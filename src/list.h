#ifndef SRC_LIST_H__
#define SRC_LIST_H__

extern void listfree(List *);
extern List *listcpy(List *, void *(*)(size_t));
extern size_t listlen(List *);
extern int listnel(List *);

#endif /* SRC_LIST_H__ */
