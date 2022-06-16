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
  *@argv: argument vector
  *@env: enviroment variables
  *
  *Return: 0 on exit, 1 otherwise
  */

int main(int ac, char **argv, char **env)
{
	char *buf = NULL, **commands;
	size_t len = 0;
	ssize_t chars;
	pid_t chpid;
	int status, counter = 0;
	(void)ac;

	printprompt();
	while ((chars = getline(&buf, &len, stdin)))
	{
		signal(SIGINT, prompt);

		if (chars == EOF)
			end_of_file(buf);
		counter++;

		commands = string_strtok(buf);
		chpid = fork();
		if (chpid  == -1)
			fork_handler();

		if (chpid == 0)
			ext(commands, buf, env, argv, counter);
		else
		{
			wait(&status);
			freeptr(buf, commands);
		}
		len = 0, buf = NULL;
		printprompt();
	}
	if (chars == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
