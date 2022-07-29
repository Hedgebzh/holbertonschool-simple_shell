#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

void parseCmd(char* cmd, char** params);
int executeCmd(char** params);
int main(void);

#endif
