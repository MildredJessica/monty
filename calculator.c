#include "monty.h"

/**
 * _add - Adds top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @ln: number of line opcode occurs on
 */
void _add(stack_t **stack, unsigned int ln)
{
stack_t *tmp = *stack;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't add, stack too short", ln);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
{
tmp->prev = tmp;
tmp = tmp->next;
}
tmp->prev->n += tmp->n;
tmp->prev->next = NULL;
free(tmp);
tmp = tmp->prev;
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
 * _sub - Subtracts top of stack and second top of stack
 * @stack: Pointer to linked list stack
 * @ln: Number of line opcode occurs on
 */
void _sub(stack_t **stack, unsigned int ln)
{
stack_t *tmp = *stack;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't sub, stack too short", ln);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
{
tmp->prev = tmp;
tmp = tmp->next;
}
tmp->prev->n -= tmp->n;
tmp->prev->next = NULL;
free(tmp);
tmp = tmp->prev;
}

/**
 * _div - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _div(stack_t **stack, unsigned int ln)
{
stack_t *tmp = *stack;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't div, stack too short", ln);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
{
tmp->prev = tmp;
tmp = tmp->next;
}
if (tmp->n == 0)
{
printf("L%d: division by zero", ln);
exit(EXIT_FAILURE);
}
tmp->prev->n /= tmp->n;
tmp->prev->next = NULL;
free(tmp);
tmp = tmp->prev;
}

/**
 * _mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _mul(stack_t **stack, unsigned int ln)
{
stack_t *tmp = *stack;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't mul, stack too short", ln);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
{
tmp->prev = tmp;
tmp = tmp->next;
}
tmp->prev->n *= tmp->n;
tmp->prev->next = NULL;
free(tmp);
tmp = tmp->prev;
}

/**
 * _mod - Modolus the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _mod(stack_t **stack, unsigned int ln)
{
stack_t *tmp = *stack;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't mod, stack too short", ln);
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
{
tmp->prev = tmp;
tmp = tmp->next;
}
if (tmp->n == 0)
{
printf("L%d: division by zero", ln);
exit(EXIT_FAILURE);
}
tmp->prev->n %= tmp->n;
tmp->prev->next = NULL;
free(tmp);
tmp = tmp->prev;
}