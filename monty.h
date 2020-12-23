#ifndef _MONTY_H_
#define _MONTY_H_

/* Librarys */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/* data structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern int push_value;
int push_value;
/* Functions Prototypes */
void get_bytecodes(char *file_name);
void free_stack(stack_t **stack);
void invalid_error(unsigned int line_n, char **op_c, stack_t **stack, char *line, FILE *fd);
void push_error(unsigned int line_n, char **op_c, stack_t **stack, char *line, FILE *fd);
void free_error(char **op_c, stack_t **stack, char *line, FILE *fd);
/*stack handler protos*/
int stack_handler(char **op_code, unsigned int line_n, stack_t **stack);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
#endif
