#include "monty.h"


/**
 * delete_spaces - Removes spaces from a given string.
 * @string: the given string.
 * Return: string.
 */
char *delete_spaces(char *string)
{
while (*string)
{

if (*string == ' ')
{
string++;
}
else
{
break;
}

}
return (string);
}
