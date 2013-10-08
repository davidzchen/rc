#ifndef SRC_VAR_H__
#define SRC_VAR_H__

extern char *varlookup_string(char *);
extern List *varlookup(char *);
extern void varassign(char *, List *, bool);
extern bool varassign_string(char *);
extern void varrm(char *, bool);
extern void starassign(char *, char **, bool);
extern void alias(char *name, List *s, bool stack);
extern void prettyprint_var(int fd, char *name, List *s);

#endif /* SRC_VAR_H__ */
