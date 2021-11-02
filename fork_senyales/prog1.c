#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

//Declaramos el manejador de la señal
void manejadorHijo(int num_senyal);
void manejadorPadre(int num_senyal);

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        perror("Error en el fork");
        exit(1);
    }
    if (pid == 0)
    { //Proceso hijo
        signal(SIGUSR1, manejadorHijo);
        printf("[Proceso: %d]: Manejador activado.\n",getpid());
        pause();
    }
    else //Proceso padre
    {
        signal(SIGUSR1, manejadorPadre);
        printf("[Proceso: %d]: Manejador activado.\n",getpid());
        pause();
        int estado;
        pid_t pid_hijo=wait(NULL);
    }
    return 0;
}

//Implementamos los manejadores
void manejadorHijo(int num_senyal)
{
    printf("Soy el manejador de la señal del hijo.\n");
}

void manejadorPadre(int num_senyal)
{
    printf("Soy el manejador de la señal del padre.\n");
}