#include "prototype.h"


/**
 * Verifica se o jogo terminou.
 *
 * Esta função verifica se o tetromino atual colidiu com as peças já fixadas
 * no tabuleiro. Se houver uma colisão e a posição vertical do tetromino (y) 
 * for igual a 0, significa que não há mais espaço para o tetromino entrar, 
 * indicando que o jogo acabou. A função retorna 1 se o jogo terminou e 0 
 * caso contrário.
 *
 * @param boardMatrix Matriz bidimensional representando o tabuleiro do jogo, 
 *                    onde cada célula contém uma peça do tipo PartTetromino.
 * @param tetromino Ponteiro para o tetromino atual que está em movimento.
 * @return int Retorna 1 se o jogo acabou, ou 0 se ainda está em andamento.
 */

int checkGameOver(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino)
{

    if (verifyCollision(boardMatrix, tetromino) && tetromino->y == 0)
        return 1;
    return 0;
}

/**
 * Verifica colisões entre o tetromino atual e o tabuleiro de jogo.
 *
 * Esta função percorre a matriz de padrões do tetromino para verificar se 
 * há sobreposição com as peças já fixadas no tabuleiro (boardMatrix). 
 * Se qualquer parte do tetromino estiver fora dos limites do tabuleiro ou
 * se colidir com uma peça existente (indicada por `isNotEmpty`), a função 
 * retorna 1, indicando uma colisão. Se não houver colisões, retorna 0.
 *
 * @param boardMatrix Matriz bidimensional representando o tabuleiro do jogo, 
 *                    onde cada célula contém uma peça do tipo PartTetromino.
 * @param tetromino Ponteiro para o tetromino atual que está sendo avaliado.
 * @return int Retorna 1 se houver colisão, ou 0 se não houver colisão.
 */

int verifyCollision(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tetromino->pattern[tetromino->currentRotation][i][j] == 1)
            {
                int posX = tetromino->x + j;
                int posY = tetromino->y + i;

                if (posX < 0 || posX >= COLUMNS || posY < 0 || posY >= LINES || boardMatrix[posY][posX].isNotEmpty)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}
