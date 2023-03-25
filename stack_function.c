#include "monty.h"

/**
 * _push - Adds a node at the end of the list
 * @head: The linked list
 * @n: The data
 * Return: A pointer to the linkedlist
 */
void _push(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *new;
char *arg;
int push_arg;

push_arg = 0;
new = malloc(sizeof(stack_t));
if (!new)
{
printf("Error: malloc failed\n");
error_exit(stack);
}

arg = strtok(NULL, "\n ");
if (isnumber(arg) == 1 && arg != NULL)
push_arg = atoi(arg);
else
{
printf("L%d: usage: push integer\n", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
if (sq_flag == 1)
add_dnodeint_end(stack, push_arg);
if (sq_flag == 0)
add_dnodeint(stack, push_arg);
}

/**
 * _pall - Prints all the values on the stack, starting from the top of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *tmp = *stack;

while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}

/**
 * _pop - Removes the top element of the stack.
 * @stack: Pointer to a pointer pointing to the stack
 * @ln: Integer representing the line number of of the opcode
 */
void _pop(stack_t **stack, unsigned int ln)
{
stack_t *tmp = *stack;

if (*stack == NULL)
{
printf("L%d: can't pint, stack empty", ln);
free_nodes();
exit(EXIT_FAILURE);
}

(*stack) = tmp->next;
if ((*stack)!= NULL)
(*stack)->prev = NULL;
free(tmp);
}
