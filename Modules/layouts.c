#include "prototype.h"

/**
 * Gera uma frase na tela com caracteres individuais.
 * 
 * Esta função itera sobre uma lista de caracteres e chama a função
 * `printChar` para desenhar cada caractere em uma posição especificada.
 * Os caracteres são espaçados uniformemente, e os espaços são ignorados
 * durante o processo de geração.
 *
 * @param coordX A coordenada X inicial onde a frase será desenhada.
 * @param coordY A coordenada Y onde a frase será desenhada.
 * @param list A lista de caracteres que compõem a frase.
 * @param lenList O comprimento da lista de caracteres.
 * @param color A cor a ser usada para desenhar os caracteres.
 */
void generatePhrase(int coordX, int coordY, char *list, int lenList, short color)
{

    int X;

    for (int i = 0; i < lenList; ++i)
    {

        if (list[i] != ' ')
        {

            X = coordX + i * 13;
            printChar(X, coordY, list[i], color);
        }
    }
}

/**
 * Desenha a pontuação na tela utilizando a função `printChar`.
 * 
 * Esta função converte um número inteiro representando a pontuação
 * em uma string e desenha cada dígito na tela usando a função
 * `printChar`. Os caracteres são espaçados uniformemente, cada um
 * ocupando uma posição específica baseada em coordenadas.
 *
 * @param coordX A coordenada X inicial onde a pontuação será desenhada.
 * @param coordY A coordenada Y onde a pontuação será desenhada.
 * @param score O valor da pontuação a ser exibida na tela, representado
 *              como um inteiro. Cada dígito será desenhado como um
 *              caractere colorido na tela.
 */
void drawScore(int coordX, int coordY, int score)
{

    char number_str[10];

    sprintf(number_str, "%d", score);

    int len = strlen(number_str);

    for (int i = 0; i < len; i++)
    {
        printChar(coordX + (13 * i), coordY, number_str[i], COLOR_YELLOW);
    }
}

/**
 * Desenha o campo de jogo exibindo a pontuação atual e a pontuação máxima.
 *
 * Esta função utiliza a função `generatePhrase` para exibir o texto
 * "score:" e "hscore:", seguido pelos valores atuais de pontuação
 * e a maior pontuação (high score). As pontuações são desenhadas
 * na tela em posições específicas, e bordas são desenhadas usando
 * a função `videoBox` para delimitar o campo de jogo.
 *
 * @param score A pontuação atual do jogador, que será exibida na tela.
 * @param hscore A maior pontuação registrada, que será exibida ao lado
 *               da pontuação atual.
 */
void gameField(int stateGame)
{
    

    // char text_score[6] = "score:";

    // phrase(0, 0, text_score, 6, COLOR_YELLOW);
    // write_score(78, 0, score);

    if (stateGame == 1) {

        // char text_pause[11] = "";
        // phrase(177, 0, text_pause, 11, COLOR_WHITE);
        
    }
    else if (stateGame == 2) {

        // char text_pause[11] = "pause<play>";
        // phrase(177, 0, text_pause, 11, COLOR_WHITE);
        
    }
    else if (stateGame == 3) {

        // char text_pause[11] = "pause<exit>";
        // phrase(177, 0, text_pause, 11, COLOR_WHITE);
        
    }


    // char text_score[3];
    // char text_hscore[3];

    // sprintf(text_score, "%03d", score);
    // sprintf(text_hscore, "%03d", hscore);

    // printChar(15, 0, 'S', COLOR_WHITE);
    // printChar(15, 5, 'C', COLOR_WHITE);
    // printChar(15, 10, 'O', COLOR_WHITE);
    // printChar(15, 15, 'R', COLOR_WHITE);
    // printChar(15, 20, 'E', COLOR_WHITE);
	
    // printChar(22, 5, text_score[0], COLOR_YELLOW);
    // printChar(22, 10, text_score[1], COLOR_YELLOW);
    // printChar(22, 15, text_score[2], COLOR_YELLOW);

    // printChar(30, 2, 'H', COLOR_WHITE);
    // printChar(30, 7, 'I', COLOR_WHITE);
    // printChar(30, 12, 'G', COLOR_WHITE);
    // printChar(30, 17, 'H', COLOR_WHITE);
    
    // printChar(37, 5, text_hscore[0], COLOR_YELLOW);
    // printChar(37, 10, text_hscore[1], COLOR_YELLOW);
    // printChar(37, 15, text_hscore[2], COLOR_YELLOW);

    // videoBox(110, 18, 112, 239, COLOR_BLUE, 1);  // LADO ESQUERDO
    // videoBox(110, 234, 230, 239, COLOR_BLUE, 1); // CENTRO
    // videoBox(225, 18, 230, 239, COLOR_BLUE, 1);  // Lado direito
}

/**
 * @brief Exibe a mensagem de "Game Over" na tela.
 * 
 * Esta função imprime a mensagem "Game Over" na tela, utilizando caracteres
 * amarelos em posições específicas.
 */
void screenGameOver()
{
    printChar(15, 0, 'G', COLOR_YELLOW);
    printChar(15, 5, 'A', COLOR_YELLOW);
    printChar(15, 10, 'M', COLOR_YELLOW);
    printChar(15, 15, 'E', COLOR_YELLOW);

    printChar(30, 2, 'O', COLOR_YELLOW);
    printChar(30, 7, 'V', COLOR_YELLOW);
    printChar(30, 12, 'E', COLOR_YELLOW);
    printChar(30, 17, 'R', COLOR_YELLOW);
}

/**
 * @brief Inicializa o layout do jogo.
 * 
 * Esta função configura o layout inicial do jogo, desenhando os elementos
 * necessários na tela.
 */
void screenGamePause()
{
    printChar(10, 59, 'P', COLOR_YELLOW);
    printChar(20, 59, 'A', COLOR_YELLOW);
    printChar(30, 59, 'U', COLOR_YELLOW);
    printChar(40, 59, 'S', COLOR_YELLOW);
    printChar(50, 59, 'E', COLOR_YELLOW);
}

/**
 * Exibe a tela de derrota. 
 * 
 * São exibidas as frases "game over" e o valor do score alcançado, utilizando as funções 
 * de escrita de frase e exibição do valor do score. Dependendo de quantos algorismos o 
 * score possui, a coordenada inicial de X é alterada.
 * 
 * @param score Valor do score alcançado na rodada.
 * @return void
 */
void screenDefeat (int score) {

    char defeat_message[9] = "game over";
    char score_message[6] = "score:";
    int sub_coordX = 0;

    if (score > 100) {

        sub_coordX = 10; 
    }
    else if (score > 10) {

        sub_coordX = 5;
    }

    phrase(100, 110, defeat_message, 9, COLOR_RED);
    phrase(110 - sub_coordX, 145, score_message, 6, COLOR_YELLOW);
    write_score(188 - sub_coordX,  145, score);

}

/**
 * Exibe a tela inicial do jogo
 * 
 * É exibido o título do jogo e a frase "start game", utilizando a função de exibição do título 
 * e de exibição de frase.
 * 
 * @return void
 */
void screenMenu () {

    // char start_game[] = "start game";

    // phrase(96, 160, start_game, 10, 0xDD82);

    // title(40, 30);
}




