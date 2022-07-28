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

void read_command(char cmd[], char par[]);
void type_prompt();
int main();
int executeCmd(char par[]);
#endif
