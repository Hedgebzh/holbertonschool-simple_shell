#include "shell.h"

#define	MAX_COMMAND_LENGTH 1000
#define	MAX_NUMBER_OF_PARAMS 100

/**
 * main - simple shell
 * Return: void
 */

int main(void)
{
	char cmd[MAX_COMMAND_LENGTH + 1];
	char *params[MAX_NUMBER_OF_PARAMS + 1];

		while (1)
		{

			if
				(fgets(cmd, sizeof(cmd), stdin) == NULL) break;

			if
				(cmd[strlen(cmd) - 1] == '\n')
			{
				cmd[strlen(cmd) - 1] = '\0';
			}

		parseCmd(cmd, params);

		if
			(strcmp(params[0], "exit") == 0) break;

		if
			(executeCmd(params) == 0) break;
	}
	return (0);
}

/**
 * parseCmd - parse command
 *
 * @cmd: command on the prompt
 * @params: parameters of the command
 */

void parseCmd(char *cmd, char **params)

{
	int i;

	for (i = 0; i < MAX_NUMBER_OF_PARAMS; i++)
	{
		params[i] = strsep(&cmd, " ");
		if
			(params[i] == NULL) break;
	}
}

/**
 * executeCmd - execute command
 *
 * @params: parameters
 * Return: 0
 */

int executeCmd(char **params)
{
	pid_t pid = fork();

if
	(pid == -1)
{
		perror("fork: error");
		return (1);
	}

else if
	(pid == 0)
	{
		execvp(params[0], params);

		perror("Error: File or description not found.");
	}

else
	{
		int childStatus;

		waitpid(pid, &childStatus, 0);

		return (1);
	}
	return (0);
}
