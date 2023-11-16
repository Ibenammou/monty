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
    stack_t *my_node;

    if (!stack_head)
        return;

    my_node = malloc(sizeof(stack_t));
    if (!my_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_function(*stack_head);  // Corrected variable name and added proper freeing
        exit(EXIT_FAILURE);
    }

    my_node->n = allData.val;
    my_node->prev = NULL;

    if (!*stack_head)
    {
        my_node->next = NULL;
        *stack_head = my_node;
    }
    else if (allData.stack_mode == 0)
    {
        my_node->next = *stack_head;
        (*stack_head)->prev = my_node;
        *stack_head = my_node;
    }
    else if (allData.stack_mode == 1)
    {
        stack_t *last_node = *stack_head;

        while (last_node->next)
            last_node = last_node->next;

        last_node->next = my_node;
        my_node->prev = last_node;
        my_node->next = NULL;
    }
}
void pall_function(stack_t **stack_head, unsigned int line_number)
{
    stack_t *my_node = *stack_head;
    int i;

    (void)line_number;

    while (my_node)
    {
        fprintf(stdout, "%d\n", my_node->n);
        my_node = my_node->next;
    }

    fflush(stdout);
}

