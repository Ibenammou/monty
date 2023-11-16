#include "monty.h"


/**
 * main -  the main of the monty project.
 * @argc: number of arguments.
 * @argv: array of args.
 * Return: number.
 */
int main(int argc, char **argv)
{
char arguments[100], *_token;
int i = 0;
allData.stack_mode = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
allData.my_file = _open(argv[1]);
while (fgets(arguments, sizeof(arguments), allData.my_file) != NULL)
{
if (strlen(delete_spaces(arguments)) < 3 || delete_spaces(arguments)[0] == '#')
{
allData.line_num++;
continue;
}
allData.line_num++;
_token = strtok(arguments, " \n");
for (i = 0; _token != NULL && i < 2; i++)
{
if (i == 0)
{
allData.opcode = _token;
}
if (strcmp(allData.opcode, "push") != 0)
{
break;
}
if (i == 1)
{
check(_token);
}
_token = strtok(NULL, " \n");
}
if (strcmp(allData.opcode, "push") == 0 && i == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", allData.line_num);
free_function(allData.stack_head);
exit(EXIT_FAILURE);
}
execute_opcode();
}
free_function(allData.stack_head);
exit(EXIT_SUCCESS);
}
