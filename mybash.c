#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybash.h"

void bash_loop(void)
{
	char *line;
	char **args;

	while(1)
	{
		line = read_line();
		args = parse(line);
		execute(args);
		
		prompt_print();

		free(line);
		free(args);
	}
}

int main(int argc, char **argv)
{
	//Load configuration.
	
	//Run command loop
	prompt_print();
	bash_loop();

	//Shoudown/Cleanup.

	return EXIT_SUCCESS;
}
