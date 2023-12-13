#include "monty.h"

/**
  *_nop- do nothing
  *@head: stack head
  *@co: line_number
  *Return: nothing
 */
void _nop(stack_t **head, unsigned int co)
{
	(void) co;
	(void) head;
}

/**
  *_sub- subtracts top element of stack from second top element of stack
  *@head: stack head
  *@counter: line_number
  *Return: nothing
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

