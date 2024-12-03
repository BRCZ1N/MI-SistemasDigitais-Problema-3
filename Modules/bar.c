#include "prototype.h"

void moveBar(Bar *bar, int accelX) {
    // Limites definidos pelos videoBox
    int xStart = 11; // Limite esquerdo
    int xEnd = 70;   // Limite direito

    // Verifica se o movimento está dentro dos limites especificados
    if ((xStart < (bar->coordX - BAR_SIZE) + accelX) && ((bar->coordX + BAR_SIZE) + accelX < xEnd)) {
        bar->coordX += accelX; // Movimento permitido
    } else {
        // Caso a barra ultrapasse os limites laterais
        if ((xStart + xEnd) / 2 >= bar->coordX) {
            bar->coordX = xStart + BAR_SIZE; // Ajusta para o limite esquerdo
        } else {
            bar->coordX = xEnd - BAR_SIZE; // Ajusta para o limite direito
        }
    }
}


// int bar0[20][20] = {{0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// } 
// int bar1[20][20] = {{0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// } 
// int bar2[20][20] = {{0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// } 
// int bar3[20][20] = {{0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0x0, 0x0, 0x0, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// } 
// int bar4[20][20] = {{0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, }, 
// } 
// int bar5[20][20] = {{0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff777777, 0xff777777, 0xff777777, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// {0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0x0, 0x0, 0x0, }, 
// } 