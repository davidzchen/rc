#ifndef SRC_CONVERT_H__
#define SRC_CONVERT_H__

extern char **list2array(List *, bool);
extern char *get_name(char *);
extern List *parse_var(char *);
extern Node *parse_fn(char *);
extern void initprint(void);

#endif /* SRC_CONVERT_H__ */
