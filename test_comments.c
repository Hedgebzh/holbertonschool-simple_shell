#include "main.h"

#define	MAX_COMMAND_LENGTH 100
#define	MAX_NUMBER_OF_PARAMS 10

int main(void)
{
	char cmd[MAX_COMMAND_LENGTH + 1];
	char* params[MAX_NUMBER_OF_PARAMS + 1];

	/* int cmdCount = 0; */

	while(1) {
		/* Print command prompt
		char* username = getenv("USER");
		printf("%s@shell %d> ", username, ++cmdCount); */

		/* Read command from standart input, exit on Ctrl+D */
		if (fgets(cmd, sizeof(cmd), stdin) == NULL) break;

		/* Remove trailing newline character, if any */
		if(cmd[strlen(cmd)-1] == '\n') {
			cmd[strlen(cmd)-1] = '\0';
		}

		/* Split cmd into array of params */
		parseCmd(cmd, params);

		/* Exit? */
		if(strcmp(params[0], "exit") == 0) break;

		/* Execute command */
		if(executeCmd(params) == 0) break;
	}
	return(0);
}

/* Split cmd into array of parameters */
void parseCmd(char* cmd, char** params)

{

	for(int i = 0; i < MAX_NUMBER_OF_PARAMS; i++)
	{
		params[i] = strsep(&cmd, " ");
		if(params[i] == NULL) break;
	}
}

int executeCmd(char** params)
{
	/* Fork process */
	pid_t pid = fork();

	/* Error */
	if(pid == -1) {
		perror("fork: error");
		return(1);
	}

	/* Child process */
	else if (pid == 0)
	{
		/* Execute command */
		execvp(params[0], params);

		/* Error ocurred */
		perror("shell: error");
	}

	/* Parent process */
	else {
		/* Wait for child process to finish */
		int childStatus;
		waitpid(pid, &childStatus, 0);
		return(1);
	}
	return(0);
}
