#ifndef SRC_BUILTINS_H__
#define SRC_BUILTINS_H__

extern builtin_t *isbuiltin(char *);
extern void b_exec(char **);
extern void funcall(char **);
extern void b_dot(char **);
extern void b_builtin(char **);
extern char *which(char *, bool);

#endif /* SRC_BUILTINS_H__ */
