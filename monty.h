#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

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

typedef void (*op_func)(stack_t **, unsigned int);

void call_fun(op_func f, char *op, char *val, int ln, int format);
void get_op_func(char *opcode, char *value, int ln, int format);
int interpret_line(char *lineptr, int line_number, int format);
void read_file(FILE *fd, char *file_name);
void open_file(char *file_name);

void _push(stack_t **stack, unsigned int n);
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int ln);
void _pint(stack_t **stack, unsigned int line_number);

void _queue(stack_t **stack, unsigned int n);

void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int ln);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);


void _add(stack_t **stack, unsigned int ln);
void _sub(stack_t **stack, unsigned int ln);
void _div(stack_t **stack, unsigned int ln);
void _mul(stack_t **stack, unsigned int ln);
void _mod(stack_t **stack, unsigned int ln);

stack_t *add_dnodeint_end(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint(stack_t **head, const int n);

stack_t *create_node(int n);
void free_nodes(void);

char *parse_line(char *line);


/**


void read_file(char *filename, stack_t **stack);


typedef void (*instruct_func) get_op_func(char *str);
char *parse_line(char *line);
void call_fun(op_func f, char *op, char *val, int ln, int format);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);

void free_nodes(void);
stack_t *add_dnodeint(stack_t **head, const int n);
*/
#endif
