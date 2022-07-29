#include "shell.h"


int main(void)
{
	char *cmd;
	size_t len;
	int child_p;
	char *array[10];

	cmd = malloc(sizeof(char) * 1000);

	while(1)
	{
		printf("$ ");

		getline(&cmd, &len, stdin);
		if ((strlen(cmd) > 0) && (cmd[strlen(cmd) - 1 == '\n']))
		{
			cmd[strlen(cmd) - 1] = '\0';
		} /* supprimer le retour à la ligne dans le stdin */

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
		wait(NULL);
	}
	free(cmd);

	return (EXIT_SUCCESS);
}
