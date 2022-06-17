#include "monty.h"

/**
  * malloc_stack - allocates memory for a stack element
  *
  * @stack: stack that exists already in case of error
  * Return: linked list node or exits with status EXIT_FAILURE
  */
stack_t *malloc_stack(stack_t *stack)
{
	stack_t *element;

	element = malloc(sizeof(stack_t));
	if (element == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		memory_clear(stack);
		exit(EXIT_FAILURE);
	}

	return (element);
}

/**
  * free_stack - frees the stack
  *
  * @head: bottom element of stack
  * Return: void
  */
void free_stack(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
  * memory_clear - frees stack, buffer, and closes file
  *
  * @stack: first element of stack
  * Return: void
  */
void memory_clear(stack_t *stack)
{
	free_stack(stack);
	if (glo.buffer)
		free(glo.buffer);
	fclose(glo.fp);
}
