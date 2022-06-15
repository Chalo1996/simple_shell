#ifndef ALX_SCHOOL
#define ALX_SCHOOL

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void prompt(int sl);
void printprompt(void);

unsigned int numcmd(char *str);
/* unsigned int cmd_len(char *s); */
char **string_strtok(char *str);

void ext(char **cmd, char *buf, char **envp,
		char **av, int counter);

char *_strncpy(char *dest, char *src, int len);
char *_conststrncpy(char *dest, const char *src, int len);
unsigned int _conststrlen(const char *str);
unsigned int _strlen(char *str);
int _strcmp(char *s1, char *s2);

unsigned int num_dir(char *path);
char **pathptr(char *cmd1, char **env_var);
char *_getenv_var(const char *name, char **env_var);
char *_cpycmd(char *dest, char *src, char *cmd, int len, int size);
void envp_print(char **env_var);

void freeEverything(char **ptr);
void freecmdbuf(char *buf, char **cmd);
void freeptr(char *buf, char **cmd);

void msg(char **av, char *cmd1, int counter);
int _geterror(char c);
void end_of_file(char *buf);
void fork_handler(void);

void freebuf(char *buf);
void prnt(char *buf, char **cmd);
void freebufend(char *buf, char **cmd, char **envp);
void _path(char **cmd, char *buf, char **envp, char **av, int counter);

#endif /* ALX_SCHOOL */
