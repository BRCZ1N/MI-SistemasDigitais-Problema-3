#include "prototype.h"
pthread_mutex_t lockStates;
int stateGame, buttons, buttonValue = 15, currentOption = 0;
int lifeJ1, lifeJ2;
Ball ball;
Bar barJ1;
Bar barJ2;
int flagGameOver = -1, flagReset = 0;

/*
 * Função principal que inicializa o ambiente do jogo Tetris.
 * Cria duas threads:
 * - A primeira thread executa a função execAccel, que lida com a função principal de execução do acelerômetro.
 * - A segunda thread executa a função execTetris, que contém a lógica principal do jogo Tetris.
 * Um mutex é inicializado para garantir que o acesso a recursos compartilhados, como a variável axis_x, seja feito de maneira segura.
 * As threads são unidas ao final da execução, garantindo que o programa aguarde a conclusão de ambas antes de encerrar.
 */
int main()
{
    pthread_t thread1, thread2, thread3, thread4, thread5;

    pthread_mutex_init(&lock, NULL);
    pthread_mutex_init(&lockMouse, NULL);
    pthread_mutex_init(&lockStates, NULL);

    pthread_create(&thread1, NULL, execAccel, NULL);
    pthread_create(&thread2, NULL, execPong, NULL);
    pthread_create(&thread3, NULL, execMouse, NULL);
    pthread_create(&thread4, NULL, changeStateExec, NULL);
    pthread_create(&thread5, NULL, lifeAnimation, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&lockMouse);
    pthread_mutex_destroy(&lockStates);

    return 0;
}
/**
 * Função principal do jogo Tetris que controla a lógica do jogo.
 *
 * Esta função é executada em uma thread separada e gerencia o fluxo
 * do jogo Tetris, incluindo a inicialização do tabuleiro, controle
 * dos tetrominos, verificação de condições de jogo, e exibição
 * do estado do jogo na tela. O loop principal continua até que o
 * jogo esteja terminado, e ele permite alternar entre pausar e
 * retomar o jogo.
 *
 * @note A função utiliza variáveis globais para o controle do estado
 *       do jogo e acesso a recursos de vídeo.
 */
// void execTetris()
// {

//     int16_t mg_per_lsb = 4;
//
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
    clearSpritePos(6);
    clearSpritePos(7);
    changeSprite(6, gaivota0);
    changeSprite(7, pombo_data);
    // changeSprite(8, gaivota);

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
                videoClearSet(11, 2, 70, 58);
                //Limpa a primeira barra
                videoClearSet(11, 2, 70, 5);
                //Limpa a segunda barra
                videoClearSet(11, 55, 70, 58);


                // setarGaivotas(lifeJ1);
                // setarGaivotas(lifeJ2);
                //  generateBall(ball.ballPositionX, ball.ballPositionY, COLOR_WHITE);

                // Definir um array com as informações dos sprites (sprite, offset, x, y)
                // int sprites[][4] = {
                //     {12, 12, 10, 290}, // Sprite 1
                //     {6, 6, 20, 200}, // Sprite 2
                //     // {7, 6, 26, 350}, // Sprite 3
                //     // {8, 6, 18, 140}, // Sprite 4
                //     // {9, 6, 26, 170}, // Sprite 5
                //     // {10, 6, 10, 110}, // Sprite 6

                //     // {12, 12, 10, 130}, // Sprite 7
                //     // {13, 13, 10, 150}, // Sprite 8
                //     // {14, 14, 10, 170}, // Sprite 9
                // }

                // // Verificar se a função isFull() retorna 0 e chamar setSprite() para cada sprite
                // if (isFull() == 0)
                // {
                //     // for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
                //     // {
                //     //     setSprite(sprites[i][0], sprites[i][1], 1, sprites[i][2], sprites[i][3]);
                //     // }
                //     setSprite(12, 12, 1, 320, 240);
                //     setSprite(6, 6, 1, 300, 240);
                //     // setSprite(8, 8, 1, 340, 240);

                //     break; // Interromper o loop após definir todos os sprites
                // }

                // while (lifeJ1 != 3 || lifeJ2 != 3)
                // {
                //     if (lifeJ1 == 1)
                //     {
                //         while (1)
                //         {
                //             if (isFull() == 0)
                //             {
                //                 setSprite(5, 5, 0, 9, 110);

                //                 break;
                //             }
                //         }
                //     }
                //     break;
                // }

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
                videoBox(10, 1, 11, 58, COLOR_CYAN, BLOCK_SIZE);
                // Baixo
                // videoBox(10, 58, 71, 59, COLOR_CYAN, BLOCK_SIZE);
                // Direita
                videoBox(70, 1, 71, 58, COLOR_CYAN, BLOCK_SIZE);
                // Cima
                // videoBox(10, 1, 70, 2, COLOR_CYAN, BLOCK_SIZE);

                /*Movimentação dos elementos do jogo*/
                pthread_mutex_lock(&lock);
                // velX = axis_x * mg_per_lsb;
                // velX = normalizeValue(velX,10);
                if (axis_x * mg_per_lsb >= 100)
                {

                    velX = 1;
                }
                else if (axis_x * mg_per_lsb <= -100)
                {

                    velX = -1;
                }
                else
                {

                    velX = 0;
                }
                pthread_mutex_unlock(&lock);
                pthread_mutex_lock(&lockMouse);
                velXMouse = xMouse;
                velXMouse = normalizeValue(velXMouse, 1);
                pthread_mutex_unlock(&lockMouse);
                int previousVelAccel = velX;
                int previousVelMouse = velXMouse;
                moveBar(&barJ1, velX);
                moveBar(&barJ2, velXMouse);
                ballRacketCollision(&ball, &barJ1, &cima, &direita, &movVertical, 0);
                ballRacketCollision(&ball, &barJ2, &cima, &direita, &movVertical, 1);
                ballBorderCollision(&ball, &barJ1, &barJ2, &cima, &direita, &lifeJ1, &lifeJ2);

                //Limpa a primeira barra
                //videoClearSet(11, 2, 70, 5);
                videoBox(barJ1.coordX - BAR_SIZE, barJ1.coordY - BAR_WIDHT, barJ1.coordX + BAR_SIZE, barJ1.coordY + BAR_WIDHT, COLOR_WHITE, BLOCK_SIZE);
                // while(1){ if(isFull() == 0) { setSprite(2, 13, 1, ((barJ1.coordX - BAR_SIZE)*8),(barJ1.coordY - BAR_WIDHT)*8); break; } }
                //Limpa a segunda barra
                //videoClearSet(11, 55, 70, 58);
                videoBox(barJ2.coordX - BAR_SIZE, barJ2.coordY - BAR_WIDHT, barJ2.coordX + BAR_SIZE, barJ2.coordY + BAR_WIDHT, COLOR_WHITE, BLOCK_SIZE);
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
            }
            else if (stateGame == 4)
            {

                clearSprite();
                videoClear();
                lifeJ1 = lifeJ2 = 3;
                resetData(&ball, &barJ1, &barJ2);
                flagGameOver = -1;
                Fover(flagGameOver);
            }
        }
    }

    return 0;
}

// Função para 2 frames de animação
void setDoubleFrameAnimation(int maxIterations, int firstReg, int coordX, int coordY, int offSet, int regFrame)
{

    for (int i = 0; i < maxIterations; i++)
    {

        while (1)
        {
            if (isFull() == 0)
            {
                setSprite(firstReg + i, regFrame, 1, coordX + (offSet), coordY + (offSet));
                usleep(50000);
                setSprite(firstReg + i, regFrame + 1, 1, coordX + (offSet), coordY + (offSet));
                usleep(50000);
            }
            break;
        }
    }

    for (int i = 0; i < 3 - maxIterations; i++)
    {
        clearSpriteReg(firstReg + i);
    }
}

void lifeAnimation()
{
    while (1)
    {

        if (stateGame == 1)
        {

            setDoubleFrameAnimation(lifeJ1, 6, 320, 240, 5, 6);
            setDoubleFrameAnimation(lifeJ2, 8, 350, 270, 5, 6);
        }
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

            stateGame = 1;

            break;

        case 4:

            if (flagGameOver)
            {

                stateGame = 0;
            }
            break;
        }
    }
}
