#ifndef SRC_FOOTOBAR_H__
#define SRC_FOOTOBAR_H__

extern char **list2array(List *, bool);
extern char *get_name(char *);
extern List *parse_var(char *);
extern Node *parse_fn(char *);
extern void initprint(void);

/* here for odd reasons; user-defined signal handlers are kept in fn.c */
extern void rc_exit(int); 

#endif /* SRC_FOOTOBAR_H__ */
