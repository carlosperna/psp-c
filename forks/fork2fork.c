//Crear un programa que usando dos bucles cree 5 hijos definidos en una constante N_HIJOS
//Cada uno de los hijos debe imprimir su PID y esperar un segundo con sleep
//Después de crear los hijos del padre se quedara esperando en otro bucle al mismo número de
//hijos a que terminen.
//al final solo el padre imprimira un mensaje *soy PID, todos mis hijos han terminado*

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

#define N_HIJOS 5

int main(int argc, char const *argv[])
{
    int hijo;
    pid_t pid_padre = getpid();
    pid_t pid;
    pid_t pid_hijo;

    for (int i = 0; i < N_HIJOS; i++)
    {
        pid = fork;
        if (pid == 0)
        {
            break;
        }
        else
        {
            printf("[Padre: %d] [Hijo] %d\n", getpid());
            sleep(1);
        }
    }

    int estado_proceso;
    if (getpid() == pid_padre)
    {
        
    }

    printf("Soy %d, todos mis hijos han terminado\n", pid_padre);

    return 0;
}
