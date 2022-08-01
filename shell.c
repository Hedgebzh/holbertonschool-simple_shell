#include "shell.h"

int main(void)
{
	char *cmd, *ptr, *argv[256];
	size_t len = 1000;
	int child_p, i, status, childStatus;

	while(1)
	{
	getline(&cmd, &len, stdin);
	cmd[strlen(cmd) - 1] = '\0';

	if(strcmp("", cmd) == 0) /* si rien dans le terminal on continue, sinon exit on break */
	continue;
	if(strcmp("exit", cmd) == 0)
	break;

	ptr = strtok(cmd, " "); /* divise la commande pour les arguments */
	i = 0;
	while(ptr != NULL)
	{
		argv[i] = ptr;
		i++;
		ptr = strtok(NULL, " ");
	}

	if(strcmp("&", argv[i-1]) == 0) /* check pourquoi strcmp */
	{
	argv[i-1] = NULL;
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
	else if (child_p == 0)
	{
		execvp(argv[0], argv);
		perror("Error");
	}
	else
	{
		waitpid(child_p, &childStatus, 0);
		return (1);
	}
	wait(&status);
	}

	exit(0);
}

