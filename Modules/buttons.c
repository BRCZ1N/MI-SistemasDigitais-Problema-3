#include "prototype.h"

/**
 * Altera o estado de pausa do jogo com base na entrada dos botões.
 *
 * Esta função verifica o estado atual do jogo e o valor dos botões pressionados. 
 * Se o jogo estiver em execução (estado 1) e o botão de pausa for pressionado 
 * (valor 2), o estado do jogo muda para pausado (estado 2). Se o jogo estiver 
 * pausado e o mesmo botão for pressionado, o estado volta para em execução. 
 * A função utiliza ponteiros para modificar os estados diretamente.
 *
 * @param pointerStateGame Ponteiro para o estado atual do jogo, que pode 
 *                         ser 1 (em execução) ou 2 (pausado).
 * @param pointerButtons Ponteiro que representa o valor dos botões 
 *                       pressionados, onde o valor 2 indica o botão de pausa.
 */

void changePauseState(int *pointerStateGame, int *pointerButtons)
{

    switch (*pointerStateGame)
    {
    case 1:
        if (*pointerButtons == 14)
        {
            *pointerStateGame = 2;
        }
        break;

    case 2:
        if (*pointerButtons == 13)
        {
            *pointerStateGame = 1;
        }
        break;
    }
}


// /**
//  * Alteração do estado atual do jogo.
//  * 
//  * Utiliza o estado atual do jogo e as alterações dos sinais dos botões para indicar qual será o próximo estado.
//  * 
//  * @param pointer_state   Ponteiro indicando o endereço que armazena o estado atual do jogo.
//  * @param pointerButtons Ponteiro indicando o endereço que armazena o sinais lidos dos botões.
//  * @return void
//  */
// void changeState(int *pointerStateGame, int *pointerButtons) {

//     /*
//         state = 0; tela inicial
//         state = 1; jogo rodando
//         state = 2; em pausa com opção de play
//         state = 3; em pausa com opção de exit
//     */

//     switch (*pointerStateGame) {

//     case 0:

//         if (*pointerButtons == 1) {

//             *pointerStateGame = 1;
//         }

//         break;

//     case 1:

//         if (*pointerButtons == 2) {

//             *pointerStateGame = 2;
//         }

//         break;

//     case 2:

//         if (*pointerButtons == 1) {

//             *pointerStateGame = 3;
//         }
//         else if (*pointerButtons == 2) {

//             *pointerStateGame = 1;
//         }

//         break;

//     case 3:

//         if (*pointerButtons == 1) {

//             *pointerStateGame = 2;
//         }

//         else if (*pointerButtons == 2) {
	
//             *pointerStateGame = 0;
//         }

//         break;
//     }
// }
