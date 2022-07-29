#include "exe_concept.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int my_pid(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
