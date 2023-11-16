#include "monty.h"


/**
 * _open -  this function open files.
 * @file: the file.
 * Return: file.
 */
FILE *_open(char *file)
{
FILE *my_file;

my_file = fopen(file, "r");

if (!my_file)
{
fprintf(stderr, "Error: Can't open file %s\n", file);
exit(EXIT_FAILURE);
}

return (my_file);
}
