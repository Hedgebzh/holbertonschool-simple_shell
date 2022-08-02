#include "shell.h"

int main(void)
{
	char *cmd, *ptr, *argv[256];
	size_t len;
	int child_p, i;

	cmd = malloc(sizeof (char *) * 1000);

	while (1)
	{
		getline(&cmd, &len, stdin); /* recuperation de l'input */
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

	if (!strcmp("&", argv[i - 1])) /* check pourquoi strcmp */
	{
	argv[i - 1] = NULL;
	argv[i] = "&";
	}
	else
	{
	argv[i] = NULL;
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
	free (cmd);
	return (0);
}
