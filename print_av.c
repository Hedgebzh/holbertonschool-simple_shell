#include <stdio.h>
#include <unistd.h>

int print_av(int ac, char **av)
{
int count;
int *ab = av;

void foo(int ac);
for (count = 0; ab[count] <= ac; count++)
{
	printf("argument value %d is %d", count, ab[count]);
}
return (0);
}
