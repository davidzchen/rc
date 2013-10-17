#ifndef SRC_VAR_H__
#define SRC_VAR_H__

#include "list.h"

typedef struct Variable {
  List *def;
  char *extdef;
  struct Variable *n;
} Variable;

extern char *variable_lookup_string(char *);
extern List *variable_lookup(char *);
extern void variable_assign(char *, List *, bool);
extern bool variable_assign_string(char *);
extern void variable_remove(char *, bool);
extern void variable_star_assign(char *, char **, bool);
extern void variable_alias(char *name, List *s, bool stack);
extern void variable_prettyprint(int fd, char *name, List *s);

#endif /* SRC_VAR_H__ */
