#include "prototype.h"


void changeSprite(int slot, const uint32_t *bitmap) {
    int width = 20, height = 20;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index =  width * height + i * width + j;
            switch (bitmap[index]) {
                case 0xff000000: // Preto 
                    setSpriteMemory(slot, 0x000000000, i, j);
                    printf("preto");
                    break;
                case 0xffffffff: // Branco
                    setSpriteMemory(slot, 0x111111111, i, j);
                    printf("branco");
                    break;
                case 0xff0000ff: // Vermelho
                    setSpriteMemory(slot, 0x111000000, i, j);
                    printf("vermelho");

                    break;
                case 0xffff0000: // Azul
                    setSpriteMemory(slot, 0x111000000, i, j);
                    printf("azul");

                    break;
                case 0xffffff00: // Ciano
                    setSpriteMemory(slot, 0x000111111, i, j);
                    printf("ciano");

                    break;
                case 0xffff00ff: // Magenta
                    setSpriteMemory(slot, 0x111000111, i, j);
                    printf("magenta");

                    break;
                case 0xff00ffff: // Amarelo
                    setSpriteMemory(slot, 0x111111000, i, j);
                    break;
                case 0xff00ff00: // Verde
                    setSpriteMemory(slot, 0x000000111, i, j);
                    break;
                case 0xff4681bf:
                    setSpriteMemory(slot, 0x100011001, i, j);
                    break;
                case 0xff2c8bf0:
                    setSpriteMemory(slot, 0x111011000, i, j);
                    break;
                case 0xff6284a9:
                    setSpriteMemory(slot, 0x011011001, i, j);
                    break;
                case 0xff007700:
                    setSpriteMemory(slot, 0x000011000, i, j);
                    break;
                case 0xffb6b6b7:
                    setSpriteMemory(slot, 0x100100100, i, j);
                    break;
                case 0xff5a5a5a:
                    setSpriteMemory(slot, 0x001001001, i, j);
                    break;
                case 0xff0791d3:
                    setSpriteMemory(slot, 0x101011000, i, j);
                    break;
                case 0xff70e7ea:
                    setSpriteMemory(slot, 0x110110011, i, j);
                    break;
                case 0xff276cd4:
                    setSpriteMemory(slot, 0x101001000, i, j);
                    break;
                case 0xff1e4887:
                    setSpriteMemory(slot, 0x011001000, i, j);
                    break;
                case 0xff15b027:
                    setSpriteMemory(slot, 0x000011000, i, j);
                    break;
                default:
                    break;
            }
        }
    }
}
