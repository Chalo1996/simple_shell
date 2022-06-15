#include "alx.h"

/**
  *num_dir - Computes for number of directories
  *@path: the path
  *
  *Return: number of directories.
  */
unsigned int num_dir(char *path)
{
	unsigned int i, flags, dirnum;

	i = flags = dirnum = 0;

	while (path[i])
	{
		if (path[i] != ':')
			flags = 1;

		if ((flags && path[i + 1] == ':') || (flags && path[i + 1] == '\0'))
		{
			dirnum++;
			flags = 0;
		}
		i++;
		}

		return (dirnum);
}

/**
  *pathptr - Stores path as a pointer.
  *@cmd1: first command inserted in the prompt
  *@env_var: enviroment variables
  *
  *Return: enviroment variables
  */

char **pathptr(char *cmd1, char **env_var)
{
	char **dirs, *envp_path, *dir;
	unsigned int len, i = 0;
	int lendir, cmd_len;

	envp_path = _getenv_var("PATH", env_var);
	len = num_dir(envp_path);
	dirs = malloc(sizeof(char *) * (len + 1));
	if (dirs == NULL)
		return (NULL);

	dir = strtok(envp_path, ":");

	while (dir != NULL)
	{
		lendir = _strlen(dir);
		cmd_len = _strlen(cmd1);
		dirs[i] = malloc(sizeof(char *) *
		(lendir + cmd_len + 2));
		if (dirs[i] == NULL)
		{
			freeEverything(dirs);
			return (NULL);
		}
			_cpycmd(dirs[i], dir, cmd1,
			lendir, cmd_len);
			i++;
		dir = strtok(NULL, ":");
	}

		dirs[i] = NULL;

	return (dirs);
}

/**
  * _getenv_var - Gets enviroment variable
  *@name: enviroment variable name.
  *@env_var: enviroment variables
  *
  *Return: the variable value.
  */

char *_getenv_var(const char *name, char **env_var)
{
	char *val_env, *name_env;
	unsigned int i = 0, len;

	len = _conststrlen(name);

	name_env = malloc(sizeof(char) * len + 1);
	if (name_env == NULL)
		return (NULL);

	_conststrncpy(name_env, name, len);

	val_env = strtok(env_var[i], "=");
	while (env_var[i])
	{
		if (_strcmp(val_env, name_env))
		{
			val_env = strtok(NULL, "\n");
			free(name_env);
			return (val_env);
		}
		i++;
		val_env = strtok(env_var[i], "=");
	}
	free(name_env);
	return (NULL);
}

/**
  *_cpycmd - Copies the path
  *@dest: destination
  *@src: source
  *@cmd: command to append
  *@len: length of destination
  *@size: length of command
  *
  *Return: dest
  */

char *_cpycmd(char *dest, char *src, char *cmd, int len, int size)
{
	int i, j;

	for (i = 0; i < len && src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '/';
	i++;

	for (j = 0; j < size && cmd[j] != '\0'; j++, i++)
		dest[i] = cmd[j];
	dest[i] = '\0';
	return (dest);
}

/**
  *envp_print - Print all enviroment variables
  *@env_var: enviroment variables for the user
  *
  *Return: (void)
  */

void envp_print(char **env_var)
{
	unsigned int i = 0, len;

	while (env_var[i])
	{
		len = _strlen(env_var[i]);
		write(STDOUT_FILENO, env_var[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
