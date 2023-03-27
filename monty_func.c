#include "monty.h"
#define  _GNU_SOURCE


/**
 * open_file - Opens a file.
 * @file_name: String with the name of the file.
 */

void open_file(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
	{
		printf("Error: Can't open file %s\n",file_name);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	/*Checks if the file exists*/
	file_check = access(file_name, R_OK);
	if (file_check == -1)
	{
		printf("Error: Can't open file %s\n",file_name);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n",file_name);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	/*errors should be handled inside this function*/
	read_file(fd, file_name);
	/*might need to check for errors on closing a file.*/
	fclose(fd);
}

/**
 * read_file - Reads the content of a file line by line.
 * @fd: Pointer to a file descriptor of an open file
 */

void read_file(FILE *fd, char *file_name)
{
	int line_n, gln;
	int format;
	char *lineprt;
	size_t n;

	lineprt = NULL;
	n = 0;
	format = 0;

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n",file_name);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	gln = getline(&lineprt, &n, fd);
	/*Getting each line in the file*/
	for (line_n = 1; gln != -1; line_n++)
	{
		format = interpret_line(lineprt, line_n, format);
	}
free(lineprt);
}


/**
 * interpret_line - Separates each line into tokens to determine
 * which function to call.
 * @lineptr: String representing a line in a file.
 * @line_number: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int interpret_line(char *lineptr, int line_number, int format)
{
const char *delim;
char *opcode;
char *value, *last;

if (lineptr == NULL)
{
printf("Error: malloc failed\n");
free_nodes();
exit(EXIT_FAILURE);
}
delim = " ";
opcode = strtok(lineptr, delim);

/*handling blank lines*/
if (opcode == NULL)
return (format);
last = strrchr(lineptr, ' ');
value = last + 1;

if (strcmp(opcode, "queue") == 0)
		return (1);
    else if (strcmp(opcode, "push") == 0)
                return (0);
    printf("POcode is %s and value is %s", opcode, value);
    get_op_func(opcode, value, line_number, format);
	return (format);
}

/**
 * get_op_func - Finds the appropite function to run the opcode instructions.
 * @opcode: The operation code, It could be push, pall, ...
 * @value: The possible value for the operation.
 * @ln: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void get_op_func(char *opcode, char *value, int ln, int format)
{
	int i, flag;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{NULL, NULL},
	};

	if (opcode[0] == '#')
		return;
	/*Iterates through list to find the right function*/
	for (flag = 1, i = 0; instruct[i].opcode != NULL; i++)
	{
		/*When 0 found the right opcode*/
		if (strcmp(opcode, instruct[i].opcode) == 0)
		{
			call_fun(instruct[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		printf("L%d: unknown instruction %s\n", ln, opcode);
		free_nodes();
		exit(EXIT_FAILURE);
	}
}

/**
 * call_fun - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func f, char *op, char *val, int ln, int format)
{
stack_t *node;
int flag;
int i;

flag = 1;
if (strcmp(op, "push") == 0)
{
/*Checks if the number is negative and moves the val ptr*/
if (val != NULL && val[0] == '-')
{
val = val + 1;
flag = -1;
}
/*val is not a digit is the return value is 0*/
if (val == NULL)
{
printf("L%d: usage: push integer\n", ln);
exit(EXIT_FAILURE);
}
for (i = 0; val[i] != '\0'; i++)
{
if (isdigit(val[i]) == 0)
{
printf("L%d: usage: push integer\n",ln);
exit(EXIT_FAILURE);
}
}
node = create_node(atoi(val) * flag);
if (format == 0)
_push(&node, ln);
if (format == 1)
_queue(&node, ln);
}
else
f(&node, ln);
}
