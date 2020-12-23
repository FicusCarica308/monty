#include "monty.h"
void op_add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp_head;

    temp_head = *stack;
    if (temp_head == NULL || temp_head->next == NULL)
    {
        dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
        push_value = -1;
    }
    else
    {
        temp_head->next->n = temp_head->n + temp_head->next->n;
        op_pop(&*stack, line_number);
    }
}