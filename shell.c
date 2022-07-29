#include "shell.h"


int main(void)
{
	char *buffer;
	size_t len;
	int child_p, status;
	char *array[10];
	char *bin = "/bin/";

	buffer = malloc(sizeof(char) * 1000);
	bin = malloc(sizeof(char) * 1000);

	while(1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		buffer[strlen(buffer) - 1] = '\0';
		array[0] = strcat(bin, buffer);
		printf("%s", array[0]);
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
		wait(&status);
	}
	return (EXIT_SUCCESS);
}
