#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void tratarSenyal(int cod_senyal);

pid_t minero;
bool final = false;


int main(int argc, char const *argv[])
{
    switch (minero = fork())
    {
    case 1:
        exit(1);
        break;

    case 0: //Minero
        signal(SIGUSR2, tratarSenyal);
        signal(SIGINT, SIG_IGN); //Ignoramos señal
        while (!final)
        {
            printf("[Minero] Esperando 5s..\n");
            sleep(5);
        }
        break;

    default: //Padre
        signal(SIGINT, tratarSenyal);
        printf("[Padre] Esperando señal..\n");
        pause();
        wait(NULL);
    }
    return 0;
}

void tratarSenyal(int cod_senyal)
{
    if (cod_senyal == SIGINT)
    {
        printf("[Proceso %d] Señal recibida %d\n", getpid, cod_senyal);
        printf("Enviando señal al hijo con PID %d en 3 segundos\n", minero);
        sleep(3);
        kill(minero, SIGUSR2);
    }
    else if (cod_senyal == SIGUSR2)
    {
        printf("[Proceso %d] Señal recibida %d\n", getpid, cod_senyal);
        final = true;
    }
}
