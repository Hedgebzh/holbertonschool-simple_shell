#ifndef HEADER_SHELL
#define HEADER_SHELL
#include <stdarg.h> /* va_arg, va_list, va_end,*/
#include <stdlib.h> /* malloc */
#include <unistd.h> /* write */
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

int print_getline(void);
int my_pid(void);
int print_av(int ac, char **av);
int print_pid(void);
int strtok_print(int argc, char *argv[]);
int wait_h(void);
int fwe(void);
int main(void);


#endif
