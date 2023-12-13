#include "monty.h"
/**
* execute - this function executes the opcode
* @stack: head linked list - stack
* @co: line_counter
* @file: poiner to monty file
* @content: line content
* Return: nothing
*/
int execute(char *content, stack_t **stack, unsigned int co, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opc;

	opc = strtok(content, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opc)
	{
		if (strcmp(opc, opst[i].opcode) == 0)
		{	opst[i].f(stack, co);
			return (0);
		}
		i++;
	}
	if (opc && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", co, opc);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

