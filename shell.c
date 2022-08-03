#include "shell.h"

int main(void)
{
<<<<<<< HEAD
	char *cmd, *token;
	size_t len = 0;
	int i = 0;
	pid_t child_pid;

	char **argv = malloc(sizeof(char *) * 1000);
=======
	char *cmd, *ptr, *argv[1000];
	size_t len;
	pid_t child_p;
	int i;

	cmd = malloc(sizeof(char *) * 1000);
>>>>>>> 82e83a59fda9b35a8ff6daa9563118a90837af3a

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
<<<<<<< HEAD
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		wait(NULL);
	}
	free(argv);
=======
		if (child_p == 0)
		{
			execvp(argv[0], argv);
		}
		wait(NULL);
	}
	free(cmd);
>>>>>>> 82e83a59fda9b35a8ff6daa9563118a90837af3a

	exit(EXIT_SUCCESS);
}


