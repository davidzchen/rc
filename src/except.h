#ifndef SRC_EXCEPT_H__
#define SRC_EXCEPT_H__

#include "nalloc.h"
#include "jbwrap.h"

typedef union Edata {
  Jbwrap *jb;
  Block *b;
  char *name;
  int fd;
} Edata;

typedef enum ecodes {
  eError,
  eBreak,
  eReturn,
  eVarstack,
  eArena,
  eFifo,
  eFd
} ecodes;

typedef struct Estack {
  ecodes e;
  bool interactive;
  Edata data;
  struct Estack *prev;
} Estack;

extern bool nl_on_intr;
extern bool outstanding_cmdarg(void);
extern void pop_cmdarg(bool);
extern void rc_raise(ecodes);
extern void except(ecodes, Edata, Estack *);
extern void unexcept(void);
extern void rc_error(char *);
extern void sigint(int);

#endif /* SRC_EXCEPT_H__ */
