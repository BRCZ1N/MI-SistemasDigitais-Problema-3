#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <linux/input.h>
#include "prototype.h"

// Definições
#define LEFT -1
#define RIGHT 1
#define MOVE_THRESHOLD 3  // Sensibilidade mínima
#define MOVE_EVENT 2      // Eventos consecutivos necessários

// Variáveis globais
int count_to_x = 0;   // Contador para filtro de movimentação

// Função para processar a movimentação horizontal
int processHorizontalMove(int dx) {
    if (dx < -MOVE_THRESHOLD) { // Movimento para a esquerda
        count_to_x = (count_to_x > 0) ? 0 : count_to_x - 1; // Reseta se movimento contrário
        if (count_to_x <= -MOVE_EVENT) { // Sensibilidade configurada
            count_to_x = 0;
            return LEFT;
        }
    } else if (dx > MOVE_THRESHOLD) { // Movimento para a direita
        count_to_x = (count_to_x < 0) ? 0 : count_to_x + 1; // Reseta se movimento contrário
        if (count_to_x >= MOVE_EVENT) { // Sensibilidade configurada
            count_to_x = 0;
            return RIGHT;
        }
    }
    return 0; // Sem evento significativo
}

// // Função para execução contínua da leitura do mouse
// void *execMouse(void *args) {
//     const char *device = "/dev/input/mice";
//     int fd = open(device, O_RDONLY); // Abrindo o dispositivo do mouse
//     if (fd == -1) {
//         perror("Erro ao abrir o dispositivo do mouse");
//         pthread_exit(NULL);
//     }

//     while (1) {
//         unsigned char mouse_buffer[3];
//         ssize_t bytes = read(fd, mouse_buffer, sizeof(mouse_buffer));
//         if (bytes < 0) {
//             perror("Erro ao ler dados do mouse");
//             break;
//         }

//         // Processa o deslocamento horizontal (byte 1 do buffer representa o eixo X)
//         int dx = (int)((int8_t)mouse_buffer[1]); // Converte para número com sinal

//         // Filtro para reduzir ruído
//         if (abs(dx) <= MOVE_THRESHOLD) {
//             dx = 0; // Ignora movimentos insignificantes
//         }

//         pthread_mutex_lock(&lockMouse);
//         int event = processHorizontalMove(dx); // Processa o evento horizontal
//         if (event == LEFT) {
//             printf("Movimento para a ESQUERDA detectado\n");
//         } else if (event == RIGHT) {
//             printf("Movimento para a DIREITA detectado\n");
//         }

//         // Atualiza a posição horizontal do mouse
//         xMouse += dx;
//         pthread_mutex_unlock(&lockMouse);

//         // Pequeno delay para suavizar leituras
//         usleep(5000); // 5ms
//     }

//     close(fd);
//     pthread_exit(NULL);
// }
