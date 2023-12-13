#include "monty.h"
/**
 * _pall - this function prints the stack
 * @head: stack head
 * @co: line_number not used
 * Return: nothing
*/
void _pall(stack_t **head, unsigned int co)
{
	stack_t *h;
	(void)co;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pint - this function prints the top
 * @head: stack head
 * @co: line_number
 * Return: no return
*/
void _pint(stack_t **head, unsigned int co)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", co);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - this function prints the top
 * @head: stack head
 * @co: line_number
 * Return: nothing
*/
void _pop(stack_t **head, unsigned int co)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", co);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

