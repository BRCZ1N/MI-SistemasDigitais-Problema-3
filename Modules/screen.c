#include "prototype.h"

void renderScreen(int frame, int width, int height, const uint32_t *bitmap){
    for (int h = 0; h < frame; h++){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                int index = h * width * height + i * width + j;
                switch (bitmap[index]){

                case 0xff000000: // Preto virou branco
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xffffffff:
                    setBackgroundBlock(i, j, 7, 7, 7);
                    break;
                case 0xff0000ff: // Vermelho
                    setBackgroundBlock(i, j, 7, 0, 0);
                    break;
                case 0xffff0000: // Azul
                    setBackgroundBlock(i, j, 0, 0, 7);
                    break;
                case 0xffffff00: // Ciano
                    setBackgroundBlock(i, j, 0, 7, 7);
                    break;
                case 0xffff00ff: // Magenta
                    setBackgroundBlock(i, j, 7, 0, 7);
                    break;
                case 0xff00ffff: // Amarelo
                    setBackgroundBlock(i, j, 7, 7, 0);
                    break;
                case 0xff00ff00: // Verde
                    setBackgroundBlock(i, j, 0, 7, 0);
                    break;
                case 0xff4681bf:
                    setBackgroundBlock(i, j, 4, 2, 1);
                    break;
                case 0xff2c8bf0:
                    setBackgroundBlock(i, j, 7, 2, 0);
                    break;
                case 0xff6284a9:
                    setBackgroundBlock(i, j, 3, 2, 1);
                    break;
                case 0xff007700:
                    setBackgroundBlock(i, j, 0, 2, 0);
                    break;
                case 0xffb6b6b7:
                    setBackgroundBlock(i, j, 4, 4, 4);
                    break;
                case 0xff5a5a5a:
                    setBackgroundBlock(i, j, 1, 1, 1);
                    break;
                case 0xff0791d3:
                    setBackgroundBlock(i, j, 5, 2, 0);
                    break;
                case 0xff70e7ea:
                    setBackgroundBlock(i, j, 6, 6, 2);
                    break;
                case 0xff276cd4:
                    setBackgroundBlock(i, j, 5, 1, 0);
                    break;
                case 0xff1e4887:
                    setBackgroundBlock(i, j, 2, 1, 0);
                    break;
                case 0xff15b027:
                    setBackgroundBlock(i, j, 0, 3, 0);
                    break;
                case 0xff91daff: // areia
                    setBackgroundBlock(i, j, 7, 6, 4);
                    break;
                case 0xff6d9191: // areia molhada
                    setBackgroundBlock(i, j, 4, 4, 3);
                    break;
                case 0xff24b624: // verde escuro folha
                    setBackgroundBlock(i, j, 1, 5, 1);
                    break;
                case 0xff4991da: // tronco claro
                    setBackgroundBlock(i, j, 6, 4, 2);
                    break;
                case 0xff24496d: // tronco escuro
                    setBackgroundBlock(i, j, 3, 2, 1);
                    break;
                default:
                    break;
                }
            }
        }
        usleep(500000);
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                int index = h * width * height + i * width + j;
                switch (bitmap[index]){

                case 0xff000000: // Preto virou branco
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xffffffff:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff0000ff: // Vermelho
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xffff0000: // Azul
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xffffff00: // Ciano
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xffff00ff: // Magenta
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff00ffff: // Amarelo
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff00ff00: // Verde
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff4681bf:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff2c8bf0:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff6284a9:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff007700:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xffb6b6b7:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff5a5a5a:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff0791d3:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff70e7ea:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff276cd4:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff1e4887:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff15b027:
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff91daff: // areia
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff6d9191: // areia molhada
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff24b624: // verde escuro folha
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff4991da: // tronco claro
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                case 0xff24496d: // tronco escuro
                    setBackgroundBlock(i, j, 0, 0, 0);
                    break;
                default:
                    break;
                }
            }
        }
        usleep(5000);
    }
}

void Fhome(){
    renderScreen(HOME_FRAME, HOME_WIDTH, HOME_HEIGHT, *home);
}

void Fpause(int estado){
    switch (estado){
    case 2:
        renderScreen(PAUSE_FRAME, PAUSE_WIDTH, PAUSE_HEIGHT, *Apause);
        break;
    case 1:
        renderScreen(PAUSE_FRAME, PAUSE_WIDTH, PAUSE_HEIGHT, *Bpause);
        break;
    case 3:
        renderScreen(PAUSE_FRAME, PAUSE_WIDTH, PAUSE_HEIGHT, *Cpause);
        break;
    }
}

void Fover(int player){
    player ? renderScreen(OVER_FRAME, OVER_WIDTH, OVER_HEIGHT, *over1p) : renderScreen(OVER_FRAME, OVER_WIDTH, OVER_HEIGHT, *over2p);
}

void Fcenario(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int index = width * height + i * width + j;
            switch (cenario_reduzido_data){

            case 0xffff0000: // Azul
                setBackgroundBlock(i, j, 0, 0, 7);
                break;
            case 0xffffff00: // Ciano
                setBackgroundBlock(i, j, 0, 7, 7);
                break;
            case 0xff00ff00: // Verde
                setBackgroundBlock(i, j, 0, 7, 0);
                break;
            case 0xff91daff: // areia
                setBackgroundBlock(i, j, 7, 6, 4);
                break;
            case 0xff6d9191: // areia molhada
                setBackgroundBlock(i, j, 4, 4, 3);
                break;
            case 0xff24b624: // verde escuro folha
                setBackgroundBlock(i, j, 1, 5, 1);
                break;
            case 0xff4991da: // tronco claro
                setBackgroundBlock(i, j, 6, 4, 2);
                break;
            case 0xff24496d: // tronco escuro
                setBackgroundBlock(i, j, 3, 2, 1);
                break;
            default:
                break;
            }
        }
    }
}