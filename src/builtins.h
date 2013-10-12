#ifndef SRC_BUILTINS_H__
#define SRC_BUILTINS_H__

typedef void builtin_t(char **);

extern builtin_t *isbuiltin(char *);
extern void builtin_exec(char **);
extern void funcall(char **);
extern void builtin_dot(char **);
extern void builtin_builtin(char **);

#endif /* SRC_BUILTINS_H__ */
