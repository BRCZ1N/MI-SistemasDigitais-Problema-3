#include "prototype.h"

// void changeSprite(int spriteSlot, int matriz[20][20])
void changeSprite(int spriteSlot)
{
    int matriz [20][20];
    gerar20x20(matriz);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            setSpriteMemory(spriteSlot, matriz[i][j], i, j);
        }
    }
}


int gerar20x20(int matriz[20][20]) {
    
    //256 128 64 32 16 8 4 2 1
    //0   1   1| 0  1  1|0 1 1
    // Preenchendo a matriz com o valor 6
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            matriz[i][j] = 0b011011011;
        }
    }
}

// void renderScreen(int frame, int width, int height, const uint32_t *bitmap) {
//     for (int h= 0; h< frame; h++){
//         for (int i = 0; i < height; i++) {
//             for (int j = 0; j < width; j++) {
//                 int index = h * width * height + i * width + j;
//                 switch (bitmap[index]) {
//                     case 0xff000000: // Preto virou branco
//                         setSpriteMemory(h+1, 0x000000000, i, j);
//                         break;
//                     case 0xffffffff: 
//                         setBackgroundBlock(i, j, 7, 7, 7);
//                         break;
//                     case 0xff0000ff: // Vermelho
//                         setBackgroundBlock(i, j, 7, 0, 0);
//                         break;
//                     case 0xffff0000: // Azul
//                         setBackgroundBlock(i, j, 0, 0, 7);
//                         break;
//                     case 0xffffff00: // Ciano
//                         setBackgroundBlock(i, j, 0, 7, 7);
//                         break;
//                     case 0xffff00ff: // Magenta
//                         setBackgroundBlock(i, j, 7, 0, 7);
//                         break;
//                     case 0xff00ffff: // Amarelo
//                         setBackgroundBlock(i, j, 7, 7, 0);
//                         break;
//                     case 0xff00ff00: // Verde
//                         setBackgroundBlock(i, j, 0, 7, 0);
//                         break;
//                     case 0xff4681bf:
//                         setBackgroundBlock(i, j, 4,2,1);
//                         break;
//                     case 0xff2c8bf0:
//                         setBackgroundBlock(i, j, 7,2,0);
//                         break;
//                     case 0xff6284a9:
//                         setBackgroundBlock(i, j, 3,2,1);
//                         break;
//                     case 0xff007700:
//                         setBackgroundBlock(i, j, 0,2,0);
//                         break;
//                     case 0xffb6b6b7:
//                         setBackgroundBlock(i, j, 4,4,4);
//                         break;
//                     case 0xff5a5a5a:
//                         setBackgroundBlock(i, j, 1,1,1);
//                         break;
//                     case 0xff0791d3:
//                         setBackgroundBlock(i, j, 5,2,0);
//                         break;
//                     case 0xff70e7ea:
//                         setBackgroundBlock(i, j, 6,6,2);
//                         break;
//                     case 0xff276cd4:
//                         setBackgroundBlock(i, j, 5,1,0);
//                         break;
//                     case 0xff1e4887:
//                         setBackgroundBlock(i, j, 2,1,0);
//                         break;
//                     case 0xff15b027:
//                         setBackgroundBlock(i, j, 0,3,0);
//                         break;
//                     default:
//                         break;
//                     }
//             }
//         }
//     }
// }