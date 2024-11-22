#include "prototype.h"
int16_t axis_x;
int16_t xMouse;
pthread_mutex_t lock;
pthread_mutex_t lockMouse;

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

    pthread_t thread1, thread2, thread3;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, execAccel, NULL);

    pthread_create(&thread2, NULL, execPong, NULL);

    pthread_create(&thread3, NULL, execMouse, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    pthread_mutex_destroy(&lock);

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
//     int dx = 0, dy = 1, moved = 1, scoreJ1, scoreJ2, hscore = 0, old_score, buttons;
//     gpuMapping();

//     while (1)
//     {
//         int stateGame = 1;

//         videoClear();

//         while (!checkEndGame(&scoreJ1, &scoreJ2))
//         {
//             buttons = buttonRead();
//             // gameField(score, hscore);
//             changeState(&stateGame, &buttons);

//             // if (stateGame == 1)
//             // {
//             //     pthread_mutex_lock(&lock);
//             //     if (axis_x * mg_per_lsb >= 100)
//             //     {

//             //         dx = 1;
//             //     }
//             //     else if (axis_x * mg_per_lsb <= -100)
//             //     {

//             //         dx = -1;
//             //     }
//             //     else
//             //     {

//             //         dx = 0;
//             //     }
//             //     pthread_mutex_unlock(&lock);
//             // }
//             // else
//             // {
//             //     screenGamePause();
//             // }
//         }

//         videoClear();
//         screenGameOver();
//         usleep(650000);
//         if (score > hscore)
//         {
//             hscore = score;
//         }
//     }
//     closeGpuMapping();
// }

int checkEndGame(int *scoreJ1, int *scoreJ2)
{
    if (*scoreJ1 < 3 || *scoreJ2 < 3)
        return 1;
    return 0;
}

/**
 * Função para posicionar os elementos no jogo ao iniciar uma partida
 * @param ball Bola
 * @param bar Barra
 * @param score Pontuação
 * @return void
 */
void resetData(Ball *ball, Bar *barJ1, Bar *barJ2, int *scoreJ1, int *scoreJ2)
{

    ball->ballPositionX = 320; // 320 x 240 para sprite centralizar // 40 x 30 para centralizar block
    ball->ballPositionY = 240;
    ball->ballSpeedX = 1;
    ball->ballSpeedY = 1;
    ball->collision = -1;

    barJ1->coordX = SCREEN_X / 2;
    barJ1->coordY = SCREEN_Y - 5;
    barJ2->coordX = SCREEN_X / 2;
    barJ2->coordY = SCREEN_Y - 55;

    *scoreJ1 = 0;
    *scoreJ2 = 0;
}

int normalizeVelocity(int velX)
{
    while (velX >= 10 || velX <= -10)
        velX /= 10;
    return velX;
}

int execPong()
{

    gpuMapping();
    int16_t mg_per_lsb = 4;
    int stateGame, buttons, velX = 1, velXMouse = 1, buttonValue = 15;
    buttons = buttonRead();

    /* Inicializar os elementos do jogo */
    int scoreJ1, scoreJ2;
    Ball ball;
    Bar barJ1;
    Bar barJ2;

    /*Loop principal do jogo*/
    while (1)
    {

        /*Posiciona elementos e iniciar a maquina de estado da tela*/
        stateGame = 1;

        resetData(&ball, &barJ1, &barJ2, &scoreJ1, &scoreJ2);

        buttons = buttonRead();
        buttonValue = 15; //1111 Binário todos os botões sem pressionar com lógica trocada

        /*Loop da patida do jogo*/
        while (checkEndGame(&scoreJ1, &scoreJ2))
        { // Enquanto o jogador não perdeu e não ganhou o jogo

            if(buttons != 15){

                buttonValue = buttons;

            }

            changeState(&stateGame, &buttonValue, &buttons);

            /* switch para mudar a tela de acordo com o estado */
            if (stateGame == 0)
            { // Tela inicial

                /*Desenhar elementos do jogo*/
                resetData(&ball, &barJ1, &barJ2, &scoreJ1, &scoreJ2);
                screenMenu();
            }
            else if (stateGame == 1)
            { // Tela do jogo

                /*Testes da outra branch
                videoClear();
                // gameField(blocksList, score, stateGame);
                //spriteTest();
                //Desconhecido,Sprite a ser selecionado,Bit ativacao IMPAR/PAR,CoordX,CoordY
                //barJ1.coordX = 300;
                //barJ1.coordY = 225;
                //videoBox(79, 15, 81, 209, COLOR_CYAN, 1, 1); // esquerda
                //videoBox(77, 207, 230, 209, COLOR_CYAN, 1, 1); // baixo
                //videoBox(230, 15, 235, 209, COLOR_CYAN, 1, 1); // direita
                //videoBox(77, 15, 230, 17, COLOR_CYAN, 1, 1); // cima
                */
            
                videoClear();
                //generateBall(ball.ballPositionX, ball.ballPositionY, COLOR_WHITE);
                while(1){ if(isFull() == 0) { setSprite(1, 9, 1, ball.ballPositionX, ball.ballPositionY); break; } }




                /*Desenhar elementos do jogo*/
                // gameField(blocksList, score, stateGame);
                // generateBall(ball.ballPositionX, ball.ballPositionY, COLOR_WHITE);
                // Esquerda
                videoBox(10, 1, 11, 58, COLOR_CYAN, BLOCK_SIZE);
                // Baixo
                videoBox(10, 58, 71, 59, COLOR_CYAN, BLOCK_SIZE);
                // Direita
                videoBox(70, 1, 71, 58, COLOR_CYAN, BLOCK_SIZE);
                // Cima
                videoBox(10, 1, 70, 2, COLOR_CYAN, BLOCK_SIZE);

                videoBox(barJ1.coordX - BAR_SIZE, barJ1.coordY - BAR_WIDHT, barJ1.coordX + BAR_SIZE, barJ1.coordY + BAR_WIDHT, COLOR_WHITE, BLOCK_SIZE);
                videoBox(barJ2.coordX - BAR_SIZE, barJ2.coordY - BAR_WIDHT, barJ2.coordX + BAR_SIZE, barJ2.coordY + BAR_WIDHT, COLOR_WHITE, BLOCK_SIZE);
                /*Movimentação dos elementos do jogo*/
                pthread_mutex_lock(&lock);
                velX = axis_x * mg_per_lsb;
                velX = normalizeVelocity(velX);
                pthread_mutex_unlock(&lock);
                pthread_mutex_lock(&lockMouse);
                velXMouse = xMouse;
                velXMouse = normalizeVelocity(velXMouse);
                pthread_mutex_unlock(&lockMouse);
                printf("VELOCIDADE X ACCEL:%d\n", velX);
                printf("VELOCIDADE X MOUSE:%d\n", velXMouse);
                usleep(16666);
                moveBar(&barJ1, velX);
                moveBar(&barJ2, velXMouse);
                moveBall(&ball, &barJ1);
                moveBall(&ball, &barJ2);

                usleep(450000);
            }
            else if (stateGame == 2)
            { // Estado de pausa

                /*Desenhar elementos do jogo*/
                // gameField(score, stateGame);
            }
            else if (stateGame == 3)
            { // Tela de pause/exit

                /*Desenhar elementos do jogo*/
                // gameField(scoreJ1, scoreJ2, stateGame);
                // bola9x9(ball.ballPositionX, ball.ballPositionY, 0xFC18);
            }
        }
        /*Finalização do jogo*/

        // if (checkLose(&ball) == 0)
        // { // Se o jogador perdeu
        //     do
        //     {
        //         buttons = buttonRead(); // Aguarda o jogador apertar o botão 1 para voltar ao menu
        //         // screenscreenGameOver(score);

        //     } while (buttons != 1);
        // }
        // else
        // { // Se o jogador ganhou
        //     screen_victory();
        // }
    }

    closeGpuMapping();
    return 0;
}
