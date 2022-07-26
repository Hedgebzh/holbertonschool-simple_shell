#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void read_command(char cmd[], char par[]);
void type_prompt();
int main();

#endif
