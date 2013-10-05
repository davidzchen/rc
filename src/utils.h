#ifndef SRC_UTILS_H__
#define SRC_UTILS_H__

extern bool isabsolute(char *);
extern int n2u(char *, unsigned int);
extern int mvfd(int, int);
extern int starstrcmp(const void *, const void *);
extern void pr_error(char *, int);
extern void panic(char *);
extern void uerror(char *);

#endif /* SRC_UTILS_H__ */
