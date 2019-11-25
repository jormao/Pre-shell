DESCRIPTION

The shell is a program that presents a command line interface that allows you to control your computer using commands entered with a keyboard.

Used prototypes and their variables








In addition to commands, shells offer other elements to improve their functionality, such as variables, functions or control structures. The set of commands and elements available, as well as their syntax, will depend on the particular shell used.

how to use it

The command is a sequence of words or tokens separated by delimiters. The first word specifies the name 
of the command to be executed. The remaining words are passed as arguments to the summoned command.
The command name is passed as an argument.

Example
	#!/bin/bash
	to_print='Hello world'
	echo $to_print
	to_print=5.5
	echo $to_print

Example

# ls -l

total 12
-rw-r--r-- 1 root root  100 apr  6 21:19 file.txt
drwxr-xr-x 3 root root 4096 apr  7 01:44 file2
drwxr-xr-x 2 root root 4096 apr  6 22:19 file3

Example

root@kali:~# cd ejemplos/carpeta2
root@kali:~/ejemplos/carpeta2# pwd
/root/ejemplos/carpeta2


CONTRIBUTORS

Jorge Salazar - @holbertonschool.com
Julian Castañeda - 1277@holbertonschool.com
