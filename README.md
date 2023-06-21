# About project
## Write a simple UNIX command interpreter.

### Built with
C programming language
<unistd.h>
<string.h>
<sys/types.h>
<sys/wait.h>

### 1. Simple shell 0.1
Write a UNIX command line interpreter.

### 2. Simple shell 0.2
Handle command lines with arguments

### 3. Simple shell 0.3
Handle the PATH
fork must not be called if the command doesn’t exist

### 4. Simple shell 0.4
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

### 5. Simple shell 1.0
Implement the env **built-in**, that prints the current environment

### 6. Simple shell 0.1.1
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline

### 7. Simple shell 0.2.1
You are not allowed to use strtok
