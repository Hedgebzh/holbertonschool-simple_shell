#ifndef HEADER_SHELL
#define HEADER_SHELL
#include <stdarg.h> /* va_arg, va_list, va_end,*/
#include <stdlib.h> /* malloc */
#include <unistd.h> /* write */
#include <stdio.h>
#include <string.h> // strtok
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

int print_av(int ac, char **av);
int print_pid();
int pid(void);
int main(void);

#endif
