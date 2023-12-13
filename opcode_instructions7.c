#include "monty.h"
/**
 * _stack -  sets the format of the data to a stack (LIFO)
 * @head: stack head
 * @co: line_number
 * Return: nothing
*/
void _stack(stack_t **head, unsigned int co)
{
	(void)head;
	(void)co;
	bus.lifi = 0;
}

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @head: stack head
 * @co: line_number
 * Return: no return
*/
void _queue(stack_t **head, unsigned int co)
{
	(void)head;
	(void)co;
	bus.lifi = 1;
}

/**
 * addqueue - adds a new node to the stack
 * @n: new_value
 * @head: head of the stack
 * Return: nothing
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

