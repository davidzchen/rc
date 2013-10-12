#ifndef SRC_TREE_H__
#define SRC_TREE_H__

#include "parser.h"

extern Node *mk(int /*nodetype*/,...);
extern Node *treecpy(Node *, void *(*)(size_t));
extern void treefree(Node *);

#endif /* SRC_TREE_H__ */
