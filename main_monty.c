#include "monty.h"


/**
 * main -  the main of the monty project.
 * @argc: number of arguments.
 * @argv: array of args.
 * Return: number.
 */// ...

int main(int argc, char **argv)
{
    char line[100], *_token;
    int i = 0;
    allData.stack_mode = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    allData.my_file = _open(argv[1]);

    while (fgets(line, sizeof(line), allData.my_file) != NULL)
    {
        // ...

        if (strcmp(allData.opcode, "push") == 0 && i == 1)
        {
            fprintf(stderr, "L%d: Usage: push integer\n", allData.line_num);
            free_function(allData.stack_head);
            exit(EXIT_FAILURE);
        }

        execute_opcode();
    }

    free_function(allData.stack_head);
    exit(EXIT_SUCCESS);
}

