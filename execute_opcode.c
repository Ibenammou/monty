#include "monty.h"

/**
 * execute_opcode - execute the opcode.
 * nothing
 * Return: void function.
 */

void execute_opcode(void)
{
instruction_t my_instruction[] = {
{"push", push_function},
{"pall", pall_function},
{"pint", pint_function},
{"pop", pop_function},
{"swap", swap_function},
{"add", add_function},
{"nop", nop_function},
{"sub", sub_function},
{"div", div_function},
{"mul", mul_function},
{"mod", mod_function},
{"pchar", pchar_function},
{"pstr", pstr_function},
{"rotl", rotl_function},
{"rotr", rotr_function},
{"queue", mode_function},
{"stack", mode_function},
{NULL, NULL},
};
int index;
for (index = 0; my_instruction[index].opcode; index++)
{
if (strcmp(allData.opcode, my_instruction[index].opcode) == 0)
{
my_instruction[index].f(&allData.stack_head, allData.line_num);
break;
}
}
if (!my_instruction[index].opcode)
{
fprintf(stderr, "L%d: unknown instruction %s\n",
allData.line_num, allData.opcode);
free_function(allData.stack_head);
exit(EXIT_FAILURE);
}
}
