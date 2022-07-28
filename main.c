#include "main.h"

int main(void)
{
char *str;
int kirikou, slip;
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
kirikou = fork();

if (fgets(str, sizeof(str), stdin) == NULL) break;

if (str[strlen(str)-1] == '\n')
{
	str[strlen(str)-1] = '\0';
}

if (kirikou == -1)
{
	perror("Boloss corrige-moi ça et vite fait!");
	return(1);
}
if (kirikou == 0)
	execve (array[0], array, NULL);
			wait (&slip);
		}
		return(EXIT_SUCCESS);
}
