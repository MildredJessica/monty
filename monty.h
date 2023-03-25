#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

extern int sq_flag;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _push(stack_t **new_node, __attribute__((unused))unsigned int ln);
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint(stack_t **head, const int n);
/**void _pop(stack_t **stack, unsigned int ln);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int ln);
void _sub(stack_t **stack, unsigned int ln);
void _div(stack_t **stack, unsigned int ln);
void _mul(stack_t **stack, unsigned int ln);
void _mod(stack_t **stack, unsigned int ln);
void read_file(char *filename, stack_t **stack);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
typedef void (*instruct_func) get_op_func(char *str);
char *parse_line(char *line);
void call_fun(op_func f, char *op, char *val, int ln, int format);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);

void free_nodes(void);
stack_t *add_dnodeint(stack_t **head, const int n);
*/
#endif
