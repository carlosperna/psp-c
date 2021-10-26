#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
    fork();
    fork();
    printf("[%d] Hola\n", getpid());
    sleep(1);
    return 0;
}
