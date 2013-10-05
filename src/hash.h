#ifndef SRC_HASH_H__
#define SRC_HASH_H__

extern Htab *fp, *vp;
extern void *lookup(char *, Htab *);
extern rc_Function *get_fn_place(char *);
extern List *varlookup(char *);
extern Node *fnlookup(char *);
extern Variable *get_var_place(char *, bool);
extern bool varassign_string(char *);
extern char **makeenv(void);
extern char *fnlookup_string(char *);
extern char *varlookup_string(char *);
extern void alias(char *, List *, bool);
extern void starassign(char *, char **, bool);
extern void delete_fn(char *);
extern void delete_var(char *, bool);
extern void fnassign(char *, Node *);
extern void fnassign_string(char *);
extern void fnrm(char *);
extern void initenv(char **);
extern void inithash(void);
extern void set_exportable(char *, bool);
extern void setsigdefaults(bool);
extern void inithandler(void);
extern void varassign(char *, List *, bool);
extern void varrm(char *, bool);
extern void whatare_all_vars(bool, bool);
extern void whatare_all_signals(void);
extern void prettyprint_var(int, char *, List *);
extern void prettyprint_fn(int, char *, Node *);

#endif /* SRC_HASH_H__ */
