#include "shell.h"

int main(void)
{
	char *cmd, *ptr, *argv[1000];
	size_t len;
	int child_p, i;

	while (1)
	{
		if (getline(&cmd, &len, stdin) == '\0')
		break; /* recuperation de l'input */

		cmd[strlen(cmd) - 1] = '\0'; /* suppresion du retour à la ligne */

		if (strcmp("", cmd) == 0)
		continue;

		if (strcmp("exit", cmd) == 0)
		break;

		ptr = strtok(cmd, " "); /* divise la commande pour les arguments */
		i = 0;
		while (ptr != NULL)
		{
			argv[i] = ptr;
			i++;
			ptr = strtok(NULL, " ");
		}

		child_p = fork();

		if (child_p == -1)
		{
			perror("Error");
			return (1);
		}
		if (child_p == 0)
		{
			execvp(argv[0], argv);
		}
		wait(NULL);
	}
	free(ptr);

	exit(EXIT_SUCCESS);
}
