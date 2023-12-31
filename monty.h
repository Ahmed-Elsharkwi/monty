#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/**
struct stack_s - doubly linked list representation of a stack (or queue)
@n: integer
@prev: points to the previous element of the stack (or queue)
@next: points to the next element of the stack (or queue)
Description: doubly linked list node structure
for stack, queues, LIFO, FIFO 
*/
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
struct easy - doubly linked list representation of a stack (or queue)
@data: integer
@top_1: points to stack
*/
typedef struct easy
{
	int data;
	FILE *fp;
	char *buffer;
	stack_t *print_pointer;
	stack_t *holder;
} stack_p;
/**
struct instruction_s - opcode and its function
@opcode: the opcode
@f: function to handle the opcode
Description: opcode and its function
for stack, queues, LIFO, FIFO 
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_p top_2;

void push_int(stack_t **new, unsigned int line_number);
void pall_int(stack_t **new, unsigned int line_number);
void pint_int(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_nubmer);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void get_the_func(char *arg_1, char *arg_2, int line_numer);
int check_space(void);
void _free_1(void);
int is_number(char *str);
#endif
