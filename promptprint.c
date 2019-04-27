#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mybash.h"

#define PATH_LEN 150

int prompt_print(){
	char * buffer = malloc(PATH_LEN);
	char * path = getcwd(buffer, PATH_LEN);

	if(path != 0)
		fprintf(stdout, "2015040719@Myshell:%s>", buffer);
	free(buffer);

	return 0;
}
