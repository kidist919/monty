#include "monty.h"

/**
  * push - pushes an element to the stack
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_element;
	char *token;
	int i = 0, n;

	if (stack == NULL)
		return;
	token = strtok(NULL, " \n\r\t");
	if (token != NULL)
	{
		for (i = 0; *(token + i) != '\0'; i++)
		{
			if (*token == '-' || *token == '+')
				continue;
			if (*(token + i) < 48 || *(token + i) > 57)
				break;
		}
	}
	if (token == NULL || *(token + i) != '\0')
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	new_element = malloc_stack(*stack);
	new_element->n = n;
	new_element->prev = NULL;

	push_help(stack, new_element);
}

/**
  * pall - prints elements of the stack, last to first
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = NULL;
	(void) line_number;

	if (stack)
		copy = *stack;
	while (copy != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", copy->n);
		copy = copy->next;
	}
}

/**
  * pint - prints the first element of the stack
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
	}
}

/**
  * pop - pops off the first element of the stack
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	if (tmp)
		tmp->prev = NULL;
	*stack = tmp;
}

/**
  * nop - does nothing
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
