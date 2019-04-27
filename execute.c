#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "mybash.h"

/*builtin part*/
int bash_cd(char **args);
int bash_help(char **args);
int bash_exit(char **args);

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&bash_cd,
	&bash_help,
	&bash_exit
};

int num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int bash_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "error: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("bash");
		}
	}
	return 1;
}

int bash_help(char **args)
{
	int i;
	printf("For project\n");
	printf("Built in list:\n");

	for (i = 0; i < num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	return 1;
}

int bash_exit(char **args)
{
	exit(0);
}
/*execution part*/
int execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return 1;
	}

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i])(args);
		}
	}
	return launch(args);
}

int launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if(execvp(args[0], args) == -1)
		{
			perror("mybash");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("mybash");
	}
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
	
	}
}
