#ifndef SRC_LIST_H__
#define SRC_LIST_H__

typedef struct List {
  char *w;
  char *m;
  struct List *n;
} List;

extern void list_free(List *);
extern List *list_copy(List *, void *(*)(size_t));
extern size_t list_length(List *);
extern int list_count(List *);

#endif /* SRC_LIST_H__ */
