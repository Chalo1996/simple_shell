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
  *@cmd: command inserted
  *
  *Return: (void)
  */

void free_all(char *buf, char **cmd)
{
	free(buf);
	freeEverything(cmd);
	exit(EXIT_SUCCESS);
}


/**
  * prnt - free all buff cmds.
  *@buf: buffer
  *@cmd: commands
  *
  *Return: (void)
  */

void prnt(char *buf, char **cmd)
{
	free(buf);
	freeEverything(cmd);
	exit(EXIT_SUCCESS);
}

/**
  *freebufend - frees enf of buffer.
  *@buf: buffer.
  *@cmd: commands array.
  *@envp: enviroment variables
  *
  *Return: (void)
  */

void freebufend(char *buf, char **cmd, char **envp)
{
	free(buf);
	freeEverything(cmd);
	envp_print(envp);
	exit(EXIT_SUCCESS);
}

/**
  * _path - Get path and execute command.
  *@cmd: array of commands
  *@buf: buffer.
  *@envp: enviroment variables
  *@av: argument vector
  *@counter: number of command execution.
  *
  *Return - (void).
  */

void _path(char **cmd, char *buf, char **envp, char **av, int counter)
{
	struct stat f2Stat;
	char **dirs;
	int i = 0;

	dirs = pathptr(cmd[0], envp);
	while (dirs[i])
	{
		if (stat(dirs[i], &f2Stat) == 0)
			execve(dirs[i], cmd, NULL);
		i++;
	}

	msg(av, cmd[0], counter);

	free(buf);
	freeEverything(cmd);
	freeEverything(dirs);
	exit(EXIT_SUCCESS);
}
