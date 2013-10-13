#ifndef SRC_HASH_H__
#define SRC_HASH_H__

#include "variable.h"
#include "function.h"

typedef struct Htab {
  char *name;
  void *p;
} Htab;

#define lookup_fn(s) ((rc_Function *) lookup(s, fp))
#define lookup_var(s) ((Variable *) lookup(s, vp));

extern Htab *fp, *vp;
extern void *lookup(char *, Htab *);
extern rc_Function *get_fn_place(char *);
extern Variable *get_var_place(char *, bool);
extern char **makeenv(void);
extern void delete_fn(char *);
extern void delete_var(char *, bool);
extern void initenv(char **);
extern void inithash(void);
extern void set_exportable(char *, bool);
extern void whatare_all_vars(bool, bool);

#endif /* SRC_HASH_H__ */
