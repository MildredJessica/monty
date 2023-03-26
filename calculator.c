#include "monty.h"

/**
 * _add - Adds top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @ln: number of line opcode occurs on
 */
void _add(stack_t **stack, unsigned int ln)
{
int sum;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't add, stack too short", ln);
free_nodes();
exit(EXIT_FAILURE);
}
(*stack) = (*stack)->next;
sum = (*stack)->prev->n + (*stack)->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
 * _sub - Subtracts top of stack and second top of stack
 * @stack: Pointer to linked list stack
 * @ln: Number of line opcode occurs on
 */
void _sub(stack_t **stack, unsigned int ln)
{
int sum;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't sub, stack too short", ln);
free_nodes();
exit(EXIT_FAILURE);
}
(*stack) = (*stack)->next;
sum = (*stack)->n - (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
 * _div - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _div(stack_t **stack, unsigned int ln)
{
int sum;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't div, stack too short", ln);
free_nodes();
exit(EXIT_FAILURE);
}
(*stack) = (*stack)->next;
sum = (*stack)->n / (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
 * _mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _mul(stack_t **stack, unsigned int ln)
{
int sum;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't mul, stack too short", ln);
free_nodes();
exit(EXIT_FAILURE);
}
(*stack) = (*stack)->next;
sum = (*stack)->n * (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
 * _mod - Modolus the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _mod(stack_t **stack, unsigned int ln)
{
int sum;

if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't mod, stack too short", ln);
free_nodes();
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
printf("L%d: division by zero", ln);
free_nodes();
exit(EXIT_FAILURE);
}
(*stack) = (*stack)->next;
sum = (*stack)->n % (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
