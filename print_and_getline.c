#include "shell.h"
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>


int main(void)
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
}

