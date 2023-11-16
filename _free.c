#include "monty.h"


/**
 * free_function -  frees the stack.
 * @stack_head: the top of the stack.
 * Return: nothing.
 */
void free_function(stack_t *stack_head)
{
stack_t *stack_a, *stack_b;

stack_a = stack_head;
while (stack_a)
{
stack_b = stack_a->next;
free(stack_a);
stack_a = stack_b;
}

allData.stack_head = NULL;
fclose(allData.my_file);
}
