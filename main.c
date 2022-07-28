#include "main.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main(void)
{
char *str;
int pid, slip;
size_t len;
char *array[2];

str = malloc(sizeof(char) * 1024);
	while (1)
		{
			printf("$ ");
			getline (&str, &len, stdin);
			str[strlen(str) - 1] = '\0';
			array[0] = str;
			array[1] = NULL;

			pid_t pid = fork();

			if (fgets(str, sizeof(str), stdin) == NULL) break;

			if (str[strlen(str)-1] == '\n')
				{
					str[strlen(str)-1] = '\0';
				}

			if (strcmp(array[0], "exit") == 0) break;



			if (pid == -1)
			{
				char* error = strerror(errno);
				printf("fork: %s\n", error)
				return(1);
			}

			if (pid == 0)
			{
			execve (array[0], array, NULL);
			wait (&slip);
			}
		}
		return(0);
}

void read_command(char cmd[], char par[])
{
	for(int i = 0; i < MAX_NUMBER_OF_PARAMS; i++)
	{
		par[i] = strsep(&cmd, " ");
		if (par[i] == NULL) break;
	}
}

int executeCmd(char par[])
{
	(void)
}
