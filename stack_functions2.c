#include "monty.h"


/**
 * _pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Pointer to a pointer pointing to the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

if (*stack == NULL)
{
printf("L%d: can't pint, stack empty", line_number);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
tmp = tmp->next;
printf("%d\n", tmp->n);
}


/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
int count = 0;

if (*stack == NULL)
{
printf("L%d: can't pint, stack empty", line_number);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
{
count++;
tmp->prev = tmp; 
tmp->next = tmp->next;
}
if (count == 1)
return;
int k = tmp->prev->n;
tmp->prev->n = tmp->n;
tmp->n = k;
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
printf("L%d: can't pchar, value out of range", line_number);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
tmp = tmp->next;
int value = tmp->n;
if (value < 0 || value > 127)
{
printf("L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
putchar(value);
putchar("\n");
}

/**
 * _pstr - Prints string starting a top of stack
 * @stack: linked list for stack
 */
void _pstr(stack_t **stack)
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