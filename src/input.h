#ifndef SRC_INPUT_H__
#define SRC_INPUT_H__

#include "parser.h"

typedef enum inputtype {
  iFd,
  iString
} inputtype;

extern void initinput(void);
extern Node *parseline(char *);
extern int gchar(void);
extern void ugchar(int);
extern Node *doit(bool);
extern void flushu(void);
extern void print_prompt2(void);
extern void pushfd(int);
extern void pushstring(char **, bool);
extern void popinput(void);
extern void closefds(void);
extern int lastchar;
extern bool rcrc;

#endif /* SRC_INPUT_H__ */
