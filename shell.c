#include "shell.h"

int main(void)
{
	char *cmd, *ptr, *argv[256];
	size_t len;
	int child_p, status, i;

	while(1)
	{
	getline(&cmd, &len, stdin);
	cmd[strlen(cmd) - 1] = '\0';

	ptr = strtok(cmd, " ");
	i = 0;
	while(ptr != NULL)
	{
		argv[i] = ptr;
		i++;
		ptr = strtok(NULL, " ");
	}

	if(!strcmp("&", argv[i-1]))
	{
	argv[i-1] = NULL;
	argv[i] = "&";
	}else
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
	wait(&status);
	}
	return (0);
}

