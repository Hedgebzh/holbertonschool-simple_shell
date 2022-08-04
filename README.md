C - Simple Shell

### Introduction

For this project we made our own simple shell (linux command line interpreter).

<p align="center" width="100%">
    <img width="33%" src="http://image.noelshack.com/fichiers/2022/31/4/1659649554-diagramme-sans-nom-drawio-3.png">
</p>


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

## Simple Shell
> The shell is the Linux command line interpreter. It provides an interface between the user and the kernel and executes programs called commands. For example, if a user enters "ls" then the shell executes the ls command. The shell can also execute other programs such as applications, scripts, and user programs (e.g., written in c or the shell programming language).

### Synopsis

> This repository holds all the code necessary for our custom ```simple shell``` to run.
> Our shell currently handles the executions of executables found in the PATH, with or without their full paths (/bin/ls or just ls). Sample commands that our shell supports include ls, mkdir, pwd, echo, whoami, whereis, etc.


### Built-Ins

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
hsh shell.h shell.c
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
