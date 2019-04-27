#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybash.h"

#define BUF_SIZE 1024;

char * read_line(void)
{
	int buffer_size = BUF_SIZE;
	char * input = malloc(buffer_size * sizeof(char));
	int i = 0;
	char c;

	if (input == NULL)
	{
		fprintf(stderr, "error: malloc failed.\n");
		exit(1);
	}

	while ((c = getchar()) != '\n')
	{
		if (i >= buffer_size)
		{
			buffer_size = 2 * buffer_size;
			input = realloc(input, buffer_size);
		}

		input[i++] = c;
	}

	input[i] = '\0';
	return input;
}
