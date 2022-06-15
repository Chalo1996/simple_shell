#include "alx.h"

/**
  * fork_handler - handles a fork errors
  *
  * Return: (void)
  */

void fork_handler(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

/**
  *msg - Writes an error message
  *@av: argument vector
  *@cmd1: first command
  *@counter: number of cmd execution.
  *
  *Return: (void)
  */

void msg(char **av, char *cmd1, int counter)
{
	int len = 1, cptr, mult = 1;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	cptr = counter;

	while (cptr >= 10)
	{
		cptr /= 10;
		mult *= 10;
		len++;
	}

	while (len > 1)
	{
		if ((counter / mult) < 10)
			_geterror((counter / mult + '0'));
		else
			_geterror((counter / mult) % 10 + '0');
		--len;
		mult /= 10;
	}

	_geterror(counter % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd1, _strlen(cmd1));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
  * _geterror - Prints a char
  *@c: character to write
  *
  *Return: int
  */

int _geterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
  * end_of_file - function to control the EOF signal
  *@buf: buffer
  *
  *Return: (void)
  */

void end_of_file(char *buf)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buf);
	exit(0);
}
