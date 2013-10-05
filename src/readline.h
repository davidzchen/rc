#ifndef SRC_READLINE_H__
#define SRC_READLINE_H__

#if READLINE

/* Including the real readline .h files is too complicated, so we just
declare what we actually use. */

extern void add_history(char *);
extern char *readline(char *);
extern int rl_clear_signals(void);
extern int rl_pending_input;
extern int rl_reset_terminal(char *);

#if READLINE_OLD
extern void rl_clean_up_for_exit(void);
extern void rl_deprep_terminal(void);
#else
extern void _rl_clean_up_for_exit(void);
extern void (*rl_deprep_term_function)(void);
#endif

extern char *rc_readline(char *);

extern volatile sig_atomic_t rl_active;
extern struct Jbwrap rl_buf;
#endif

#if EDITLINE
extern char *readline(char *);
extern void add_history(char *);
#define rc_readline readline
#endif

#endif /* SRC_READLINE_H__ */
