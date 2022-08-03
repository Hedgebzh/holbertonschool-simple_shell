#include "shell.h"

int main(void)
{
	char *cmd, *token;
	size_t len = 0;
	int i = 0;
	pid_t child_pid;

	char **argv = malloc(sizeof(char *) * 1000);

	while (1)
	{
		if (getline(&cmd, &len, stdin) == '\0')
		break;

		cmd[strlen(cmd) - 1] = '\0';

		if (strcmp("", cmd) == 0)
		continue;

		if (strcmp("exit", cmd) == 0)
		break;

		token = strtok(cmd, " ");

		while (token != NULL)
		{
			argv[i] = token;
			i++;
			token = strtok (NULL, " ");
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error");
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		wait(NULL);
	}
	free(argv);

	exit(EXIT_SUCCESS);
}


