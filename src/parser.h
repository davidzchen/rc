#ifndef SRC_LANG_H__
#define SRC_LANG_H__

typedef struct Word {
  char *w;
  char *m;
  bool q;
} Word;

typedef enum nodetype {
	nAndalso, 
  nAssign, 
  nBackq, 
  nBang, 
  nBody, 
  nCbody, 
  nNowait, 
  nBrace,
	nConcat, 
  nCount, 
  nElse, 
  nFlat, 
  nDup, 
  nEpilog, 
  nNewfn, 
  nForin, 
  nIf,
	nOrelse, 
  nPipe, 
  nPre, 
  nRedir, 
  nRmfn, 
  nArgs, 
  nSubshell, 
  nCase,
	nSwitch, 
  nMatch, 
  nVar, 
  nVarsub, 
  nWhile, 
  nWord, 
  nLappend, 
  nNmpipe
} nodetype;

typedef struct Node {
	nodetype type;
	union {
		char *s;
		int i;
		struct Node *p;
	} u[4];
} Node;

typedef struct Pipe {
	int left;
  int right;
} Pipe;

extern Node *parsetree;
extern int yyparse(void);
extern void initparse(void);

#endif /* SRC_LANG_H__ */
