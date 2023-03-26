#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
int num;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't swap, stack too short", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
num = (*stack)->next->n;
(*stack)->next->n = (*stack)->n;
(*stack)->n = num;
}

/**
 * nop - Doesn’t do anything
 * @stack: pointer to linked list stack
 * @ln: number of line opcode occurs on
 */
void nop(__attribute__((unused))stack_t **stack, 
__attribute__((unused))unsigned int ln)
{
;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
if (*stack == NULL)
{
printf("L%d: can't pchar, stack empty", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
tmp = tmp->next;
int value = tmp->n;
if (value < 0 || value > 127)
{
printf("L%d: can't pchar, value out of range\n", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
putchar(value);
putchar("\n");
}


/**
 * _pstr - Prints string starting a top of stack
 * @stack: linked list for stack
 * @line_number: Integer representing the line number of of the opcode.
 */
void _pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *tmp = *stack;
int value;

while(tmp != NULL)
{
value = tmp->n;
if (value <= 0 || value > 127)
break;
putchar(value);
tmp = tmp->next;
}
putchar("\n");
}
