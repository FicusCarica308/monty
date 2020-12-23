#include "monty.h"
void op_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp_head;

    temp_head = *stack;
    if (temp_head == NULL)
    {
        dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
        push_value = -1;
    }
    else
    {
        if (temp_head->next != NULL)
			temp_head->next->prev = NULL;
		*stack = temp_head->next;
		free(temp_head);
    }
}