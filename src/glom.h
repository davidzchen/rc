#ifndef SRC_GLOM_H__
#define SRC_GLOM_H__

#include "redir.h"

extern Rq *redirq;

extern void assign(List *, List *, bool);
extern void qredir(Node *);
extern List *append(List *, List*);
extern List *flatten(List *);
extern List *glom(Node *);
extern List *concat(List *, List *);
extern List *varsub(List *, List *);
extern List *word(char *, char *);

#endif /* SRC_GLOM_H__ */
