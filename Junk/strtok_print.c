#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	char str[] = "Bonjour je m'appelle William";
	const char * separators = " ,.-!";

	char * strToken = strtok ( str, separators );
	while ( strToken != NULL )
	{
		printf ( "%s\n", strToken );
		strToken = strtok ( NULL, separators );
	}

	return EXIT_SUCCESS;
}

