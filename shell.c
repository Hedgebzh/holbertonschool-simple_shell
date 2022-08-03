#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

int main(void)
{
	char *cmd, *token;
	size_t len = 0;
	ssize_t input;
	int i = 0;
	pid_t child_pid;

	char **argv = malloc(sizeof(char *) * 1000);

	while ((input = getline(&cmd, &len, stdin)) != -1)
	{

		cmd[strlen(cmd) - 1] = '\0';

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


