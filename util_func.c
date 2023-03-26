#include "monty.h"

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Integer representing the line number of of the opcode.
 */
void _rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *tmp = *stack;
while (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
(*stack)->prev = tmp;
*stack = (*stack)->next;
(*stack)->prev= NULL;
}


/**
 * rotr - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Integer representing the line number of of the opcode.
 */
void _rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *tmp = *stack;
while (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
tmp->prev->next = NULL;
(*stack)->prev = tmp;
*stack = tmp;
(*stack)->prev = NULL;
}
