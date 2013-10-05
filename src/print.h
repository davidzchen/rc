#ifndef SRC_PRINT_H__
#define SRC_PRINT_H__

/*
   The following prototype should be:
extern Conv fmtinstall(int, Conv);
   but this freaks out SGI's compiler under IRIX3.3.2
*/
extern bool (*fmtinstall(int, bool (*)(Format *, int)))(Format *, int);
extern int printfmt(Format *, const char *);
extern int fmtprint(Format *, const char *,...);
extern void fmtappend(Format *, const char *, size_t);
extern void fmtcat(Format *, const char *);
extern int fprint(int fd, const char *fmt,...);
extern char *mprint(const char *fmt,...);
extern char *nprint(const char *fmt,...);
/*
   the following macro should by rights be coded as an expression, not
   a statement, but certain compilers (notably DEC) have trouble with
   void expressions inside the ?: operator. (sheesh, give me a break!)
*/
#define	fmtputc(f, c) {\
	if ((f)->buf >= (f)->bufend)\
		(*(f)->grow)((f), (size_t)1);\
	*(f)->buf++ = (c);\
}

#endif /* SRC_PRINT_H__ */
