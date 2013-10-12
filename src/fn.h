#ifndef SRC_FN_H__
#define SRC_FN_H__

#include "parser.h"

typedef struct rc_Function {
  Node *def;
  char *extdef;
} rc_Function;

/* here for odd reasons; user-defined signal handlers are kept in fn.c */
extern void rc_exit(int);
extern void inithandler(void);
extern void setsigdefaults(bool);
extern void fnassign(char *, Node *);
extern void fnassign_string(char *);
extern Node *fnlookup(char *);
extern char *fnlookup_string(char *);
extern void fnrm(char *);
extern void whatare_all_signals(void);
extern void prettyprint_fn(int, char *, Node *);

#endif /* SRC_FN_H__ */
