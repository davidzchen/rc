#ifndef SRC_REDIR_H__
#define SRC_REDIR_H__

#include "parser.h"

typedef enum redirtype {
  rFrom,
  rCreate,
  rAppend,
  rHeredoc,
  rHerestring
} redirtype;

typedef struct Redir {
  redirtype type;
  int fd;
} Redir;

typedef struct Dup {
  redirtype type;
  int left;
  int right;
} Dup;

typedef struct Rq {
  Node *r;
  struct Rq *n;
} Rq;

extern void doredirs(void);

#endif /* SRC_REDIR_H__ */
