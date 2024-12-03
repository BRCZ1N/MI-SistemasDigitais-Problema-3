#include "prototype.h"
void changeSprite(int slot, const uint32_t *bitmap) {
    int width = 20, height = 20;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index =  width * height + i * width + j;
            switch (bitmap[index]) {
                case 0xff000000: // Preto 
                    setSpriteMemory(slot, 0b000000000,  j, i);
                    break;
                case 0xffffffff: // Branco
                    setSpriteMemory(slot, 0b111111111,  j, i);
                    break;
                case 0xff0000ff: // Vermelho
                    setSpriteMemory(slot, 0b111000000,  j, i);
                    break;
                case 0xffff0000: // Azul
                    setSpriteMemory(slot, 0b000000111,  j, i);
                    break;
                case 0xffffff00: // Ciano
                    setSpriteMemory(slot, 0b000111111,  j, i);
                    break;
                case 0xffff00ff: // Magenta
                    setSpriteMemory(slot, 0b111000111,  j, i);
                    break;
                case 0xff00ffff: // Amarelo
                    setSpriteMemory(slot, 0b111111000,  j, i);
                    break;
                case 0xff00ff00: // Verde
                    setSpriteMemory(slot, 0b000000111,  j, i);
                    break;
                case 0xff4681bf: //cinza azulado
                    setSpriteMemory(slot, 0b100011001,  j, i);
                    break;
                case 0xff2c8bf0: //azul claro
                    setSpriteMemory(slot, 0b111011000,  j, i);
                    break;
                case 0xff6284a9:
                    setSpriteMemory(slot, 0b011011001,  j, i);
                    break;
                case 0xff007700:
                    setSpriteMemory(slot, 0b000011000,  j, i);
                    break;
                case 0xffb6b6b7:
                    setSpriteMemory(slot, 0b100100100,  j, i);
                    break;
                case 0xff5a5a5a:
                    setSpriteMemory(slot, 0b001001001,  j, i);
                    break;
                case 0xff0791d3:
                    setSpriteMemory(slot, 0b101011000,  j, i);
                    break;
                case 0xff70e7ea:
                    setSpriteMemory(slot, 0b110110011,  j, i);
                    break;
                case 0xff276cd4:
                    setSpriteMemory(slot, 0b101001000,  j, i);
                    break;
                case 0xff1e4887:
                    setSpriteMemory(slot, 0b011001000,  j, i);
                    break;
                case 0xff15b027:
                    setSpriteMemory(slot, 0b000011000,  j, i);
                case 0xff777777:
                    setSpriteMemory(slot, 0b100100100,  j, i);
                    break;
                case 0xffcccccc:
                    setSpriteMemory(slot, 0b110110110,  j, i);
                    break;
                case 0xffffaa00:
                    setSpriteMemory(slot, 0b111101000,  j, i);
                    break;
                default:
                    setSpriteMemory(slot, 0b000000000,  j, i);
                    break;
            }
        }
    }
}

