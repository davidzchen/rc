#ifndef SRC_HEREDOC_H__
#define SRC_HEREDOC_H__

#include "parser.h"

typedef struct Hq Hq;

extern int heredoc(int);
extern int qdoc(Node *, Node *);
extern Hq *hq;

#endif /* SRC_HEREDOC_H__ */
