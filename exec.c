#include "alx.h"

/**
  *ext- Verify and execute every command
  *@commands: command entered
  *@buf: commands buffer.
  *@env: enviroment variables
  *@argv: argument counter
  *@counter: execution counter.
  *
  *Return: (void)
  */

void ext(char **commands, char *buf, char **env, char **argv, int counter)
{
	struct stat f1Stat;

	if (commands == NULL)
		freebuf(buf);
	else if (_strcmp("exit", commands[0]))
		prnt(buf, commands);
	else if (_strcmp("env", commands[0]))
		freebufend(buf, commands, env);
	else if (stat(commands[0], &f1Stat) == 0)
		execve(commands[0], commands, NULL);
	else
		_path(commands, buf, env, argv, counter);
}
