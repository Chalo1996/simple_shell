#include "alx.h"

/**
  * freeEverything - frees all the memory
  * @ptr: memory pointer to free.
  *
  * Return: (void)
  */

void freeEverything(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);
	free(ptr);
}

/**
  *freecmdbuf - free the buffer commands
  * @buf: buffer
  * @cmd: commands store.
  *
  * Return: (void)
  */

void freecmdbuf(char *buf, char **cmd)
{
	free(buf);
	freeEverything(cmd);
}

/**
  *freeptr - Free when child == -1.
  *@buf: buffer
  *@cmd: commands array
  *
  *Return:(void)
  */

void freeptr(char *buf, char **cmd)
{
	if (cmd == NULL)
		freecmdbuf(buf, cmd);
	else if (_strcmp("exit", cmd[0]))
		prnt(buf, cmd);
	else
		freecmdbuf(buf, cmd);
}
