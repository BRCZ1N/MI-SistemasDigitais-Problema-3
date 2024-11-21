#include "prototype.h"

/**
 * Função para exibir a bola na tela
 * @param coordX Coordenada do centro da bola no eixo x
 * @param coordY Coordenada do centro da bola no eixo y
 * @param cor Cor da bola
 * @return void
*/
void generateBall (int coordX, int coordY, short cor) {

    // videoBox(coordX - 1, coordY - 4, coordX + 1, coordY - 4, cor, 1);
	// videoBox(coordX - 2, coordY - 2, coordX + 2, coordY - 1, cor, 1);
	// videoBox(coordX - 4, coordY - 1, coordX + 4, coordY + 1, cor, 1);
	// videoBox(coordX - 3, coordY + 2, coordX + 3, coordY + 3, cor, 1);
	// videoBox(coordX - 1, coordY + 4, coordX + 1, coordY + 4, cor, 1);
}

/**
 * Função para verificar coliões entre retangulos e circulos
 * @param x_rect Coordenada do canto superior esquerdo do retangulo no eixo x
 * @param y_rect Coordenada do canto superior esquerdo do retangulo no eixo y
 * @param length_rect Comprimento do retangulo
 * @param width_rect Largura do retangulo
 * @param x_boll Coordenada do centro da bola no eixo x
 * @param y_boll Coordenada do centro da bola no eixo y
 * @param ray Raio da bola
 * @param x_point Coordenada do ponto de impacto no eixo x
 * @param y_point Coordenada do ponto de impacto no eixo y
 * @return 1 se houve colisão, 0 caso contrário
*/
int detectCollision(int x_rect, int y_rect, int length_rect, int width_rect,  int x_boll, int y_boll, int ray, int *x_point, int *y_point) {

    *x_point = x_boll;  /* Ponto de impacto em x */
    *y_point = y_boll;  /* ponto de impacto em y */
    
    /* Procurar o ponto mais proximo do circulo no eixo x */
    if (x_boll < x_rect)
        (*x_point) = x_rect;
    else if (x_boll > x_rect + length_rect) 
        (*x_point) = x_rect + length_rect;

    /* Procurar o ponto mais proximo do circulo no eixo y */
    if (y_boll < y_rect)
        (*y_point) = y_rect;
    else if (y_boll > y_rect + width_rect) 
        (*y_point) = y_rect + width_rect;

    /* Calcular distancia e verificar se a bola esta dentro bloco */
    int dist_x = x_boll - *x_point;
    int dist_y = y_boll - *y_point;
    int distance = round(sqrt(dist_x * dist_x + dist_y * dist_y));

    if (distance <= ray)
        return 1;

    return 0;
}

/**
 * Função para verificar o tipo de colisão
 * @param ball Bola
 * @param bar Barra
 * @return 1 para colisões em  x e y, 2 para colisões em x, 3 para colisões em y, 4 para colisões na barra, -1 caso contrário
*/
int getTypeCollision(Ball *ball, Bar *bar) {
    int x_point, y_point;

    /* Paredes: colisão na parte superior à esquerda */
    if ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X) && 
        (ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y)))
        return 1;
        
    /* Paredes: colisão na parte superior à direita */ 
    else if ((ball->ballPositionX + COLLISION_RADIUS == (SCREEN_X - WALL_WIDHT_X) && 
            (ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y))))
        return 1;

    /* Barra e parede */
    else if ((detectCollision(bar->coordX - BAR_SIZE, bar->coordY - BAR_WIDHT, (BAR_SIZE * 2 + 1), (BAR_WIDHT * 2 + 1),
            ball->ballPositionX, ball->ballPositionY, COLLISION_RADIUS, &x_point, &y_point) == 1) &&
            ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X) ||
             (ball->ballPositionX + COLLISION_RADIUS == (SCREEN_X - WALL_WIDHT_X)))) 
    	return 1; 

    /* Paredes: colisões na esquerda e direita */  
    else if ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X) ||
            (ball->ballPositionX + COLLISION_RADIUS == (SCREEN_X - WALL_WIDHT_X))) 
        return 2;

    /* Paredes: colisão na parte superior */
    else if ((ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y)))
        return 3;

    /* Colisões na barra */
    else if ((detectCollision(bar->coordX - BAR_SIZE, bar->coordY - BAR_WIDHT, (BAR_SIZE * 2 + 1), 
            (BAR_WIDHT * 2 + 1), ball->ballPositionX, ball->ballPositionY, COLLISION_RADIUS, &x_point, &y_point)) == 1)
        return 4;

    return -1;
}

/**
 * Função para pegar a velocidade a partir da colisão com a barra
 * @param ball Bola
 * @param bar Barra
 * @return void
*/
void getVelcBall(Ball *ball, Bar *bar){
    if ((bar->coordX - ball->ballPositionX) / 6 != 0)
        ball->ballSpeedX = (bar->coordX - ball->ballPositionX) / 6;

    if ((bar->coordX - ball->ballPositionX) / 6 > 3 ){
        ball->ballSpeedY = 1;
    } else {
        ball->ballSpeedY = 2;
    }

}

/**
 * Função para pegar o próximo movimento da bola
 * @param ball Bola
 * @param bar Barra
 * @return 1 para colisões em  x e y, 2 para colisões em x, 3 para colisões em y, 4 para colisões na barra, -1 caso contrário
*/
int getMoveBall(Ball *ball, Bar *bar) {
    Ball auxBall = *ball;

    int pontosIntermediarios = 100;
    float tempo = 0.0;
    int typeCollision;

    /* Verificação de colisão nos pontos intermediários */
    for (int i = 0; i <= pontosIntermediarios; i++) {
        tempo =  i / (float)  pontosIntermediarios;

        /* Valores para verificar se há colisão */
        auxBall.ballPositionX = (int) round(ball->ballPositionX + ball->ballSpeedX * tempo);
        auxBall.ballPositionY = (int) round(ball->ballPositionY  + ball->ballSpeedY * tempo);

        /* Verifica se houve colisão */
        typeCollision = getTypeCollision(&auxBall, bar);

        if (typeCollision != -1 &&  ball->collision != typeCollision && ball->collision != 1) { 
            *ball = auxBall;
            ball->collision = typeCollision;

            return typeCollision;
        }
    }

    /* Sem colisão */
    ball->ballPositionX += ball->ballSpeedX;
    ball->ballPositionY += ball->ballSpeedY;
    ball->collision = -1;

    return -1;
}


/**
 * Função para mover a bola
 * @param ball Bola
 * @param bar Barra
 * @return void
*/
void moveBall(Ball *ball, Bar *bar) {

    /* Switch para inversão da velocidade da bola*/
    switch (getMoveBall(ball, bar)) {
    
    case (1):
        if ((ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y))){ //Superior
            if (ball->ballSpeedY < 0){
                ball->ballSpeedX = -ball->ballSpeedX;
            }
        } else{ // Inferior
            if (ball->ballSpeedY > 0){
                ball->ballSpeedX = -ball->ballSpeedX;
            }
        }

        // Encontrar o lado que houve a colisão
        if ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X)) {  // Esquerdo
            if (ball->ballSpeedX < 0){
                ball->ballSpeedX = -ball->ballSpeedX;
            }
        }else{ //Direita
            if (ball->ballSpeedX > 0){
                ball->ballSpeedX = -ball->ballSpeedX;
            }
        }
        break;

    case (2):
        ball->ballSpeedX = -ball->ballSpeedX;
        break;

    case (3):
        ball->ballSpeedY = -ball->ballSpeedY;
        break;

    case (4):
        getVelcBall(ball, bar);

        ball->ballSpeedY = -ball->ballSpeedY;
        /* Variação da velocidade no eixo x */
        if (ball->ballPositionX < bar->coordX && (bar->coordX - ball->ballPositionX) / 6 != 0 ){
            ball->ballSpeedX = -ball->ballSpeedX;
;
        } else if (ball->ballPositionX > bar->coordX && (bar->coordX - ball->ballPositionX) / 6 != 0 ){
            ball->ballSpeedX = -ball->ballSpeedX;

        } break;
    }
}
