#include "exe_concept.h"


int print_getline(void)
{
	char *buffer;
	size_t len;

	buffer = malloc(sizeof(char) * 1024);

	while(1)
	{
	printf("$ ");
	getline(&buffer, &len, stdin);
	printf("%s", buffer);
	}
	return (0);
}

