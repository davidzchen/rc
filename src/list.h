#ifndef SRC_LIST_H__
#define SRC_LIST_H__

typedef struct List {
  char *w;
  char *m;
  struct List *n;
} List;

extern void listfree(List *);
extern List *listcpy(List *, void *(*)(size_t));
extern size_t listlen(List *);
extern int listnel(List *);

#endif /* SRC_LIST_H__ */
