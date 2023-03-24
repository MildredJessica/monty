#include "monty.h"

/**
 * _push - Adds a node at the end of the list
 * @head: The linked list
 * @n: The data
 * Return: A pointer to the linkedlist
 */
void _push(stack_t **stack, int n)
{
stack_t *new_node, *tmp;

new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
exit(EXIT_FAILURE);
new_node->prev = NULL;
new_node->n = n;
new_node->next = NULL;
if (*stack == NULL)
{
*stack = new_node;
return;
}
tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = new_node;
new_node->prev = tmp;
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
exit(EXIT_FAILURE);
}
while (tmp->next != NULL)
{
tmp->prev = tmp;
tmp = tmp->next;
}
tmp->prev->next = tmp->next;
free(tmp);
}
