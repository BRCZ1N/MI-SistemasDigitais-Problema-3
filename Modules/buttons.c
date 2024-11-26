#include "prototype.h"



/**
 * Alteração do estado atual do jogo.
 * 
 * Utiliza o estado atual do jogo e as alterações dos sinais dos botões para indicar qual será o próximo estado.
 * 
 * @param pointerStateGame  Ponteiro indicando o endereço que armazena o estado atual do jogo.
 * @param pointerButtons    Ponteiro indicando o endereço que armazena o sinais lidos dos botões.
 * @return void
 */
void changeState(int *pointerStateGame, int *pointerButtons, int buttons) {

    /*
        state = 0; tela inicial
        state = 1; jogo rodando
        state = 2; em pausa com opção de play
        state = 3; em pausa com opção de exit
    */

    switch (*pointerStateGame) {

    case 0:

    
        if (*pointerButtons == 14 && buttons == 15) {

            
            *pointerStateGame = 1;
        }

        break;

    case 1:

        if (*pointerButtons == 13 && buttons == 15) {

            *pointerStateGame = 2;
        }

        break;

    case 2:

        // if (*pointerButtons == 11 && buttons == 15) {

        //     *pointerStateGame = 3;
        // }
        // else if (*pointerButtons == 11 && buttons == 15) {

        //     *pointerStateGame = 1;
        // }

        break;

    case 3:

        if (*pointerButtons == 7 && buttons == 15) {

            *pointerStateGame = 2;
        }

        else if (*pointerButtons == 7 && buttons == 15) {
	
            *pointerStateGame = 0;
        }

        break;
    }
}



void pauseMenu(int *pointerStateGame, int *pointerButtons, int buttons) {
    int currentOption = 0; // 0 = Resume, 1 = Main Menu, 2 = Restart

    while (*pointerStateGame == 2) { // Loop enquanto o jogo está em pausa
        // Chama Fpause com a opção atual
        Fpause(currentOption + 1);

        // Lê o estado atual dos botões (simulação aqui)
        buttons = buttonRead();

        // Verifica movimento para cima (botão 1 pressionado)
        if ((*pointerButtons == 14 && buttons == 13) || 
            (*pointerButtons == 15 && buttons == 14)) {
            currentOption = (currentOption - 1 + 3) % 3; // Cicla para cima
        }
        // Verifica movimento para baixo (botão 2 pressionado)
        else if ((*pointerButtons == 13 && buttons == 11) || 
                 (*pointerButtons == 15 && buttons == 13)) {
            currentOption = (currentOption + 1) % 3; // Cicla para baixo
        }
        // Verifica seleção (botão 3 pressionado)
        else if ((*pointerButtons == 11 && buttons == 7)) {
            switch (currentOption) {
            case 0: // Resume
                *pointerStateGame = 1; // Sai do menu e volta ao jogo
                break;
            case 1: // Main Menu
                *pointerStateGame = 0; // Vai para o menu principal
                // Adicione lógica para resetar tudo
                break;
            case 2: // Restart
                *pointerStateGame = 1; // Reinicia o jogo
                // Adicione lógica para reinicializar o estado do jogo
                // e reiniciar a partida aqui pode fazer bruno?
                break;
            }
        }

        // Atualiza os botões
        *pointerButtons = buttons;
    }
}
