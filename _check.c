#include "monty.h"


/**
 * check -  verify if is number.
 *
 * @__t: token string.
 * Return: nothing.
 */
void check(char *__t)
{
int i = 0;

if (atoi(__t) < 0)
i++;

if ((isdigit(__t[i]) && strlen(__t) == _size(atoi(__t))) ||
(__t[0] == '-' && isdigit(__t[1])))
allData.val = atoi(__t);
else
{
fprintf(stderr, "L%d: usage: push integer\n", allData.line_num);
free_function(allData.stack_head);
exit(EXIT_FAILURE);
}
}
