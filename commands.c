#include "alx.h"

/**
   *numcmd - compute fo number of commands.
   *@str: strings with equivalent commands.
   *
   *Return: commands.
   */

unsigned int numcmd(char *str)
{
	unsigned int i, command, flags;

	i = command = flags = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			flags = 1;
		if ((flags && str[i + 1] == ' ')
			|| (flags && str[i + 1] == '\0'))
		{
			++command;
			flags = 0;
		}
		i++;
	}
	return (command);
}

/**
  * string_strtok - pointer to each string
  * @str: command from the terminal
  *
  * Return: pointer to cmd arrays.
  */

char **string_strtok(char *str)
{
	char *token, **mem;
	unsigned int len;
	int i = 0;

	str[_strlen(str) - 1] = '\0';
	len = numcmd(str);
	if (len == 0)
		return (NULL);
	mem = malloc((sizeof(char *) * (len + 1)));
	if (mem == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		mem[i] = malloc(_strlen(token) + 1);
		if (mem[i] == NULL)
		{
			freeEverything(mem);
			return (NULL);
		}
		_strncpy(mem[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		i++;
	}
	mem[i] = NULL;
	return (mem);
}
