#include "prototype.h"

#define CHAR_SIZE 5

unsigned short char_bitmaps[37][5][4] = {
    // A
    {
        {0,1,1,1},
        {1,0,0,1},
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1}
    },
    // B
    {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,0},
        {1,0,0,1},
        {1,1,1,1}
    },
    // C
    {
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {0,1,1,1}
    },
    // D
    {
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,1,1,1}
    },
    // E
    {
        {1,1,1,1},
        {1,0,0,0},
        {1,1,1,0},
        {1,0,0,0},
        {1,1,1,1}
    },
    // F
    {
        {1,1,1,1},
        {1,0,0,0},
        {1,1,1,0},
        {1,0,0,0},
        {1,0,0,0}
    },
    // G
    {
        {0,1,1,1},
        {1,0,0,0},
        {1,0,1,1},
        {1,0,0,1},
        {0,1,1,1}
    },
    // H
    {
        {1,0,0,1},
        {1,0,0,1},
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1}
    },
    // I
    {
        {1,1,1,1},
        {0,1,1,0},
        {0,1,1,0},
        {0,1,1,0},
        {1,1,1,1}
    },
    // J
    {
        {0,1,1,1},
        {0,0,0,1},
        {0,0,0,1},
        {1,0,0,1},
        {0,1,1,1}
    },
    // K
    {
        {1,0,0,1},
        {1,0,1,0},
        {1,1,0,0},
        {1,0,1,0},
        {1,0,0,1}
    },
    // L
    {
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {1,1,1,1}
    },
    // M
    {
        {1,0,0,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1}
    },
    // N
    {
        {1,0,0,1},
        {1,1,0,1},
        {1,0,1,1},
        {1,0,0,1},
        {1,0,0,1}
    },
    // O
    {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    },
    // P
    {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    },
    // Q
    {
        {0,1,1,1},
        {1,0,0,1},
        {1,0,1,1},
        {1,0,0,1},
        {0,1,1,1}
    },
    // R
    {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,1},
        {1,0,1,0},
        {1,0,0,1}
    },
    // S
    {
        {0,1,1,1},
        {1,0,0,0},
        {0,1,1,0},
        {0,0,0,1},
        {1,1,1,0}
    },
    // T
    {
        {1,1,1,1},
        {0,1,1,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,1,1,0}
    },
    // U
    {
        {1,0,0,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    },
    // V
    {
        {1,0,0,1},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0},
        {0,0,1,0}
    },
    // W
    {
        {1,0,0,1},
        {1,0,0,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,0,0,1}
    },
    // X
    {
        {1,0,0,1},
        {0,1,1,0},
        {0,0,1,0},
        {0,1,1,0},
        {1,0,0,1}
    },
    // Y
    {
        {1,0,0,1},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,1,0}
    },
    // Z
    {
        {1,1,1,1},
        {0,0,1,0},
        {0,1,0,0},
        {1,0,0,0},
        {1,1,1,1}
    },
    // 0
    {
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,1,1,1}
    },
    // 1
    {
        {0,0,1,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,1,1,1}
    },
    // 2
    {
        {1,1,1,1},
        {0,0,0,1},
        {1,1,1,1},
        {1,0,0,0},
        {1,1,1,1}
    },
    // 3
    {
        {1,1,1,1},
        {0,0,0,1},
        {0,1,1,1},
        {0,0,0,1},
        {1,1,1,1}
    },
    // 4
    {
        {1,0,0,1},
        {1,0,0,1},
        {1,1,1,1},
        {0,0,0,1},
        {0,0,0,1}
    },
    // 5
    {
        {1,1,1,1},
        {1,0,0,0},
        {1,1,1,1},
        {0,0,0,1},
        {1,1,1,1}
    },
    // 6
    {
        {1,1,1,1},
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,1}
    },
    // 7
    {
        {1,1,1,1},
        {0,0,0,1},
        {0,0,0,1},
        {0,0,0,1},
        {0,0,0,1}
    },
    // 8
    {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,1}
    },
    // 9
    {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,1},
        {0,0,0,1},
        {1,1,1,1}
    }
};


/**
 * Função para imprimir um caractere na tela.
 *
 * Esta função desenha um caractere específico em uma posição dada (coordX, coordY)
 * com uma cor especificada. O caractere é convertido em um índice para acessar
 * seu bitmap correspondente, e a cor é convertida de hexadecimal para RGB.
 * A função então itera sobre o bitmap do caractere e desenha os blocos de fundo
 * nas posições apropriadas se o bit correspondente estiver definido.
 *
 * @param coordX A coordenada X onde o caractere será desenhado.
 * @param coordY A coordenada Y onde o caractere será desenhado.
 * @param caracter O caractere a ser desenhado.
 * @param color A cor do caractere em formato hexadecimal.
 */
void printChar(int coordX, int coordY, char caracter, short color) {
    int index = charToIndex(caracter);
    Color cor = convertHexToRgb(color);
    for (int i = 0; i < CHAR_SIZE; i++) {
        for (int j = 0; j < 4; j++) {
            if (char_bitmaps[index][i][j] == 1)
                setBackgroundBlock(coordX+i, coordY+j, cor.red, cor.green, cor.blue);
        }
    }
}

/**
 * Função para mapear o caractere para o índice na matriz.
 *
 * Esta função converte um caractere alfabético ou numérico em um índice
 * correspondente para uso em uma matriz. Caracteres de 'A' a 'Z' são mapeados
 * para índices de 0 a 25, caracteres de 'a' a 'z' são mapeados para os mesmos
 * índices de 'A' a 'Z', e caracteres de '0' a '9' são mapeados para índices
 * de 26 a 35. Qualquer outro caractere é considerado inválido e mapeado para
 * o índice 36.
 *
 * @param c O caractere a ser mapeado.
 * @return O índice correspondente ao caractere na matriz, ou 36 se o caractere
 *         for inválido.
 */
int charToIndex(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }else if (c >= 'a' && c <= 'z') {
        return c - 'A';
    } else if (c >= '0' && c <= '9') {
        return c - '0' + 26;
    } else {
        return 36;  // Caractere inválido
    }
}


/**
 * @brief Gera uma caixa colorida na tela.
 * 
 * Esta função desenha uma caixa colorida na tela, preenchendo uma área quadrada
 * com a cor especificada.
 * 
 * @param column A coluna inicial onde a caixa será desenhada.
 * @param line A linha inicial onde a caixa será desenhada.
 * @param R O valor da componente vermelha da cor.
 * @param G O valor da componente verde da cor.
 * @param B O valor da componente azul da cor.
 * @param length O comprimento do lado da caixa.
 */
void generateBox(int column, int line, int R, int G, int B, int length)
{

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            setBackgroundBlock((column * length) + j, (line * length) + i, R, G, B);
        }
    }
}

/**
 * @brief Converte uma cor hexadecimal para RGB.
 * 
 * Esta função converte um valor de cor hexadecimal para uma estrutura RGB.
 * 
 * @param colorHex O valor da cor em hexadecimal.
 * @return A estrutura de cor RGB correspondente.
 */
Color convertHexToRgb(int colorHex)
{
    Color colorRgb;

    colorRgb.red = (((colorHex >> 16) & 0xFF)*7)/255;
    colorRgb.green= (((colorHex >> 8) & 0xFF)*7)/255;
    colorRgb.blue = ((colorHex & 0xFF)*7)/255;
    
    return colorRgb;
}

/**
 * @brief Limpa a tela de vídeo.
 * 
 * Esta função percorre a tela de vídeo e limpa cada bloco, definindo-o como vazio.
 */
void videoClear(){

    for (int i = 0; i < SCREEN_X; i++)
    {
        for (int j = 0; j < SCREEN_Y; j++)
        {
            while (1)
            {
                if (((isFull() / sizeof(int))) == 0)
                {
                    generateBox(j, i, 0, 0, 0, 1);
                    break;
                }
            }
        }
    }

}

/**
 * @brief Limpa a tela de vídeo.
 * 
 * Esta função percorre a tela de vídeo e limpa cada bloco, definindo-o como vazio.
 */
void videoClearSet(int x_inicial, int y_inicial, int x_final, int y_final){

    for (int i = x_inicial; i < x_final; i++)
    {
        for (int j = y_inicial; j < y_final; j++)
        {
            while (1)
            {
                if (((isFull() / sizeof(int))) == 0)
                {
                    generateBox(j, i, 0, 0, 0, 1);
                    break;
                }
            }
        }
    }

}

void videoBox(int initial_x, int initial_y, int end_x, int end_y, int color, int blockLength)
{
    Color colorRGB = convertHexToRgb(color);
    for (int i = initial_x; i < end_x; i++)
    {
        for (int j = initial_y; j < end_y; j++)
        {
            while (1)
            {
                if (((isFull() / sizeof(int))) == 0)
                {
                    generateBox(j, i, colorRGB.red, colorRGB.green, colorRGB.blue, blockLength);
                    break;
                }
            }
        }
    }
}

