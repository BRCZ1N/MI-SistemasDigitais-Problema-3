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

    pthread_create(&thread2, NULL, execTetris, NULL);

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
void execTetris()
{

    int buttons, buttonValue, buttonValueRotate;
    int16_t mg_per_lsb = 4;

    srand(time(NULL));

    Tetromino currentTetromino;
    PartTetromino boardMatrix[LINES][COLUMNS], OldboardMatrix[LINES][COLUMNS];

    int dx = 0, dy = 1, moved = 1, score, hscore = 0, old_score;
    char text_over[4] = "over";
    char text_paused[6] = "paused";
    char text_game[4] = "game";
    gpuMapping();

    while (1)
    {
        score = 0;
        resetBoard(boardMatrix);
        initTetromino(&currentTetromino);
        int pointerStateGame = 1;
        videoClear();

        while (!checkGameOver(boardMatrix, &currentTetromino))
        {
            buttonValue = buttonRead();
            gameField(score, hscore);
            changePauseState(&pointerStateGame, &buttonValue);
            buttonValue = 15;

            if (pointerStateGame == 1)
            {
				printChar(10, 59, 'P', COLOR_BLACK);
                printChar(20, 59, 'A', COLOR_BLACK);
                printChar(30, 59, 'U', COLOR_BLACK);
                printChar(40, 59, 'S', COLOR_BLACK);
                printChar(50, 59, 'E', COLOR_BLACK);
                pthread_mutex_lock(&lock);
                if (axis_x * mg_per_lsb >= 100)
                {

                    dx = 1;
                }
                else if (axis_x * mg_per_lsb <= -100)
                {

                    dx = -1;
                }
                else
                {

                    dx = 0;
                }
                pthread_mutex_unlock(&lock);
                moveTetromino(boardMatrix, &currentTetromino, dx, dy, &moved);
                dx = 0;
                if (!moved)
                {
                    old_score = score;
                    removeFullLines(boardMatrix, &score);
                    if(old_score != score){
                        videoClear();
                    }

                    gameField(score, hscore);
                    initTetromino(&currentTetromino);
                }
               
                drawBoard(boardMatrix);
                usleep(450000);

            }
            else
            {
                gamePause();
                drawBoard(boardMatrix);
                usleep(450000);
            }

        }

        videoClear();
        gameOver();
        usleep(650000);
        if (score > hscore){
            hscore = score;
        }
    }
    closeGpuMapping();
}
