#ifndef SRC_STATUS_H__
#define SRC_STATUS_H__

#include "list.h"

extern int istrue(void);
extern int getstatus(void);
extern void set(bool);
extern void setstatus(pid_t, int);
extern List *sgetstatus(void);
extern void setpipestatus(int [], int);
extern void statprint(pid_t, int);
extern void ssetstatus(char **);
extern char *strstatus(int s);

#endif /* SRC_STATUS_H__ */
