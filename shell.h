#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#define vo (void)
#define NOT_INBUILT 4096

extern int errno;
extern char **environ;

typedef struct inbuilts {
	char *name;
	int (*func)(void);
} inbuit_t;

size_t _strlen(char *str);
void getlne(char *prompt, char *);
char **sep(char *cmd);
int execute_bin(char **token);
void execute_cmd(char **tokens, char *path);
int _strcmp(char *s1, const char *s2);
char *_getenv(char *name);
char *_strdup(char *s);
char *_strcpy(char *, char *);
char *_strcat(char *dest, char *src);
char *getpath(char *path);
void printerr(int err, char *cmd, char *prog);
int _strncmp(char *s1, const char *s2, size_t n);


#endif
