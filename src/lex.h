#ifndef SRC_LEX_H__
#define SRC_LEX_H__

extern bool quotep(char *, bool);
extern int yylex(void);
extern void inityy(void);
extern void yyerror(const char *);
extern void scanerror(char *);
extern const char nw[], dnw[];

#endif /* SRC_LEX_H__ */
