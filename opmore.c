#include "monty.h"

/**
  * swap - swaps the top two elements of the stack
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	tmp->prev = NULL;
	*stack = tmp;

}

/**
  * add - adds the top two elements of the stack
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
  * sub - subtracts the top element from the second
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n -= tmp->n;
	*stack = (*stack)->next;
	tmp->prev = NULL;
	free(tmp);
}

/**
  * divi - divides the top element from the second
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
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
	tmp->next->n /= tmp->n;
	*stack = (*stack)->next;
	tmp->prev = NULL;
	free(tmp);
}

/**
  * mul - mul the top element from the second
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n *= tmp->n;
	*stack = (*stack)->next;
	tmp->prev = NULL;
	free(tmp);
}
