#include "shell.h"

int main(void)
{
	char *cmd;
	size_t len;
	int child_p, status;
	char *array [2];

	cmd = malloc(sizeof(char) * 1024);

	while(1)
	{
	getline(&buffer, &len, stdin);
	cmd[strlen(cmd) - 1] = '\0';
	array[0] = cmd;
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
	free(cmd);
	}
	return (EXIT_SUCCESS);
}

