#include "alx.h"

/**
  *freebuf - Free buffer.
  *@buf: buffer size.
  *
  *Return: (void)
  */

void freebuf(char *buf)
{
	free(buf);
	exit(EXIT_SUCCESS);
}

/**
  *free_all - free all getline args read.
  *@buf: buffer from getline.
  *@commands: command inserted
  *
  *Return: (void)
  */

void free_all(char *buf, char **commands)
{
	free(buf);
	freeEverything(commands);
	exit(EXIT_SUCCESS);
}


/**
  * prnt - free all buff cmds.
  *@buf: buffer
  *@commands: commands
  *
  *Return: (void)
  */

void prnt(char *buf, char **commands)
{
	free(buf);
	freeEverything(commands);
	exit(EXIT_SUCCESS);
}

/**
  *freebufend - frees enf of buffer.
  *@buf: buffer.
  *@commands: commands array.
  *@env: enviroment variables
  *
  *Return: (void)
  */

void freebufend(char *buf, char **commands, char **env)
{
	free(buf);
	freeEverything(commands);
	envp_print(env);
	exit(EXIT_SUCCESS);
}

/**
  * _path - Get path and execute command.
  *@commands: array of commands
  *@buf: buffer.
  *@env: enviroment variables
  *@argv: argument vector
  *@counter: number of command execution.
  *
  *Return - (void).
  */

void _path(char **commands, char *buf, char **env, char **argv, int counter)
{
	struct stat f2Stat;
	char **dirs;
	int i = 0;

	dirs = pathptr(commands[0], env);
	while (dirs[i])
	{
		if (stat(dirs[i], &f2Stat) == 0)
			execve(dirs[i], commands, NULL);
		i++;
	}

	msg(argv, commands[0], counter);

	free(buf);
	freeEverything(commands);
	freeEverything(dirs);
	exit(EXIT_SUCCESS);
}
