#include <stdio.h>
#include <signal.h>

void gestionar_interrupcion(int senyal) {
    printf("Recibida la señal numero %d\n", senyal);
}

int main(int argc, char const * argv[]) {
    signal(SIGINT, gestionar_interrupcion);
}