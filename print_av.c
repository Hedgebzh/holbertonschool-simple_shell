#include "shell.h"

int print_av(int ac, char **av)
{
int count;

(void) ac;
for (count = 1; av[count] != NULL; count++)
{
	printf("argument value %d is %s\n", count, av[count]);
}
return (0);
}
