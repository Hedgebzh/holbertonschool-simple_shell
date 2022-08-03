#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	char *cmd, *token;
	size_t len = 0;
	int i;
	pid_t child_pid;

	char **argv = malloc(sizeof(char *) * 1000);

	while (1)
	{
		if (getline(&cmd, &len, stdin) == '\0')
		break;

		cmd[strlen(cmd) - 1] = '\0';

		token = strtok(cmd, " ");

		i = 0;
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
		else if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
		wait(NULL);
		}
	}
	free(argv);

	exit(EXIT_SUCCESS);
}
