#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include "prototype.h"

unsigned char mouse_buffer[3];
pthread_mutex_t lock; 

void *execMouse(void *args)
{
    const char *device = "/dev/input/mice";
    int fd = open(device, O_RDONLY); // Abrindo o dispositivo do mouse
    if (fd == -1)
    {
        perror("Erro ao abrir o dispositivo do mouse");
        pthread_exit(NULL);
    }

    while (1)
    {
        unsigned char temp_buffer[3]; // Buffer temporário para leitura
        ssize_t bytes = read(fd, temp_buffer, sizeof(temp_buffer));
        if (bytes < 0)
        {
            break;
        }

        pthread_mutex_lock(&lock);
        for (int i = 0; i < 3; i++)
        {
            mouse_buffer[i] = temp_buffer[i];
        }
        int dx = (int)mouse_buffer[1];
        xMouse += dx;
        pthread_mutex_unlock(&lock);
        printf("posicao do mouse:%d",xMouse );
        
    }

    close(fd); 
    pthread_exit(NULL);
}
