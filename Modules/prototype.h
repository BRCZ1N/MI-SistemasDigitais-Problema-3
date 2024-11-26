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

#include "home.h"
#include "over1p.h"
#include "over2p.h"
#include "pRM.h"
#include "pRT.h"
#include "pMM.h"



int execPong();
void resetData(Ball *ball, Bar *barJ1, Bar *barJ2);
void ballRacketCollision(Ball *ball, Bar *bar, int *vert, int *hori, int *movVertical, int isTopBar);
void ballBorderCollision(Ball *ball, Bar *barJ1, Bar *barJ2, int *vert, int *hori, int *scoreJ1, int *scoreJ2);
void *execMouse(void *args);
void screenMenu();
void gameField(int stateGame);
void generateChar(int coordX, int coordY, char caracter, short cor); 
void changeGameState(int *pointer_state, int *pointer_buttons, int buttons); 
int buttonRead(); 
void generateBall (int coordX, int coordY, short cor);
void screenGameOver();
void changePauseState(int *pointerStateGame, int *pointerButtons); 
void generateBox(int column, int line, int R, int G, int B, int length);
Color convertHexToRgb(int colorHex);
void videoClear();
void videoClearSet(int x_inicial, int y_inicial, int x_final, int y_final);
int normalizeVelocity(int velX);
void spriteTest();
void videoBox(int initial_x, int initial_y, int end_x, int end_y, int color, int blockLength);
int charToIndex(char c);
void printChar(int coordX, int coordY, char caracter, short color);
void screenGamePause();

void Fover(int player);
void Fpause(int estado);
void Fhome();
void renderScreen(int mode, int width, int height, const uint32_t *bitmap);
void pauseMenu(int *pointerStateGame, int *pointerButtons, int buttons);



// Variáveis globais para o acelerômetro
extern int16_t axis_x; // Eixo X do acelerômetro.
extern pthread_mutex_t lock; // Mutex para controle de acesso a recursos compartilhados.
extern int16_t xMouse;
//Funções da biblioteca
extern int closeGpuMapping();
extern int gpuMapping();
extern void setSprite(int registrador, int x, int y, int offset, int activation_bit);
extern void setBackgroundColor(int R, int G, int B);
extern void setBackgroundBlock(int column, int line, int R, int G, int B);
extern void setPolygon(int address, int opcode, int color, int form, int mult, int ref_point_x, int ref_point_y);
extern void setSpriteMemory(unsigned long spriteSlot, unsigned long cor,unsigned long x, unsigned long y);
extern int isFull();

#endif
