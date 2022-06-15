#include "alx.h"

/**
  *prompt - sends signal the prompt
  *@sl: prompt signal
  *
  *Return: (void)
  */

void prompt(int sl)
{
	(void)sl;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
  *printprompt - prints the prompt to stdout
  *
  *Return: (void)
  */

void printprompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
  *main - main function.
  *@ac: argument count
  *@av: argument vector
  *@envp: enviroment variables
  *
  *Return: 0 on exit, 1 otherwise
  */

int main(int ac, char **av, char **envp)
{
	char *buf = NULL, **cmd;
	size_t len = 0;
	ssize_t chars;
	pid_t chpid;
	int status, counter = 0;
	(void)ac;

	printprompt();
	chars = getline(&buf, &len, stdin);
	while (chars)
	{
		signal(SIGINT, prompt);

		if (chars == EOF)
			end_of_file(buf);
		counter++;

		cmd = string_strtok(buf);
		chpid = fork();
		if (chpid  == -1)
			fork_handler();

		if (chpid == 0)
			ext(cmd, buf, envp, av, counter);
		else
		{
			wait(&status);
			freeptr(buf, cmd);
		}
		len = 0;
		buf = NULL;

		printprompt();
	}
	if (chars == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
