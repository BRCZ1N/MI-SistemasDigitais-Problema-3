#include "prototype.h"
int stateGame, buttons, buttonValue = 15, currentOption = 0;
int lifeJ1, lifeJ2;
Ball ball;
Bar barJ1;
Bar barJ2;
int flagGameOver = -1, flagReset = 0;

// struct input_event ev;
// int fd_mouse;
// int xsoma = 0, ysoma = 0;
// unsigned int click_reset = 0;

// int start = 1;
// int end;
// int restart;
// int stop;
// int x_avg = 0;
// int y_avg = 0;
// int smoothing_factor = 4; 

/*
 * Função principal que inicializa o ambiente do jogo Tetris.
 * Cria duas threads:
 * - A primeira thread executa a função execAccel, que lida com a função principal de execução do acelerômetro.
 * - A segunda thread executa a função execTetris, que contém a lógica principal do jogo Tetris.
 * Um mutex é inicializado para garantir que o acesso a recursos compartilhados, como a variável axis_x, seja feito de maneira segura.
 * As threads são unidas ao final da execução, garantindo que o programa aguarde a conclusão de ambas antes de encerrar.
 */
int main(){
    pthread_t thread1, thread2, thread3, thread4;

    pthread_mutex_init(&lock, NULL);
    pthread_mutex_init(&lockMouse, NULL);

    pthread_create(&thread1, NULL, execAccel, NULL);
    pthread_create(&thread2, NULL, execPong, NULL);
    pthread_create(&thread3, NULL, execMouse, NULL);
    pthread_create(&thread4, NULL, changeStateExec, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&lockMouse);

    return 0;
}

int checkEndGame(int lifeJ1, int lifeJ2)
{
    if (lifeJ1 == 0)
    {

        return 1;
    }
    else if (lifeJ2 == 0)
    {

        return 0;
    }
    else
    {

        return -1;
    }
}

int normalizeValue(int value, int scale_factor)
{
    const int thresholds[] = {400, 200, 100, 50, 25};
    const int normalized[] = {8, 6, 4, 2, 1};

    // Escala o valor para ajustar a magnitude
    value = value / scale_factor;

    for (int i = 0; i < 5; i++)
    {
        if (value >= thresholds[i])
        {
            return normalized[i];
        }
        else if (value <= -thresholds[i])
        {
            return -normalized[i];
        }
    }
}

// Mover para perto do video clear
void clearSprite()
{
    for (int i = 0; i < 32; i++)
    {

        setSprite(i, 0, 0, 0, 0);
    }
}

void clearSpriteReg(int reg)
{

    setSprite(reg, 0, 0, 0, 0);
}

void clearSpritePos(int slot)
{

    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 20; j++)
        {

            setSpriteMemory(slot, 0b000000000, j, i);
        }
    }
}

int execPong()
{
    gpuMapping();
    clearSpritePos(2);
    clearSpritePos(3);
    changeSprite(2, gaivota0);
    changeSprite(3, pombo_data);
    changeSprite(15, barj1_data[0]);
    changeSprite(16, barj1_data[1]);
    changeSprite(17, barj1_data[2]);

    changeSprite(12, barj2_data[0]);
    changeSprite(13, barj2_data[1]);
    changeSprite(14, barj2_data[2]);



    int16_t mg_per_lsb = 4;
    int velX = 1, velXMouse = 1, cima = 1, direita = 1, movVertical = 1, vert = 1, hori = 1;
    // buttons = buttonRead();

    /* Inicializar os elementos do jogo */

    /*Loop principal do jogo*/
    while (1)
    {
        /*Posiciona elementos e iniciar a maquina de estado da tela*/
        stateGame = 0;
        lifeJ1 = 3;
        lifeJ2 = 3;
        resetData(&ball, &barJ1, &barJ2);

        /*Loop da patida do jogo*/
        while (1)
        { // Enquanto o jogador não perdeu e não ganhou o jogo

            /* switch para mudar a tela de acordo com o estado */
            if (stateGame == 0)
            { // Tela inicial
                videoClear();
                clearSprite();
                Fhome();
                resetData(&ball, &barJ1, &barJ2);
            }
            else if (stateGame == 1)
            { // Tela do jogo

                flagGameOver = -1;
                flagReset = 0;

                while (1)
                {
                    if (isFull() == 0)
                    {
                        setSprite(11, 9, 1, (ball.ballPositionX * 8) - 4, (ball.ballPositionY * 8) - 4);
                        break;
                    }
                }

                // generateBall(ball.ballPositionX, ball.ballPositionY, COLOR_WHITE);
                // Esquerda
                videoBox(10, 1, 11, 58, COLOR_YELLOW, BLOCK_SIZE);
                // Baixo
                // videoBox(10, 58, 71, 59, COLOR_CYAN, BLOCK_SIZE);
                // Direita
                videoBox(70, 1, 71, 58, COLOR_YELLOW, BLOCK_SIZE);
                //Fcenario();
                // Cima
                // videoBox(10, 1, 70, 2, COLOR_CYAN, BLOCK_SIZE);

                /*Movimentação dos elementos do jogo*/
                pthread_mutex_lock(&lock);
                if (axis_x * mg_per_lsb >= 150)
                {

                    velX += 1;
                }
                else if (axis_x * mg_per_lsb <= -150)
                {

                    velX -= 1;
                }
                else
                {

                    velX = 0;
                }
                pthread_mutex_unlock(&lock);
                moveBar(&barJ1, velX);
                moveBar(&barJ2, xMouse);
                ballRacketCollision(&ball, &barJ1, &cima, &direita, &movVertical, 0);
                ballRacketCollision(&ball, &barJ2, &cima, &direita, &movVertical, 1);
                ballBorderCollision(&ball, &barJ1, &barJ2, &cima, &direita, &lifeJ1, &lifeJ2);
                //setPolygon(2010,10,10,2,20,20);

                // usleep_simulado(95000);
                // videoClearSet(11, 54, 70, 57);
                // videoClearSet(11, 2, 70, 6);
                // usleep_simulado(50000);
            
                while (1)
                {
                    if (isFull() == 0)
                    {
                        setSprite(15, 12, 1, (barJ1.coordX * 8) -40, (barJ1.coordY  * 8)-8);
                        setSprite(14, 12, 1, (barJ1.coordX * 8) -20, (barJ1.coordY  * 8)-8);
                        setSprite(13, 12, 1, (barJ1.coordX* 8), (barJ1.coordY  * 8)-8);
                        setSprite(12, 12, 1, (barJ1.coordX* 8) +20, (barJ1.coordY  * 8)-8);

                        setSprite(19, 15, 1, (barJ2.coordX * 8) -40, (barJ2.coordY  * 8)-8);
                        setSprite(18, 15, 1, (barJ2.coordX * 8) -20, (barJ2.coordY  * 8)-8);
                        setSprite(17, 15, 1, (barJ2.coordX* 8), (barJ2.coordY  * 8)-8);
                        setSprite(16, 15, 1, (barJ2.coordX* 8) +20, (barJ2.coordY  * 8)-8);
                        break;
                    }
                }
                //videoBox(barJ1.coordX - BAR_SIZE, barJ1.coordY - BAR_WIDHT, barJ1.coordX + BAR_SIZE, barJ1.coordY + BAR_WIDHT, COLOR_WHITE, BLOCK_SIZE);
                // while(1){ if(isFull() == 0) { setSprite(2, 13, 1, ((barJ1.coordX - BAR_SIZE)*8),(barJ1.coordY - BAR_WIDHT)*8); break; } }
                // Limpa a segunda barra
                //videoBox(barJ2.coordX - BAR_SIZE, barJ2.coordY - BAR_WIDHT, barJ2.coordX + BAR_SIZE, barJ2.coordY + BAR_WIDHT, COLOR_WHITE, BLOCK_SIZE);
                // while(1){ if(isFull() == 0) { setSprite(3, 13, 1, (barJ2.coordX - BAR_SIZE)*8, (barJ2.coordY - BAR_WIDHT)*8); break; } }

                if (cima == 1 && movVertical == 0)
                {
                    ball.ballPositionY += 1;
                }
                else if (movVertical == 0)
                {
                    ball.ballPositionY -= 1;
                }

                if (direita == 1 && movVertical == 0)
                {
                    ball.ballPositionX += 1;
                }
                else if (movVertical == 0)
                {
                    ball.ballPositionX -= 1;
                }

                if (movVertical == 1 && cima == 1)
                {
                    ball.ballPositionY += 1;
                }
                else if (movVertical == 1)
                {
                    ball.ballPositionY -= 1;
                }

                flagGameOver = checkEndGame(lifeJ1, lifeJ2);
                setDoubleFrameAnimation(lifeJ1, 1, 30, 120, 20, 2);
                setDoubleFrameAnimation(lifeJ2, 4, 30, 320, 20, 2);


            }
            else if (stateGame == 2)
            { // Estado de pausa

                videoClear();
                clearSprite();
                currentOption = 0;
                while (stateGame == 2)
                { // Loop enquanto o jogo está em pausa
                  // Chama Fpause com a opção atual

                    Fpause(currentOption + 1);

                    // Verifica movimento para cima (botão 1 pressionado)

                    if (buttonValue == 14 && buttons == 15)
                    {
                        currentOption = (currentOption - 1 + 3) % 3; // Cicla para cima
                        buttonValue = 15;
                    }
                    // Verifica movimento para baixo (botão 2 pressionado)
                    else if (buttonValue == 13 && buttons == 15)
                    {
                        currentOption = (currentOption + 1) % 3; // Cicla para baixo
                        buttonValue = 15;
                    }
                }
            }
            else if (stateGame == 3)
            {

                clearSprite();
                videoClear();
                lifeJ1 = lifeJ2 = 3;
                resetData(&ball, &barJ1, &barJ2);
                cima = 1, direita = 1, movVertical = 1, vert = 1, hori = 1;
                flagReset = 1;
            }
            else if (stateGame == 4)
            {               
                clearSprite();
                videoClear();
                lifeJ1 = lifeJ2 = 3;
                resetData(&ball, &barJ1, &barJ2);
                cima = 1, direita = 1, movVertical = 1, vert = 1, hori = 1;
                if(flagGameOver != -1){

                    Fover(flagGameOver);

                }
                flagGameOver = -1;
            }
        }
    }

    return 0;
}

// Função de animação de sprites (vidas)
void setDoubleFrameAnimation(int maxIterations, int firstReg, int coordX, int coordY, int offSet, int regFrame)
{
    int dx[] = {0, offSet, offSet * 2}; // Deslocamento horizontal
    int dy[] = {0, offSet, offSet * 2}; // Deslocamento vertical

    // Anima as vidas restantes
    for (int i = 0; i < 3; i++)
    {
        if (i < maxIterations)
        {
            // Animação para vidas ativas
            while (1)
            {
                if (isFull() == 0)
                {
                    int spriteCoordX = coordX;
                    int spriteCoordY = coordY + dy[i];
                    setSprite(firstReg + i, regFrame, 1, spriteCoordX, spriteCoordY);
                    usleep_simulado(10000);

                    setSprite(firstReg + i, regFrame + 1, 1, spriteCoordX, spriteCoordY);
                    usleep_simulado(10000);
                }
                break;
            }
        }
        else
        {
            // Limpa os sprites além do número de vidas restantes
            clearSpriteReg(firstReg + i);
        }
    }
}

void usleep_simulado(int microsegundos) {
    clock_t inicio = clock();
    // Calcula o número de "clocks" que devem passar para o intervalo de tempo desejado
    clock_t fim = inicio + microsegundos * CLOCKS_PER_SEC / 1000000;
    while (clock() < fim) {
        // Laço ocioso aguardando o tempo passar
    }
}

void changeStateExec()
{
    gpuMapping(); // Colocada aqui para fazer com que exista o mapeamento do botão !!!!!!
    while (1)
    {

        buttons = buttonRead();
        if (buttons != 15)
        {
            buttonValue = buttons;
        }

        switch (stateGame)
        {

        case 0:

            if (buttonValue == 14 && buttons == 15)
            {
                stateGame = 1;
            }

            break;

        case 1:

            if (buttonValue == 13 && buttons == 15)
            {

                stateGame = 2;
            }
            else if (flagGameOver == 1 || flagGameOver == 0)
            {

                stateGame = 4;
            }
            break;

        case 2:

            if (buttonValue == 11 && buttons == 15 && currentOption == 0)
            {
                stateGame = 0;
            }
            else if (buttonValue == 11 && buttons == 15 && currentOption == 1)
            {
                stateGame = 1;
            }
            else if (buttonValue == 11 && buttons == 15 && currentOption == 2)
            {
                stateGame = 3;
            }

            break;

        case 3:

            if(flagReset){

                stateGame = 1;

            }
            break;

        case 4:

            if (flagGameOver)
            {
                stateGame = 1;
            }
            break;
        }
    }
}
