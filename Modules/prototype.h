#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

/*
 * prototype.h
 *
 * Este arquivo contém as declarações de funções e variáveis globais utilizadas no 
 * jogo Tetris. Inclui bibliotecas necessárias para manipulação de vídeo, 
 * controle de threads, e funções de suporte ao jogo.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "constants.h"
#include "structs.h"
#include "acelerometro.h"
#include <unistd.h>


// // Lógica do layout
// void phrase           (int coordX, int coordY, char *list, int lenList, short cor);
// void write_score      (int coordX, int coordY, int score);
// void screen_defeat    (int score);
// void screen_victory   ();
// void create_menu      ();
// void game_field       (Block blocksList[], int score, int state_game);

// // Escrita na tela
// void title            (int coordX, int coordY);
// void alphanumeric     (int coordX, int coordY, char caracter, short cor);
 
// // Bola
// int  detect_collision (int x_rect, int y_rect, int length_rect, int width_rect,  
//                       int x_boll, int y_boll, int ray, int *x_point, int *y_point);
// int  getTypeCollision (Ball *ball, Block blocksList[], Bar *bar);
// int  getMoveBall      (Ball *ball, Block blocksList[], Bar *bar);
// void moveBall         (Ball *ball, Block blocksList[], Bar *bar);

// // Barra
// void moveBar          (Bar *bar, int accelX);

// // Botões
// void change_state     (int *pointer_state, int *pointer_buttons);


void gameField(int score, int hscore); 
void generateChar(int coordX, int coordY, char caracter, short cor); 
void changeGameState(int *pointer_state, int *pointer_buttons); 
//int verifyCollision(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino); 
//void drawBoard(PartTetromino boardMatrix[LINES][COLUMNS]); 
//void drawBoardTerminal(PartTetromino boardMatrix[LINES][COLUMNS]); 
int buttonRead(); 
void screenGameOver();
void changePauseState(int *pointerStateGame, int *pointerButtons); 
extern int closeGpuMapping();
extern int gpuMapping();
extern void setSprite(int registrador, int x, int y, int offset, int activation_bit);
extern void setBackgroundColor(int R, int G, int B);
extern void setBackgroundBlock(int column, int line, int R, int G, int B);
extern void setPolygon(int address, int opcode, int color, int form, int mult, int ref_point_x, int ref_point_y);
extern int isFull();
void generateBox(int column, int line, int R, int G, int B, int length);
Color convertHexToRgb(int colorHex);
void videoClear();
void videoBox(int initial_x, int initial_y, int end_x, int end_y, int color, int blockLength);
int charToIndex(char c);
void printChar(int coordX, int coordY, char caracter, short color);
void screenGamePause();

// Variáveis globais para o acelerômetro
extern int16_t axis_x; // Eixo X do acelerômetro.
extern pthread_mutex_t lock; // Mutex para controle de acesso a recursos compartilhados.

#endif
