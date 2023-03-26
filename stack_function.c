#include "monty.h"

/**
 * _push - Adds a node at the end of the list
 * @head: The linked list
 * @n: The data
 * Return: A pointer to the linkedlist
 */
void _push(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
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
 * _pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Pointer to a pointer pointing to the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
printf("L%d: can't pint, stack empty", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
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
printf("L%d: can't pop an stack empty\n", ln);
free_nodes();
exit(EXIT_FAILURE);
}

(*stack) = tmp->next;
if ((*stack)!= NULL)
(*stack)->prev = NULL;
free(tmp);
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}