#include "prototype.h"

/**
 * Função para exibir a bola na tela
 * @param coordX Coordenada do centro da bola no eixo x
 * @param coordY Coordenada do centro da bola no eixo y
 * @param cor Cor da bola
 * @return void
*/
void generateBall (int coordX, int coordY, short cor) {

    videoBox(coordX, coordY, coordX+1, coordY+1, cor, 1);
	// videoBox(coordX - 2, coordY - 2, coordX + 2, coordY - 1, cor, 1);
	// videoBox(coordX - 4, coordY - 1, coordX + 4, coordY + 1, cor, 1);
	// videoBox(coordX - 3, coordY + 2, coordX + 3, coordY + 3, cor, 1);
	// videoBox(coordX - 1, coordY + 4, coordX + 1, coordY + 4, cor, 1);
}

/**
 * Função para posicionar os elementos no jogo ao iniciar uma partida
 * @param ball Bola
 * @param bar Barra
 * @param score Pontuação
 * @return void
 */
void resetData(Ball *ball, Bar *barJ1, Bar *barJ2)
{

    ball->ballPositionX = 40; // 320 x 240 para sprite centralizar // 40 x 30 para centralizar block
    ball->ballPositionY = 30;
    ball->ballSpeedX = 1;
    ball->ballSpeedY = 1;
    ball->collision = -1;

    barJ1->coordX = SCREEN_X / 2;
    barJ1->coordY = SCREEN_Y - 5;
    barJ2->coordX = SCREEN_X / 2;
    barJ2->coordY = SCREEN_Y - 55;

}


void ballRacketCollision(Ball *ball, Bar *bar, int *vert, int *hori, int *movVertical, int isTopBar)
{
    // Define uma faixa de Y para o range de colisão na raquete
    int racketStartY = bar->coordY - 3;  // Começo da faixa Y da raquete (ajustado para permitir um range)
    int racketEndY = bar->coordY + 2;    // Fim da faixa Y da raquete (ajustado para permitir um range)

    // Define uma faixa de X para o range de colisão na raquete
    int racketStartX = bar->coordX - 4;  // Começo da faixa X da raquete (ajustado para permitir um range)
    int racketEndX = bar->coordX + RACKET_WIDTH + 4; // Fim da faixa X da raquete (ajustado para permitir um range)


    
    //videoBox(racketStartX, racketStartY, bar->coordX + (RACKET_WIDTH / 3), racketEndY, COLOR_BLUE,1);
    //videoBox(racketStartX, racketStartY, bar->coordX + (RACKET_WIDTH / 3), racketEndY, COLOR_GREEN,1);
    //videoBox(bar->coordX + (RACKET_WIDTH / 3) * 2, racketStartY, racketEndX, racketEndY, COLOR_CYAN, 1);
    // Verificando colisão com a parte inicial da raquete (esquerda)
    if (ball->ballPositionX >= racketStartX && ball->ballPositionX < bar->coordX + (RACKET_WIDTH / 3))
    {

        // Verifica se a bola está dentro do intervalo Y da raquete
        if (ball->ballPositionY >= racketStartY && ball->ballPositionY <= racketEndY)
        {
            printf("COLISAO NO INICIO\n");
            *vert = (isTopBar) ? 1 : -1;  // Inverte direção vertical dependendo da barra
            *hori = (isTopBar) ? -1 : 1;  // Direção horizontal invertida
            *movVertical = 0;  // Não há movimento vertical após o impacto
        }
    }

    // Verificando colisão com a parte central da raquete
    else if (ball->ballPositionX >= bar->coordX + (RACKET_WIDTH / 3) && ball->ballPositionX < bar->coordX + (RACKET_WIDTH / 3) * 2)
    {
        
        // Verifica se a bola está dentro do intervalo Y da raquete
        if (ball->ballPositionY >= racketStartY && ball->ballPositionY <= racketEndY)
        {
            printf("COLISAO NO CENTRO\n");
            *vert = (isTopBar) ? 1 : -1;  // Direção vertical invertida dependendo da barra
            *movVertical = 1;  // Bola mantém movimento vertical (subindo ou descendo)
            *hori = 0;  // Bola não altera direção horizontal
        }
    }

    // Verificando colisão com a parte final da raquete (direita)
    else if (ball->ballPositionX >= bar->coordX + (RACKET_WIDTH / 3) * 2 && ball->ballPositionX <= racketEndX)
    {
      
        // Verifica se a bola está dentro do intervalo Y da raquete
        if (ball->ballPositionY >= racketStartY && ball->ballPositionY <= racketEndY)
        {
            printf("COLISAO NO FINAL\n");
            *vert = (isTopBar) ? 1 : -1;  // Direção vertical invertida dependendo da barra
            *hori = (isTopBar) ? 1 : -1;  // Direção horizontal invertida dependendo da barra
            *movVertical = 0;  // Não há movimento vertical após o impacto
        }
    }
}



void ballBorderCollision(Ball *ball, Bar *barJ1, Bar *barJ2, int *vert, int *hori, int *lifeJ1, int *lifeJ2)
{
    
    // Colisão com o lado direito
    if (ball->ballPositionX + 1 == RIGHT_MARGIN + BORDER_WEIGHT)
        *hori = -1;

    // Colisão com o topo
    if (ball->ballPositionY + 1 == TOP_MARGIN + BORDER_WEIGHT)
    {

        *lifeJ1 -= 1;
        resetData(ball,barJ1,barJ2);

    }

    // Colisão com o lado esquerdo
    if (ball->ballPositionX - 1 == LEFT_MARGIN + BORDER_WEIGHT)
        *hori = 1;

    // Colisão com o chão = perde uma vida
    if (ball->ballPositionY- 1 == BOTTOM_MARGIN + BORDER_WEIGHT){

        *lifeJ2 -= 1;
        resetData(ball,barJ1,barJ2);
    
    }

}
