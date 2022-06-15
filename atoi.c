#include "alx.h"

/**
  *_strncpy - Copy src to dest.
  *@dest: point of copy.
  *@src: string to copy to dest.
  *@len: string size.
  *
  *Return: destination.
  */

char *_strncpy(char *dest, char *src, int len)
{
	int i;

	for (i = 0; i < len && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < len; i++)
		dest[i] = '\0';

	return (dest);
}

/**
  * _conststrncpy - Copies a constant src into dest.
  *@dest: point of string
  *@src: string to copy
  *@len: string size.
  *
  *Return: destination
  */

char *_conststrncpy(char *dest, const char *src, int len)
{
	int i;

	for (i = 0; i < len && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < len; i++)
		dest[i] = '\0';

	return (dest);
}

/**
  * _conststrlen - Computes the length of a constant string.
  *@str: the string
  *
  *Return: length of the string
  */

unsigned int _conststrlen(const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
  * _strlen - Computes the length of a string
  *@str: the string.
  *
  *Return: length of the string
  */

unsigned int _strlen(char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
  * _strcmp - Compares length of two strings.
  *@s1: first string.
  *@s2: second string.
  *
  *Return: 1 if equal, 0 otherwise.
  */

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}

	return (1);
}
