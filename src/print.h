#ifndef SRC_PRINT_H__
#define SRC_PRINT_H__

// Format->flags values
enum {
  FMT_quad = 1,       /* %q */
  FMT_long = 2,       /* %l */
  FMT_unsigned = 8,   /* %u */
  FMT_zeropad = 16,   /* %0 */
  FMT_leftside = 32,  /* %- */
  FMT_altform = 64,   /* %# */
  FMT_f1set = 128,    /* %<n> */
  FMT_f2set = 256,    /* %.<n> */
};

typedef struct Format {
  // For the formatting routines.
  va_list args;
  long flags;
  long f1;
  long f2;

  // For the buffer maintenance routines.
  char *buf;
  char *bufbegin;
  char *bufend;
  int flushed;
  void (*grow)(struct Format *, size_t);
  union {
    int n;
    void *p;
  } u;
} Format;

typedef bool (*Conv)(Format *, int);

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
