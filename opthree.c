#include "monty.h"

/**
  * mod - modulus of the top element from the second
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n %= tmp->n;
	*stack = (*stack)->next;
	tmp->prev = NULL;
	free(tmp);
}

/**
  * pchar - prints the char at the top of the stack
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar,", line_number);
		dprintf(STDERR_FILENO, " value out of range\n");
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}

	dprintf(STDOUT_FILENO, "%c\n", (*stack)->n);
}

/**
  * pstr - prints the string of the stack if possible
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	(void) line_number;

	if (stack == NULL)
		return;

	copy = *stack;
	while (copy != NULL && copy->n != 0)
	{
		if (copy->n < 0 || copy->n > 127)
			break;
		dprintf(STDOUT_FILENO, "%c", copy->n);
		copy = copy->next;
	}

	dprintf(STDOUT_FILENO, "\n");
}

/**
  * rotl - rotates the top of the stack to the last spot
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *copy, *tmp;
	(void) line_number;

	copy = *stack;
	tmp = *stack;

	if (stack == NULL)
		return;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	while (copy != NULL && copy->next != NULL)
		copy = copy->next;
	if (copy != NULL)
	{
		copy->next = tmp;
		tmp->next = NULL;
		tmp->prev = copy;
	}
}

/**
  * stoq - rotates the stack to the bottom
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void stoq(stack_t **stack, unsigned int line_number)
{
	stack_t *nex, *cur, *pre;
	(void) line_number;

	pre = NULL;
	cur = *stack;
	if (cur != NULL)
		nex = cur->next;
	else
		nex = NULL;

	while (cur != NULL)
	{
		cur->prev = nex;
		cur->next = pre;
		pre = cur;
		cur = nex;
		if (nex != NULL)
			nex = nex->next;
	}

	*stack = pre;
}
