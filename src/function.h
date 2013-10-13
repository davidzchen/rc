#ifndef SRC_FUNCTION_H__
#define SRC_FUNCTION_H__

#include "parser.h"

typedef struct rc_Function {
  Node *def;
  char *extdef;
} rc_Function;

/* here for odd reasons; user-defined signal handlers are kept in fn.c */
extern void rc_exit(int);
extern void inithandler(void);
extern void setsigdefaults(bool);

extern void function_assign(char *, Node *);
extern void function_assign_string(char *);
extern Node *function_lookup(char *);
extern char *function_lookup_string(char *);
extern void function_remove(char *);
extern void whatare_all_signals(void);
extern void function_prettyprint(int, char *, Node *);

#endif /* SRC_FUNCTION_H__ */
