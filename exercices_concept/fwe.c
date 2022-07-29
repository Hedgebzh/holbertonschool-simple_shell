#include "exe_concept.h"


int fwe(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int status, count;
	pid_t cpid;

for (count = 0; count <= 4 && cpid != 0; count++)
{
	printf("before fork\n");
	cpid = fork();
	if (cpid == -1)
	{
		printf("error");
		return (1);
	}
	wait(&status);
}

	if (cpid == 0) /* child */
	{
		printf("this is the children process and his is is %d\n", getpid());
		printf("my parent id is %d\n", getppid());
	}
	else /* parent */
	{
		printf("i am the parent");
	}

    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    return (0);
}
