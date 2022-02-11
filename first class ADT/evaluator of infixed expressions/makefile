#makefile
main: main.o stack_functions.o
	gcc main.o stack_functions.o -o main
main.o stack_functions.o:main.c stack_functions.c
	gcc -c $*.c