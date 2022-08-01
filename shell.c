#include "shell.h"

{
	char *cmd, *ptr, *argv[256];
	size_t len;
	int child_p, i;

	while(1)
	{
	getline(&cmd, &len, stdin);
	cmd[strlen(cmd) - 1] = '\0';

	if(strcmp("", cmd) == 0)
	continue;
	if(strcmp("exit", cmd) == 0)
	break;

	ptr = strtok(cmd, " "); /* divise la commande pour les arguments */
	i = 0;
	while(ptr != NULL)
	{
	@@ -20,11 +25,12 @@ int main(void)
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
	@@ -39,7 +45,7 @@ int main(void)
	{
		execvp(argv[0], argv);
	}
	wait(NULL);
	}
	return (0);
}
