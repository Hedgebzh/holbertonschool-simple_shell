#include "shell.h"

int main(int ac, char **av)
{
int count;

(void) ac;
for (count = 1; av[count] != NULL; count++)
{
	printf("argument value %d is %s", count, av[count]);
}
return (0);
}
