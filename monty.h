#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globalData - all data in program
 * @val: value to push.
 * @line_num: number of lines.
 * @opcode: the opcode.
 * @my_file: file.
 * @stack_head: the top of stack.
 * @stack_mode: stack or queaue.
 */
typedef struct globalData
{
int val;
unsigned int line_num;
char *opcode;
FILE *my_file;
stack_t *stack_head;
int stack_mode;
} globalData;
globalData allData;

void execute_opcode(void);
char *delete_spaces(char *string);
void push_function(stack_t **stack_head, unsigned int line_number);
void pall_function(stack_t **stack_head, unsigned int line_number);
void pint_function(stack_t **stack_head, unsigned int line_number);
void pop_function(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}

/* Add other opcode functions as needed */

/**
 * execute_opcode - Executes the opcode provided in the Monty byte code file.
 * @opcode: Opcode to be executed.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in Monty byte code file where the opcode appears.
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    /* Add other opcodes here, for example: */
    if (strcmp(opcode, "pop") == 0)
        pop_function(stack, line_number);
    /* Add more opcodes as needed */
}

/* Add other helper functions and main logic as needed */
void swap_function(stack_t **stack_head, unsigned int line_number);
void add_function(stack_t **stack_head, unsigned int line_number);
void nop_function(stack_t **stack_head, unsigned int line_number);
void sub_function(stack_t **stack_head, unsigned int line_number);
void div_function(stack_t **stack_head, unsigned int line_number);
void mul_function(stack_t **stack_head, unsigned int line_number);
void mod_function(stack_t **stack_head, unsigned int line_number);
void pchar_function(stack_t **stack_head, unsigned int line_number);
void pstr_function(stack_t **stack_head, unsigned int line_number);
void rotl_function(stack_t **stack_head, unsigned int line_number);
void rotr_function(stack_t **stack_head, unsigned int line_number);
void mode_function(stack_t **stack_head, unsigned int line_number);
int main(int argc, char **argv);
FILE *_open(char *filename);
size_t _size(int num);
void check(char *token);
void free_function(stack_t *stack_head);

#endif

