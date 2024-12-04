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
    // Ajusta a faixa Y dependendo se é a raquete superior ou inferior
    int racketStartY, racketEndY;

    if (isTopBar) {
        // Raquete superior: a colisão ocorre acima, portanto, o intervalo Y é ajustado de forma "normal"
        racketStartY = bar->coordY - 6;  // Começo da faixa Y da raquete
        racketEndY = bar->coordY + 4;    // Fim da faixa Y da raquete
    } else {
        // Raquete inferior: a colisão ocorre abaixo, então o intervalo Y é invertido
        racketStartY = bar->coordY - 4;  // Começo da faixa Y da raquete (ajustado para raquete inferior)
        racketEndY = bar->coordY + 6;    // Fim da faixa Y da raquete
    }

    // Define a faixa X para o range de colisão na raquete
    int racketStartX = bar->coordX - RACKET_WIDTH - 4;  // Começo da faixa X da raquete
    int racketEndX = bar->coordX + RACKET_WIDTH + 4; // Fim da faixa X da raquete

    // Verifica se a bola está dentro da área da raquete (considerando X e Y)
    if (ball->ballPositionX >= racketStartX && ball->ballPositionX <= racketEndX &&
        ball->ballPositionY >= racketStartY && ball->ballPositionY <= racketEndY) {

        // Determina a direção vertical dependendo da raquete (superior ou inferior)
        *vert = (isTopBar) ? 1 : -1;

        // Divide a raquete em 3 partes, levando em consideração a largura total da raquete
        int partWidth = RACKET_WIDTH / 3;  // Largura de cada parte da raquete

        // Colisão com a parte esquerda da raquete
        if (ball->ballPositionX < racketStartX + partWidth) {
            printf("COLISAO NA LATERAL ESQUERDA\n");
            *hori = (isTopBar) ? -1 : 1;  // Inverte a direção horizontal
            *movVertical = 0;  // Não há movimento vertical após o impacto
        }
        // Colisão com a parte central da raquete
        else if (ball->ballPositionX >= racketStartX + partWidth && ball->ballPositionX < racketStartX + 2 * partWidth) {
            printf("COLISAO NA PARTE CENTRAL\n");
            *hori = 0;  // Não há mudança na direção horizontal
            *movVertical = 1;  // Mantém movimento vertical (subindo ou descendo)
        }
        // Colisão com a parte direita da raquete
        else if (ball->ballPositionX >= racketStartX + 2 * partWidth && ball->ballPositionX <= racketEndX) {
            printf("COLISAO NA LATERAL DIREITA\n");
            *hori = (isTopBar) ? 1 : -1;  // Inverte a direção horizontal
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
