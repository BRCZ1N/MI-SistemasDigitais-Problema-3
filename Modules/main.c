#include "prototype.h"
int16_t axis_x;
pthread_mutex_t lock;

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

    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, execAccel, NULL);

    pthread_create(&thread2, NULL, execPong, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

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

    ball->ballPositionX = SCREEN_X / 2;
    ball->ballPositionY = SCREEN_Y - 120;
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

int execPong()
{

    gpuMapping();
    int16_t mg_per_lsb = 4;
    int stateGame, buttons, velX = 1;
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

        /*Loop da patida do jogo*/
        while (checkEndGame(&scoreJ1, &scoreJ2))
        { // Enquanto o jogador não perdeu e não ganhou o jogo

            // Leitura dos botões e mudança de estado
            buttons = buttonRead();
            changeState(&stateGame, &buttons);

            /* switch para mudar a tela de acordo com o estado */
            if (stateGame == 0)
            { // Tela inicial

                /*Desenhar elementos do jogo*/
                resetData(&ball, &barJ1, &barJ2, &scoreJ1, &scoreJ2);
                screenMenu();
            }
            else if (stateGame == 1)
            { // Tela do jogo

                videoClear();
                /*Desenhar elementos do jogo*/
                // gameField(blocksList, score, stateGame);
                //generateBall(ball.ballPositionX, ball.ballPositionY, COLOR_WHITE);
                videoBox(barJ1.coordX - BAR_SIZE, barJ1.coordY - BAR_WIDHT, barJ1.coordX + BAR_SIZE, barJ1.coordY + BAR_WIDHT, COLOR_WHITE, 1);
                videoBox(barJ2.coordX - BAR_SIZE, barJ2.coordY - BAR_WIDHT, barJ2.coordX + BAR_SIZE, barJ2.coordY + BAR_WIDHT, COLOR_WHITE, 1);

                /*Movimentação dos elementos do jogo*/
                pthread_mutex_lock(&lock);
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
                moveBar(&barJ1, velX);
                moveBar(&barJ2, velX);
                //moveBall(&ball, &barJ1);
                //moveBall(&ball, &barJ2);
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
