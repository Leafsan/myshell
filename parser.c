#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybash.h"

#define TOK_BUFSIZE 64

char ** parse(char * line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char ** tokens = malloc(bufsize * sizeof(char*));
	char * token;

	if(!tokens)
	{
		fprintf(stderr, "error: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if(position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
		tokens = realloc(tokens, bufsize * sizeof(char*));

			if(!tokens)
			{
				fprintf(stderr, "error: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	

	token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return tokens;
}
