#include "ss_shell.h"

int main(void)
{
	char *buffer;
	size_t len;
	int child_p, status;
	char *array [2];

	buffer = malloc(sizeof(char) * 1024);

	while(1)
	{
	printf("$ ");
	getline(&buffer, &len, stdin);
	buffer[strlen(buffer) - 1] = '\0';
	array[0] = buffer;
	array[1] = NULL;
	child_p = fork();
	if (child_p == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_p == 0)
	{
		execve(array[0], array, NULL);
	}
	wait(&status);
	}
	return (EXIT_SUCCESS);
}

