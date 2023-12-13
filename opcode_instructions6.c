#include "monty.h"
/**
  *_rotl- this function rotates the stack to the top
  *@head: stack head
  *@co: line_number
  *Return: nothing
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int co)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
  *_rotr- this function rotates the stack to the bottom
  *@head: stack head
  *@co: line_number
  *Return: nothing
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int co)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

