#include "monty.h"

/**
 * pint_function -  prints the value at the top of
 * the double list.
 * @stack_head: tp of list.
 * @line_number: number of lines.
 * Return: nothing
 */
void pint_function(stack_t **stack_head, unsigned int line_number)
{

if (!*stack_head)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
free_function(allData.stack_head);
exit(EXIT_FAILURE);
}

fprintf(stdout, "%d\n", (*stack_head)->n);
fflush(stdout);

}
