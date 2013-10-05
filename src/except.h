#ifndef SRC_EXCEPT_H__
#define SRC_EXCEPT_H__

extern bool nl_on_intr;
extern bool outstanding_cmdarg(void);
extern void pop_cmdarg(bool);
extern void rc_raise(ecodes);
extern void except(ecodes, Edata, Estack *);
extern void unexcept(void);
extern void rc_error(char *);
extern void sigint(int);

#endif /* SRC_EXCEPT_H__ */
