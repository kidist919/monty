#include "monty.h"

/**
  * rotr - rotates the last element to be the top element
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *copy;
	(void) line_number;

	copy = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (copy != NULL && (copy)->next != NULL)
		copy = copy->next;

	tmp = copy->prev;
	copy->prev = NULL;
	copy->next = *stack;
	(*stack)->prev = copy;
	tmp->next = NULL;
	*stack = copy;
}

/**
  * queue - changes mode for stack vs queue
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	glo.mode = 1;
}

/**
  * stac - changes mode for stack vs queue
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void stac(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	glo.mode = 0;
}

/**
  * push_help - helper function for push
  *
  * @stack: first element of the stack
  * @new_element: element to add
  * Return: void
  */
void push_help(stack_t **stack, stack_t *new_element)
{
	stack_t *tmp;

	if (glo.mode == 0)
	{
		tmp = *stack;
		new_element->next = tmp;
		*stack = new_element;
		if (tmp)
			tmp->prev = *stack;
	}
	else
	{
		stoq(stack, 0);
		tmp = *stack;
		new_element->next = tmp;
		if (tmp)
			tmp->prev = new_element;
		*stack = new_element;
		stoq(stack, 0);
	}
}
