#include "shell.h"
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>


int strtok_print(int argc, char *argv[])
{
    const char *separators = " ";
    int count = 0;

    char *strToken = strtok (argv[1], separators);
    (void) argc;
    for(count = 2; strToken != NULL; count++)
    {
        printf ( "%s\n", strToken);
        strToken = strtok (argv[count], separators);
    }

    return (EXIT_SUCCESS);
}

