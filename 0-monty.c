#include "monty.h"


/**
 * push_function -  Adds a new node at the beginning of a
 * double-linked list.
 * @stack_head: The head.
 * @line_number: line number of opcode
 * Return: none
 */
void push_function(stack_t **stack_head, unsigned int line_number)
{
int i = 0;
stack_t *my_node, *last_node;
(void)line_number;
if (!stack_head)
return;
my_node = malloc(sizeof(stack_t));
if (!my_node)
{
fprintf(stderr, "Error: malloc failed");
free_function(allData.stack_head);
exit(EXIT_FAILURE);
}
my_node->n = allData.val;
if (allData.stack_mode == 0 || !*stack_head)
{
if (*stack_head)
{
my_node->next = *stack_head;
(*stack_head)->prev = my_node;
}
else
my_node->next = NULL;
my_node->prev = NULL;
*stack_head = my_node;
}
else if (allData.stack_mode == 1)
{
last_node = *stack_head;
for (i = 0; last_node; i++)
{
if (!last_node->next)
break;
last_node = last_node->next;
}
last_node->next = my_node;
my_node->prev = last_node;
my_node->next = NULL;
}
}

/**
 * pall_function -  prints elements the list.
 * @stack_head: The head.
 * @line_number: number of lines.
 * Return: nothing.
 */
void pall_function(stack_t **stack_head, unsigned int line_number)
{
stack_t *my_node = *stack_head;
int i;

(void)line_number;
for (i = 0; my_node; i++)
{
fprintf(stdout, "%d\n", my_node->n);
my_node = my_node->next;
}

fflush(stdout);
}


