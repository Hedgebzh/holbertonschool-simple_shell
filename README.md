C - Simple Shell

### Introduction

For this project we made our own simple shell (linux command line interpreter).

![68747470733a2f2f692e696d6775722e636f6d2f536a71495573372e706e67](https://user-images.githubusercontent.com/105505927/178279750-67811154-48ec-4467-9dc4-e89813768989.png)

## Requirements

* Compilation command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 using gcc 
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to


### Synopsis

> This repository holds all the code necessary for our custom ```simple shell``` to run.
> Our shell currently handles the executions of executables found in the PATH, with or without their full paths (/bin/ls or just ls). Sample commands that our shell supports include ls, mkdir, pwd, echo, whoami, whereis, etc.


### Builtins

* `exit` exits shell (Usage: `exit`)
* `env` prints environmental variables (Usage: `env`)

### Files description

|File| Description |
|--|--|
| AUTHORS | Contains names of the authors.|
| README.md | Contains all you need to know about our program.|
| hsh | Executable file of simple shell.|
| man_1_simple_shell | Custom manpage for our simple shell. |
| shell.c |  Contains our command line interpreter code.|
| shell.h | Contains all functions prototypes used for our simple shell.|

### Environment

* Language: C
* OS: Ubuntu 20.04 LTS
* Compiler: gcc 7.3
* Style guidelines: Betty style

### How To Install

```
$git clone [https://github.com/Hedgebzh/holbertonschool-simple_shell.git]
$cd holbertonschool-simple_shell
```

### How to compile

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
### How to use

Non-Interactive Mode

```
$echo "ls" | ./hsh
AUTHORS hsh man_1_simple_shell README.md shell.c shell.h
$
```

Interactive Mode

```
$./hsh
 ($) ls
 AUTHORS hsh man_1_simple_shell README.md shell.c shell.h
 ($)
 ($) exit
$
```


### Authors
William Granger & Axel Goré
