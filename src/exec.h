#ifndef SRC_EXEC_H__
#define SRC_EXEC_H__

#include "list.h"

extern void exec(List *, bool);

#if HASH_BANG
#define rc_execve execve
#else
/* execve.c */
extern int my_execve(char *, char **, char **);
#endif

#endif /* SRC_EXEC_H__ */
