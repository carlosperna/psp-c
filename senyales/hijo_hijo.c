#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void tratarSenyal(int cod_senyal);

int main(int argc, char const *argv[])
{
    pid_t pidHijo1, pidHijo2;

    if ((pidHijo1 = fork()) == -1)
    {
        perror("Error en el fork");
        exit(1);
    }
    if (pidHijo1 == 0) //Hijo1
    {
        signal(SIGUSR1, tratarSenyal);
        printf("[H1]: PID: %d\n", getpid());
        pause(); //Espero a una señal de hijo2
    }
    else //Padre
    {
        printf("[Padre]: He creado un hijo con PID %d\n", pidHijo1);
        if ((pidHijo2 = fork()) == -1)
        {
            perror("Error en el fork");
            exit(1);
        }

        if (pidHijo2 == 0) //Hijo2
        {
            printf("[H2]: PID: %d\n", getpid());
            sleep(2);
            kill(pidHijo1, SIGUSR1); //Envio una señal a hijo1
        }
        else
        {
            printf("[Padre]: He creado un hijo con PID %d\n", pidHijo2);
            printf("[Padre] Esperando a un hijo..\n");
            printf("[Padre] El hijo con PID %d finalizó\n", wait(NULL));
            printf("[Padre] Esperando a otro hijo..\n");
            printf("[Padre] El hijo con PID %d finalizó\n", wait(NULL));
        }
    }

    return 0;
}

void tratarSenyal(int cod_senyal) {
    printf("[Proceso %d]: He recibido una señal\n", getpid());
}
