typedef unsigned int size_t;
# 325 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 3 4
typedef long int wchar_t;
# 34 "/usr/include/stdlib.h" 2 3 4


# 96 "/usr/include/stdlib.h" 3 4

typedef int _Bool;


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;



# 140 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) ;




extern double atof ( char *__nptr);

extern int atoi ( char *__nptr);

extern long int atol ( char *__nptr);

extern long long int atoll ( char *__nptr);

extern double strtod ( char *__restrict __nptr,
        char **__restrict __endptr) ;

# 181 "/usr/include/stdlib.h" 3 4


extern long int strtol ( char *__restrict __nptr,
   char **__restrict __endptr, int __base);

extern unsigned long int strtoul ( char *__restrict __nptr,
      char **__restrict __endptr, int __base);




extern long long int strtoq ( char *__restrict __nptr,
        char **__restrict __endptr, int __base) ;
extern unsigned long long int strtouq ( char *__restrict __nptr,
           char **__restrict __endptr, int __base);





extern long long int strtoll ( char *__restrict __nptr,
         char **__restrict __endptr, int __base);


extern unsigned long long int strtoull ( char *__restrict __nptr,
     char **__restrict __endptr, int __base);

# 277 "/usr/include/stdlib.h" 3 4
extern double __strtod_internal ( char *__restrict __nptr,
     char **__restrict __endptr, int __group);

extern float __strtof_internal ( char *__restrict __nptr,
    char **__restrict __endptr, int __group)
     ;
extern long double __strtold_internal ( char *__restrict __nptr,
           char **__restrict __endptr,
           int __group) ;

extern long int __strtol_internal ( char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group)
     ;



extern unsigned long int __strtoul_internal ( char *__restrict __nptr,
          char **__restrict __endptr,
          int __base, int __group)
     ;





extern long long int __strtoll_internal ( char *__restrict __nptr,
      char **__restrict __endptr,
      int __base, int __group)
     ;




extern unsigned long long int __strtoull_internal ( char *
         __restrict __nptr,
         char **__restrict __endptr,
         int __base, int __group)
     ;
# 424 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n);


extern long int a64l ( char *__s)
     ;




# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4


# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 32 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




 typedef signed long long int __int64_t;
 typedef unsigned long long int __uint64_t;







 typedef long long int __quad_t;
 typedef unsigned long long int __u_quad_t;
# 129 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 130 "/usr/include/bits/types.h" 2 3 4






 typedef __u_quad_t __dev_t;
 typedef unsigned int __uid_t;
 typedef unsigned int __gid_t;
 typedef unsigned long int __ino_t;
 typedef __u_quad_t __ino64_t;
 typedef unsigned int __mode_t;
 typedef unsigned int __nlink_t;
 typedef long int __off_t;
 typedef __quad_t __off64_t;
 typedef int __pid_t;
 typedef struct { int __val[2]; } __fsid_t;
 typedef long int __clock_t;
 typedef unsigned long int __rlim_t;
 typedef __u_quad_t __rlim64_t;
 typedef unsigned int __id_t;
 typedef long int __time_t;
 typedef unsigned int __useconds_t;
 typedef long int __suseconds_t;

 typedef int __daddr_t;
 typedef long int __swblk_t;
 typedef int __key_t;


 typedef int __clockid_t;


 typedef int __timer_t;


 typedef long int __blksize_t;




 typedef long int __blkcnt_t;
 typedef __quad_t __blkcnt64_t;


 typedef unsigned long int __fsblkcnt_t;
 typedef __u_quad_t __fsblkcnt64_t;


 typedef unsigned long int __fsfilcnt_t;
 typedef __u_quad_t __fsfilcnt64_t;

 typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


 typedef int __intptr_t;


 typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 62 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 100 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4
# 147 "/usr/include/sys/types.h" 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 148 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 191 "/usr/include/sys/types.h" 3 4
typedef int int8_t ;
typedef int int16_t ;
typedef int int32_t ;
typedef int int64_t ;


typedef unsigned int u_int8_t ;
typedef unsigned int u_int16_t ;
typedef unsigned int u_int32_t ;
typedef unsigned int u_int64_t ;

typedef int register_t ;
# 213 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 214 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 23 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 118 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4

# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 128 "/usr/include/sys/select.h" 3 4

# 217 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 29 "/usr/include/sys/sysmacros.h" 3 4

extern  unsigned int gnu_dev_major (unsigned long long int __dev)
    ;

extern  unsigned int gnu_dev_minor (unsigned long long int __dev)
    ;

extern  unsigned long long int gnu_dev_makedev (unsigned int __major,
       unsigned int __minor)
    ;


 extern  unsigned int
gnu_dev_major (unsigned long long int __dev)
{
  return ((__dev >> 8) & 0xfff) | ((unsigned int) (__dev >> 32) & ~0xfff);
}

 extern  unsigned int
gnu_dev_minor (unsigned long long int __dev)
{
  return (__dev & 0xff) | ((unsigned int) (__dev >> 12) & ~0xff);
}

 extern  unsigned long long int
gnu_dev_makedev (unsigned int __major, unsigned int __minor)
{
  return ((__minor & 0xff) | ((__major & 0xfff) << 8)
   | (((unsigned long long int) (__minor & ~0xff)) << 12)
   | (((unsigned long long int) (__major & ~0xfff)) << 32));
}
# 220 "/usr/include/sys/types.h" 2 3 4
# 231 "/usr/include/sys/types.h" 3 4
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 266 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/sched.h" 1 3 4
# 83 "/usr/include/bits/sched.h" 3 4
struct __sched_param
  {
    int __sched_priority;
  };
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4


struct _pthread_fastlock
{
  long int __status;
  int __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;





 typedef long long __pthread_cond_align_t;




typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
  char __padding[48 - sizeof (struct _pthread_fastlock)
   - sizeof (_pthread_descr) - sizeof (__pthread_cond_align_t)];
  __pthread_cond_align_t __align;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;
# 150 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;
# 267 "/usr/include/sys/types.h" 2 3 4



# 434 "/usr/include/stdlib.h" 2 3 4






extern long int random (void);


extern void srandom (unsigned int __seed);





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) ;



extern char *setstate (char *__statebuf) ;







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     ;

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     ;

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     ;






extern int rand (void);

extern void srand (unsigned int __seed);




extern int rand_r (unsigned int *__seed);







extern double drand48 (void);
extern double erand48 (unsigned short int __xsubi[3]) ;


extern long int lrand48 (void);
extern long int nrand48 (unsigned short int __xsubi[3])
     ;


extern long int mrand48 (void);
extern long int jrand48 (unsigned short int __xsubi[3])
     ;


extern void srand48 (long int __seedval);
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     ;
extern void lcong48 (unsigned short int __param[7]) ;





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) ;


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     ;
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     ;


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     ;
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     ;


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     ;

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) ;

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     ;









extern void *malloc (size_t __size) ;

extern void *calloc (size_t __nmemb, size_t __size)
     ;







extern void *realloc (void *__ptr, size_t __size) ;

extern void free (void *__ptr);




extern void cfree (void *__ptr);



# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size);






# 607 "/usr/include/stdlib.h" 2 3 4




extern void *valloc (size_t __size) ;
# 620 "/usr/include/stdlib.h" 3 4


extern void abort (void) ;



extern int atexit (void (*__func) (void)) ;





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     ;






extern void exit (int __status) ;

# 652 "/usr/include/stdlib.h" 3 4


extern char *getenv ( char *__name) ;




extern char *__secure_getenv ( char *__name) ;





extern int putenv (char *__string) ;





extern int setenv ( char *__name,  char *__value, int __replace)
     ;


extern int unsetenv ( char *__name) ;






extern int clearenv (void);
# 691 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) ;
# 702 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) ;
# 721 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) ;








extern int system ( char *__command);

# 749 "/usr/include/stdlib.h" 3 4
extern char *realpath ( char *__restrict __name,
         char *__restrict __resolved) ;






typedef int (*__compar_fn_t) ( void *,  void *);









extern void *bsearch ( void *__key,  void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     ;



extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) ;



extern int abs (int __x) ;
extern long int labs (long int __x) ;












extern div_t div (int __numer, int __denom)
     ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     ;

# 814 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) ;

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     ;
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     ;







extern int mblen ( char *__s, size_t __n);


extern int mbtowc (wchar_t *__restrict __pwc,
      char *__restrict __s, size_t __n);


extern int wctomb (char *__s, wchar_t __wchar);



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
    char *__restrict __s, size_t __n);

extern size_t wcstombs (char *__restrict __s,
    wchar_t *__restrict __pwcs, size_t __n)
    ;








extern int rpmatch ( char *__response) ;
# 954 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     ;






# 119 "./test.priv.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4




extern void *memcpy (void *__restrict __dest,
        void *__restrict __src, size_t __n)
     ;


extern void *memmove (void *__dest,  void *__src, size_t __n)
     ;






extern void *memccpy (void *__restrict __dest,  void *__restrict __src,
        int __c, size_t __n)
     ;





extern void *memset (void *__s, int __c, size_t __n) ;


extern int memcmp ( void *__s1,  void *__s2, size_t __n)
     ;


extern void *memchr ( void *__s, int __c, size_t __n)
      ;

# 82 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest,  char *__restrict __src)
     ;

extern char *strncpy (char *__restrict __dest,
         char *__restrict __src, size_t __n)
     ;


extern char *strcat (char *__restrict __dest,  char *__restrict __src)
     ;

extern char *strncat (char *__restrict __dest,  char *__restrict __src,
        size_t __n) ;


extern int strcmp ( char *__s1,  char *__s2)
     ;

extern int strncmp ( char *__s1,  char *__s2, size_t __n)
     ;


extern int strcoll ( char *__s1,  char *__s2)
     ;

extern size_t strxfrm (char *__restrict __dest,
          char *__restrict __src, size_t __n)
     ;

# 130 "/usr/include/string.h" 3 4
extern char *strdup ( char *__s)
     ;
# 165 "/usr/include/string.h" 3 4


extern char *strchr ( char *__s, int __c)
     ;

extern char *strrchr ( char *__s, int __c)
     ;

# 181 "/usr/include/string.h" 3 4



extern size_t strcspn ( char *__s,  char *__reject)
     ;


extern size_t strspn ( char *__s,  char *__accept)
     ;

extern char *strpbrk ( char *__s,  char *__accept)
     ;

extern char *strstr ( char *__haystack,  char *__needle)
     ;



extern char *strtok (char *__restrict __s,  char *__restrict __delim)
     ;




extern char *__strtok_r (char *__restrict __s,
     char *__restrict __delim,
    char **__restrict __save_ptr)
     ;

extern char *strtok_r (char *__restrict __s,  char *__restrict __delim,
         char **__restrict __save_ptr)
     ;
# 240 "/usr/include/string.h" 3 4


extern size_t strlen ( char *__s)
     ;

# 254 "/usr/include/string.h" 3 4


extern char *strerror (int __errnum);

# 281 "/usr/include/string.h" 3 4
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     ;





extern void __bzero (void *__s, size_t __n) ;



extern void bcopy ( void *__src, void *__dest, size_t __n)
     ;


extern void bzero (void *__s, size_t __n) ;


extern int bcmp ( void *__s1,  void *__s2, size_t __n)
     ;


extern char *index ( char *__s, int __c)
     ;


extern char *rindex ( char *__s, int __c)
     ;



extern int ffs (int __i) ;
# 325 "/usr/include/string.h" 3 4
extern int strcasecmp ( char *__s1,  char *__s2)
     ;


extern int strncasecmp ( char *__s1,  char *__s2, size_t __n)
     ;
# 348 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
        char *__restrict __delim)
     ;
# 426 "/usr/include/string.h" 3 4

# 120 "./test.priv.h" 2






# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 103 "/usr/include/bits/sigset.h" 3 4
extern int __sigismember ( __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 34 "/usr/include/signal.h" 2 3 4







typedef __sig_atomic_t sig_atomic_t;

# 58 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/signum.h" 1 3 4
# 59 "/usr/include/signal.h" 2 3 4
# 75 "/usr/include/signal.h" 3 4
typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
    ;
# 90 "/usr/include/signal.h" 3 4


extern __sighandler_t signal (int __sig, __sighandler_t __handler);
# 103 "/usr/include/signal.h" 3 4

# 115 "/usr/include/signal.h" 3 4
extern int kill (__pid_t __pid, int __sig);






extern int killpg (__pid_t __pgrp, int __sig);




extern int raise (int __sig);




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler);
extern int gsignal (int __sig);




extern void psignal (int __sig,  char *__s);
# 150 "/usr/include/signal.h" 3 4
extern int __sigpause (int __sig_or_mask, int __is_sig);
# 179 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask);


extern int sigsetmask (int __mask);


extern int siggetmask (void);
# 199 "/usr/include/signal.h" 3 4
typedef __sighandler_t sig_t;







# 1 "/usr/include/time.h" 1 3 4
# 208 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4







typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
# 51 "/usr/include/bits/siginfo.h" 3 4
typedef struct siginfo
  {
    int si_signo;
    int si_errno;

    int si_code;

    union
      {
 int _pad[((128 / sizeof (int)) - 3)];


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;


 struct
   {
     int si_tid;
     int si_overrun;
     sigval_t si_sigval;
   } _timer;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     sigval_t si_sigval;
   } _rt;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;


 struct
   {
     void *si_addr;
   } _sigfault;


 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
      } _sifields;
  } siginfo_t;
# 129 "/usr/include/bits/siginfo.h" 3 4
enum
{
  SI_ASYNCNL = -60,

  SI_TKILL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};



enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};


enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE

};


enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 273 "/usr/include/bits/siginfo.h" 3 4
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
 int _pad[((64 / sizeof (int)) - 3)];



 __pid_t _tid;

 struct
   {
     void (*_function) (sigval_t);
     void *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;






enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4

};
# 211 "/usr/include/signal.h" 2 3 4



extern int sigemptyset (sigset_t *__set);


extern int sigfillset (sigset_t *__set);


extern int sigaddset (sigset_t *__set, int __signo);


extern int sigdelset (sigset_t *__set, int __signo);


extern int sigismember ( sigset_t *__set, int __signo);
# 243 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigaction.h" 1 3 4
# 25 "/usr/include/bits/sigaction.h" 3 4
struct sigaction
  {


    union
      {

 __sighandler_t sa_handler;

 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };
# 244 "/usr/include/signal.h" 2 3 4


extern int sigprocmask (int __how,  sigset_t *__restrict __set,
   sigset_t *__restrict __oset);






extern int sigsuspend ( sigset_t *__set);


extern int sigaction (int __sig,  struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact);


extern int sigpending (sigset_t *__set);






extern int sigwait ( sigset_t *__restrict __set, int *__restrict __sig);






extern int sigwaitinfo ( sigset_t *__restrict __set,
   siginfo_t *__restrict __info);






extern int sigtimedwait ( sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
     struct timespec *__restrict __timeout);



extern int sigqueue (__pid_t __pid, int __sig,  union sigval __val)
    ;
# 299 "/usr/include/signal.h" 3 4
extern  char * _sys_siglist[65];
extern  char * sys_siglist[65];


struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;

    int sv_flags;

  };
# 323 "/usr/include/signal.h" 3 4
extern int sigvec (int __sig,  struct sigvec *__vec,
     struct sigvec *__ovec);



# 1 "/usr/include/bits/sigcontext.h" 1 3 4
# 28 "/usr/include/bits/sigcontext.h" 3 4
# 1 "/usr/include/asm/sigcontext.h" 1 3 4
# 18 "/usr/include/asm/sigcontext.h" 3 4
struct _fpreg {
 unsigned short significand[4];
 unsigned short exponent;
};

struct _fpxreg {
 unsigned short significand[4];
 unsigned short exponent;
 unsigned short padding[3];
};

struct _xmmreg {
 unsigned long element[4];
};

struct _fpstate {

 unsigned long cw;
 unsigned long sw;
 unsigned long tag;
 unsigned long ipoff;
 unsigned long cssel;
 unsigned long dataoff;
 unsigned long datasel;
 struct _fpreg _st[8];
 unsigned short status;
 unsigned short magic;


 unsigned long _fxsr_env[6];
 unsigned long mxcsr;
 unsigned long reserved;
 struct _fpxreg _fxsr_st[8];
 struct _xmmreg _xmm[8];
 unsigned long padding[56];
};



struct sigcontext {
 unsigned short gs, __gsh;
 unsigned short fs, __fsh;
 unsigned short es, __esh;
 unsigned short ds, __dsh;
 unsigned long edi;
 unsigned long esi;
 unsigned long ebp;
 unsigned long esp;
 unsigned long ebx;
 unsigned long edx;
 unsigned long ecx;
 unsigned long eax;
 unsigned long trapno;
 unsigned long err;
 unsigned long eip;
 unsigned short cs, __csh;
 unsigned long eflags;
 unsigned long esp_at_signal;
 unsigned short ss, __ssh;
 struct _fpstate * fpstate;
 unsigned long oldmask;
 unsigned long cr2;
};
# 29 "/usr/include/bits/sigcontext.h" 2 3 4
# 329 "/usr/include/signal.h" 2 3 4


extern int sigreturn (struct sigcontext *__scp);
# 341 "/usr/include/signal.h" 3 4
extern int siginterrupt (int __sig, int __interrupt);

# 1 "/usr/include/bits/sigstack.h" 1 3 4
# 26 "/usr/include/bits/sigstack.h" 3 4
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };



enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};
# 50 "/usr/include/bits/sigstack.h" 3 4
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 344 "/usr/include/signal.h" 2 3 4
# 352 "/usr/include/signal.h" 3 4
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss);



extern int sigaltstack ( struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss);
# 380 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 381 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
        __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask);


extern int pthread_kill (pthread_t __threadid, int __signo);
# 382 "/usr/include/signal.h" 2 3 4






extern int __libc_current_sigrtmin (void);

extern int __libc_current_sigrtmax (void);




# 127 "./test.priv.h" 2
# 135 "./test.priv.h"
# 1 "/usr/include/curses.h" 1 3 4
# 58 "/usr/include/curses.h" 3 4
# 1 "/usr/include/ncurses/ncurses_dll.h" 1 3 4
# 59 "/usr/include/curses.h" 2 3 4
# 106 "/usr/include/curses.h" 3 4
typedef unsigned long chtype;

# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4


typedef struct _IO_FILE FILE;





# 62 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 72 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 14 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 354 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 15 "/usr/include/_G_config.h" 2 3 4
# 24 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 51 "/usr/include/wchar.h" 2 3 4
# 76 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 25 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 44 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/gconv.h" 1 3 4
# 28 "/usr/include/gconv.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4
# 29 "/usr/include/gconv.h" 2 3 4


# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h" 1 3 4
# 32 "/usr/include/gconv.h" 2 3 4





enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
        unsigned char **,  unsigned char *,
       unsigned char **, size_t *, int, int);


typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
      struct __gconv_step_data *, void *,
       unsigned char *,
       unsigned char **,
       unsigned char *, unsigned char **,
      size_t *);


typedef int (*__gconv_trans_context_fct) (void *,  unsigned char *,
        unsigned char *,
       unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) ( char *,  char ***,
     size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
   char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
   struct __gconv_step_data __data [];
} *__gconv_t;
# 45 "/usr/include/_G_config.h" 2 3 4
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t ;
typedef int _G_int32_t ;
typedef unsigned int _G_uint16_t ;
typedef unsigned int _G_uint32_t ;
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h" 1 3 4
# 43 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h" 3 4
typedef int __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 166 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 176 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 199 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 267 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 315 "/usr/include/libio.h" 3 4
  __off64_t _offset;





  void *__pad1;
  void *__pad2;

  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 354 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie,  char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 406 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern wint_t __wunderflow (_IO_FILE *);
extern wint_t __wuflow (_IO_FILE *);
extern wint_t __woverflow (_IO_FILE *, wint_t);
# 444 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp);
extern int _IO_ferror (_IO_FILE *__fp);

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *);
extern void _IO_funlockfile (_IO_FILE *);
extern int _IO_ftrylockfile (_IO_FILE *);
# 474 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *);
# 73 "/usr/include/stdio.h" 2 3 4
# 86 "/usr/include/stdio.h" 3 4


typedef _G_fpos_t fpos_t;




# 138 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 139 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;









extern int remove ( char *__filename);

extern int rename ( char *__old,  char *__new);









extern FILE *tmpfile (void);
# 180 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s);





extern char *tmpnam_r (char *__s);
# 198 "/usr/include/stdio.h" 3 4
extern char *tempnam ( char *__dir,  char *__pfx)
     ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 223 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 237 "/usr/include/stdio.h" 3 4






extern FILE *fopen ( char *__restrict __filename,
       char *__restrict __modes);




extern FILE *freopen ( char *__restrict __filename,
         char *__restrict __modes,
        FILE *__restrict __stream);
# 264 "/usr/include/stdio.h" 3 4

# 275 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd,  char *__modes);
# 296 "/usr/include/stdio.h" 3 4



extern void setbuf (FILE *__restrict __stream, char *__restrict __buf);



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n);





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size);


extern void setlinebuf (FILE *__stream);








extern int fprintf (FILE *__restrict __stream,
       char *__restrict __format, ...);




extern int printf ( char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
       char *__restrict __format, ...);





extern int vfprintf (FILE *__restrict __s,  char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf ( char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s,  char *__restrict __format,
       __gnuc_va_list __arg);





extern int snprintf (char *__restrict __s, size_t __maxlen,
        char *__restrict __format, ...)
     ;

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
         char *__restrict __format, __gnuc_va_list __arg)
     ;

# 390 "/usr/include/stdio.h" 3 4





extern int fscanf (FILE *__restrict __stream,
      char *__restrict __format, ...);




extern int scanf ( char *__restrict __format, ...);

extern int sscanf ( char *__restrict __s,
      char *__restrict __format, ...);

# 432 "/usr/include/stdio.h" 3 4





extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 456 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 467 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 500 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream);






extern char *gets (char *__s);

# 580 "/usr/include/stdio.h" 3 4





extern int fputs ( char *__restrict __s, FILE *__restrict __stream);





extern int puts ( char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream);




extern size_t fwrite ( void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 633 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream);
extern size_t fwrite_unlocked ( void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream);




extern void rewind (FILE *__stream);

# 688 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream,  fpos_t *__pos);
# 711 "/usr/include/stdio.h" 3 4

# 720 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream);

extern int feof (FILE *__stream);

extern int ferror (FILE *__stream);




extern void clearerr_unlocked (FILE *__stream);
extern int feof_unlocked (FILE *__stream);
extern int ferror_unlocked (FILE *__stream);








extern void perror ( char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern  char * sys_errlist[];
# 750 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream);




extern int fileno_unlocked (FILE *__stream);
# 769 "/usr/include/stdio.h" 3 4
extern FILE *popen ( char *__command,  char *__modes);





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s);
# 809 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream);



extern int ftrylockfile (FILE *__stream);


extern void funlockfile (FILE *__stream);
# 836 "/usr/include/stdio.h" 3 4

# 109 "/usr/include/curses.h" 2 3 4
# 1 "/usr/include/ncurses/unctrl.h" 1 3 4
# 54 "/usr/include/ncurses/unctrl.h" 3 4
# 1 "/usr/include/ncurses/curses.h" 1 3 4
# 55 "/usr/include/ncurses/unctrl.h" 2 3 4


 char * unctrl (chtype);
# 110 "/usr/include/curses.h" 2 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h" 1 3 4
# 105 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 111 "/usr/include/curses.h" 2 3 4
# 133 "/usr/include/curses.h" 3 4
typedef unsigned char NCURSES_BOOL;
# 143 "/usr/include/curses.h" 3 4
# 1 "/usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdbool.h" 1 3 4
# 144 "/usr/include/curses.h" 2 3 4
# 181 "/usr/include/curses.h" 3 4
extern int COLORS;
extern int COLOR_PAIRS;
# 199 "/usr/include/curses.h" 3 4
extern chtype acs_map[];
# 289 "/usr/include/curses.h" 3 4
typedef struct screen SCREEN;
typedef struct _win_st WINDOW;

typedef chtype attr_t;
# 325 "/usr/include/curses.h" 3 4
struct ldat;

struct _win_st
{
 short _cury, _curx;


 short _maxy, _maxx;
 short _begy, _begx;

 short _flags;


 attr_t _attrs;
 chtype _bkgd;


 _Bool _notimeout;
 _Bool _clear;
 _Bool _leaveok;
 _Bool _scroll;
 _Bool _idlok;
 _Bool _idcok;
 _Bool _immed;
 _Bool _sync;
 _Bool _use_keypad;
 int _delay;

 struct ldat *_line;


 short _regtop;
 short _regbottom;


 int _parx;
 int _pary;
 WINDOW *_parent;


 struct pdat
 {
     short _pad_y, _pad_x;
     short _pad_top, _pad_left;
     short _pad_bottom, _pad_right;
 } _pad;

 short _yoffset;




};

extern WINDOW * stdscr;
extern WINDOW * curscr;
extern WINDOW * newscr;

extern int LINES;
extern int COLS;
extern int TABSIZE;




extern int ESCDELAY;

extern char ttytype[];





extern _Bool is_term_resized (int, int);
extern char * keybound (int, int);
extern const char * curses_version (void);
extern int assume_default_colors (int, int);
extern int define_key (const char *, int);
extern int key_defined (const char *);
extern int keyok (int, _Bool);
extern int resize_term (int, int);
extern int resizeterm (int, int);
extern int use_default_colors (void);
extern int use_extended_names (_Bool);
extern int wresize (WINDOW *, int, int);
# 508 "/usr/include/curses.h" 3 4
extern int addch (const chtype);
extern int addchnstr (const chtype *, int);
extern int addchstr (const chtype *);
extern int addnstr (const char *, int);
extern int addstr (const char *);
extern int attroff (attr_t);
extern int attron (attr_t);
extern int attrset (attr_t);
extern int attr_get (attr_t *, short *, void *);
extern int attr_off (attr_t, void *);
extern int attr_on (attr_t, void *);
extern int attr_set (attr_t, short, void *);
extern int baudrate (void);
extern int beep (void);
extern int bkgd (chtype);
extern void bkgdset (chtype);
extern int border (chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);
extern int box (WINDOW *, chtype, chtype);
extern _Bool can_change_color (void);
extern int cbreak (void);
extern int chgat (int, attr_t, short, const void *);
extern int clear (void);
extern int clearok (WINDOW *,_Bool);
extern int clrtobot (void);
extern int clrtoeol (void);
extern int color_content (short,short*,short*,short*);
extern int color_set (short,void*);
extern int COLOR_PAIR (int);
extern int copywin (const WINDOW*,WINDOW*,int,int,int,int,int,int,int);
extern int curs_set (int);
extern int def_prog_mode (void);
extern int def_shell_mode (void);
extern int delay_output (int);
extern int delch (void);
extern void delscreen (SCREEN *);
extern int delwin (WINDOW *);
extern int deleteln (void);
extern WINDOW * derwin (WINDOW *,int,int,int,int);
extern int doupdate (void);
extern WINDOW * dupwin (WINDOW *);
extern int echo (void);
extern int echochar (const chtype);
extern int erase (void);
extern int endwin (void);
extern char erasechar (void);
extern void filter (void);
extern int flash (void);
extern int flushinp (void);
extern chtype getbkgd (WINDOW *);
extern int getch (void);
extern int getnstr (char *, int);
extern int getstr (char *);
extern WINDOW * getwin (FILE *);
extern int halfdelay (int);
extern _Bool has_colors (void);
extern _Bool has_ic (void);
extern _Bool has_il (void);
extern int hline (chtype, int);
extern void idcok (WINDOW *, _Bool);
extern int idlok (WINDOW *, _Bool);
extern void immedok (WINDOW *, _Bool);
extern chtype inch (void);
extern int inchnstr (chtype *, int);
extern int inchstr (chtype *);
extern WINDOW * initscr (void);
extern int init_color (short,short,short,short);
extern int init_pair (short,short,short);
extern int innstr (char *, int);
extern int insch (chtype);
extern int insdelln (int);
extern int insertln (void);
extern int insnstr (const char *, int);
extern int insstr (const char *);
extern int instr (char *);
extern int intrflush (WINDOW *,_Bool);
extern _Bool isendwin (void);
extern _Bool is_linetouched (WINDOW *,int);
extern _Bool is_wintouched (WINDOW *);
extern char * keyname (int);
extern int keypad (WINDOW *,_Bool);
extern char killchar (void);
extern int leaveok (WINDOW *,_Bool);
extern char * longname (void);
extern int meta (WINDOW *,_Bool);
extern int move (int, int);
extern int mvaddch (int, int, const chtype);
extern int mvaddchnstr (int, int, const chtype *, int);
extern int mvaddchstr (int, int, const chtype *);
extern int mvaddnstr (int, int, const char *, int);
extern int mvaddstr (int, int, const char *);
extern int mvchgat (int, int, int, attr_t, short, const void *);
extern int mvcur (int,int,int,int);
extern int mvdelch (int, int);
extern int mvderwin (WINDOW *, int, int);
extern int mvgetch (int, int);
extern int mvgetnstr (int, int, char *, int);
extern int mvgetstr (int, int, char *);
extern int mvhline (int, int, chtype, int);
extern chtype mvinch (int, int);
extern int mvinchnstr (int, int, chtype *, int);
extern int mvinchstr (int, int, chtype *);
extern int mvinnstr (int, int, char *, int);
extern int mvinsch (int, int, chtype);
extern int mvinsnstr (int, int, const char *, int);
extern int mvinsstr (int, int, const char *);
extern int mvinstr (int, int, char *);
extern int mvprintw (int,int, const char *,...)
  ;
extern int mvscanw (int,int, char *,...)
  ;
extern int mvvline (int, int, chtype, int);
extern int mvwaddch (WINDOW *, int, int, const chtype);
extern int mvwaddchnstr (WINDOW *, int, int, const chtype *, int);
extern int mvwaddchstr (WINDOW *, int, int, const chtype *);
extern int mvwaddnstr (WINDOW *, int, int, const char *, int);
extern int mvwaddstr (WINDOW *, int, int, const char *);
extern int mvwchgat (WINDOW *, int, int, int, attr_t, short, const void *);
extern int mvwdelch (WINDOW *, int, int);
extern int mvwgetch (WINDOW *, int, int);
extern int mvwgetnstr (WINDOW *, int, int, char *, int);
extern int mvwgetstr (WINDOW *, int, int, char *);
extern int mvwhline (WINDOW *, int, int, chtype, int);
extern int mvwin (WINDOW *,int,int);
extern chtype mvwinch (WINDOW *, int, int);
extern int mvwinchnstr (WINDOW *, int, int, chtype *, int);
extern int mvwinchstr (WINDOW *, int, int, chtype *);
extern int mvwinnstr (WINDOW *, int, int, char *, int);
extern int mvwinsch (WINDOW *, int, int, chtype);
extern int mvwinsnstr (WINDOW *, int, int, const char *, int);
extern int mvwinsstr (WINDOW *, int, int, const char *);
extern int mvwinstr (WINDOW *, int, int, char *);
extern int mvwprintw (WINDOW*,int,int, const char *,...)
  ;
extern int mvwscanw (WINDOW *,int,int, char *,...)
  ;
extern int mvwvline (WINDOW *,int, int, chtype, int);
extern int napms (int);
extern WINDOW * newpad (int,int);
extern SCREEN * newterm ( char *,FILE *,FILE *);
extern WINDOW * newwin (int,int,int,int);
extern int nl (void);
extern int nocbreak (void);
extern int nodelay (WINDOW *,_Bool);
extern int noecho (void);
extern int nonl (void);
extern void noqiflush (void);
extern int noraw (void);
extern int notimeout (WINDOW *,_Bool);
extern int overlay (const WINDOW*,WINDOW *);
extern int overwrite (const WINDOW*,WINDOW *);
extern int pair_content (short,short*,short*);
extern int PAIR_NUMBER (int);
extern int pechochar (WINDOW *, const chtype);
extern int pnoutrefresh (WINDOW*,int,int,int,int,int,int);
extern int prefresh (WINDOW *,int,int,int,int,int,int);
extern int printw (const char *,...)
  ;
extern int putp (const char *);
extern int putwin (WINDOW *, FILE *);
extern void qiflush (void);
extern int raw (void);
extern int redrawwin (WINDOW *);
extern int refresh (void);
extern int resetty (void);
extern int reset_prog_mode (void);
extern int reset_shell_mode (void);
extern int ripoffline (int, int (*)(WINDOW *, int));
extern int savetty (void);
extern int scanw ( char *,...)
  ;
extern int scr_dump (const char *);
extern int scr_init (const char *);
extern int scrl (int);
extern int scroll (WINDOW *);
extern int scrollok (WINDOW *,_Bool);
extern int scr_restore (const char *);
extern int scr_set (const char *);
extern int setscrreg (int,int);
extern SCREEN * set_term (SCREEN *);
extern int slk_attroff (const chtype);
extern int slk_attr_off (const attr_t, void *);
extern int slk_attron (const chtype);
extern int slk_attr_on (attr_t,void*);
extern int slk_attrset (const chtype);
extern attr_t slk_attr (void);
extern int slk_attr_set (const attr_t,short,void*);
extern int slk_clear (void);
extern int slk_color (short);
extern int slk_init (int);
extern char * slk_label (int);
extern int slk_noutrefresh (void);
extern int slk_refresh (void);
extern int slk_restore (void);
extern int slk_set (int,const char *,int);
extern int slk_touch (void);
extern int standout (void);
extern int standend (void);
extern int start_color (void);
extern WINDOW * subpad (WINDOW *, int, int, int, int);
extern WINDOW * subwin (WINDOW *,int,int,int,int);
extern int syncok (WINDOW *, _Bool);
extern chtype termattrs (void);
extern char * termname (void);
extern int tigetflag ( char *);
extern int tigetnum ( char *);
extern char * tigetstr ( char *);
extern void timeout (int);
extern int touchline (WINDOW *, int, int);
extern int touchwin (WINDOW *);
extern char * tparm ( char *, ...);
extern int typeahead (int);
extern int ungetch (int);
extern int untouchwin (WINDOW *);
extern void use_env (_Bool);
extern int vidattr (chtype);
extern int vidputs (chtype, int (*)(int));
extern int vline (chtype, int);
extern int vwprintw (WINDOW *, const char *,va_list);
extern int vw_printw (WINDOW *, const char *,va_list);
extern int vwscanw (WINDOW *, char *,va_list);
extern int vw_scanw (WINDOW *, char *,va_list);
extern int waddch (WINDOW *, const chtype);
extern int waddchnstr (WINDOW *,const chtype *,int);
extern int waddchstr (WINDOW *,const chtype *);
extern int waddnstr (WINDOW *,const char *,int);
extern int waddstr (WINDOW *,const char *);
extern int wattron (WINDOW *, int);
extern int wattroff (WINDOW *, int);
extern int wattrset (WINDOW *, int);
extern int wattr_get (WINDOW *, attr_t *, short *, void *);
extern int wattr_on (WINDOW *, attr_t, void *);
extern int wattr_off (WINDOW *, attr_t, void *);
extern int wattr_set (WINDOW *, attr_t, short, void *);
extern int wbkgd (WINDOW *, chtype);
extern void wbkgdset (WINDOW *,chtype);
extern int wborder (WINDOW *,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);
extern int wchgat (WINDOW *, int, attr_t, short, const void *);
extern int wclear (WINDOW *);
extern int wclrtobot (WINDOW *);
extern int wclrtoeol (WINDOW *);
extern int wcolor_set (WINDOW*,short,void*);
extern void wcursyncup (WINDOW *);
extern int wdelch (WINDOW *);
extern int wdeleteln (WINDOW *);
extern int wechochar (WINDOW *, const chtype);
extern int werase (WINDOW *);
extern int wgetch (WINDOW *);
extern int wgetnstr (WINDOW *,char *,int);
extern int wgetstr (WINDOW *, char *);
extern int whline (WINDOW *, chtype, int);
extern chtype winch (WINDOW *);
extern int winchnstr (WINDOW *, chtype *, int);
extern int winchstr (WINDOW *, chtype *);
extern int winnstr (WINDOW *, char *, int);
extern int winsch (WINDOW *, chtype);
extern int winsdelln (WINDOW *,int);
extern int winsertln (WINDOW *);
extern int winsnstr (WINDOW *, const char *,int);
extern int winsstr (WINDOW *, const char *);
extern int winstr (WINDOW *, char *);
extern int wmove (WINDOW *,int,int);
extern int wnoutrefresh (WINDOW *);
extern int wprintw (WINDOW *, const char *,...)
  ;
extern int wredrawln (WINDOW *,int,int);
extern int wrefresh (WINDOW *);
extern int wscanw (WINDOW *, char *,...)
  ;
extern int wscrl (WINDOW *,int);
extern int wsetscrreg (WINDOW *,int,int);
extern int wstandout (WINDOW *);
extern int wstandend (WINDOW *);
extern void wsyncdown (WINDOW *);
extern void wsyncup (WINDOW *);
extern void wtimeout (WINDOW *,int);
extern int wtouchln (WINDOW *,int,int,int);
extern int wvline (WINDOW *,chtype,int);
# 1166 "/usr/include/curses.h" 3 4
typedef unsigned long mmask_t;

typedef struct
{
    short id;
    int x, y, z;
    mmask_t bstate;
}
MEVENT;

extern int getmouse (MEVENT *);
extern int ungetmouse (MEVENT *);
extern mmask_t mousemask (mmask_t, mmask_t *);
extern _Bool wenclose (const WINDOW *, int, int);
extern int mouseinterval (int);
extern _Bool wmouse_trafo (const WINDOW* win,int* y, int* x, _Bool to_screen);
extern _Bool mouse_trafo (int*, int*, _Bool);





extern int mcprint (char *, int);
extern int has_key (int);



extern void _tracef (const char *, ...) ;
extern void _tracedump (const char *, WINDOW *);
extern char * _traceattr (attr_t);
extern char * _traceattr2 (int, chtype);
extern char * _nc_tracebits (void);
extern char * _tracechar (int);
extern char * _tracechtype (chtype);
extern char * _tracechtype2 (int, chtype);
# 1210 "/usr/include/curses.h" 3 4
extern char * _tracemouse (const MEVENT *);
extern void trace (const unsigned int);
# 136 "./test.priv.h" 2
# 1 "/usr/include/term.h" 1 3 4
# 82 "/usr/include/term.h" 3 4
# 1 "/usr/include/termios.h" 1 3 4
# 36 "/usr/include/termios.h" 3 4




# 1 "/usr/include/bits/termios.h" 1 3 4
# 25 "/usr/include/bits/termios.h" 3 4
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;


struct termios
  {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;


  };
# 41 "/usr/include/termios.h" 2 3 4
# 49 "/usr/include/termios.h" 3 4
extern speed_t cfgetospeed ( struct termios *__termios_p);


extern speed_t cfgetispeed ( struct termios *__termios_p);


extern int cfsetospeed (struct termios *__termios_p, speed_t __speed);


extern int cfsetispeed (struct termios *__termios_p, speed_t __speed);



extern int cfsetspeed (struct termios *__termios_p, speed_t __speed);




extern int tcgetattr (int __fd, struct termios *__termios_p);



extern int tcsetattr (int __fd, int __optional_actions,
         struct termios *__termios_p);




extern void cfmakeraw (struct termios *__termios_p);



extern int tcsendbreak (int __fd, int __duration);





extern int tcdrain (int __fd);



extern int tcflush (int __fd, int __queue_selector);



extern int tcflow (int __fd, int __action);
# 105 "/usr/include/termios.h" 3 4
# 1 "/usr/include/sys/ttydefaults.h" 1 3 4
# 106 "/usr/include/termios.h" 2 3 4



# 83 "/usr/include/term.h" 2 3 4
# 674 "/usr/include/term.h" 3 4
typedef struct termtype {
    char *term_names;
    char *str_table;
    char *Booleans;
    short *Numbers;
    char **Strings;


    char *ext_str_table;
    char **ext_Names;

    unsigned short num_Booleans;
    unsigned short num_Numbers;
    unsigned short num_Strings;

    unsigned short ext_Booleans;
    unsigned short ext_Numbers;
    unsigned short ext_Strings;


} TERMTYPE;

typedef struct term {
    TERMTYPE type;
    short Filedes;
    struct termios Ottyb,
  Nttyb;
    int _baudrate;
    char * _termname;
} TERMINAL;

extern TERMINAL * cur_term;
# 730 "/usr/include/term.h" 3 4
extern char * const boolnames[];
extern char * const boolcodes[];
extern char * const boolfnames[];
extern char * const numnames[];
extern char * const numcodes[];
extern char * const numfnames[];
extern char * const strnames[];
extern char * const strcodes[];
extern char * const strfnames[];




extern int _nc_set_tty_mode (struct termios *buf);
extern int _nc_get_tty_mode (struct termios *buf);
extern int _nc_read_entry (const char * const, char * const, TERMTYPE *const);
extern int _nc_read_file_entry (const char *const, TERMTYPE *);
extern char * _nc_first_name (const char *const);
extern int _nc_name_match (const char *const, const char *const, const char *const);
extern int _nc_read_termcap_entry (const char *const, TERMTYPE *const);
extern const TERMTYPE * _nc_fallback (const char *);


extern TERMINAL * set_curterm (TERMINAL *);
extern int del_curterm (TERMINAL *);


extern int restartterm ( char *, int, int *);
extern int setupterm ( char *,int,int *);
# 772 "/usr/include/term.h" 3 4
extern char * tgetstr ( char *, char **);
extern char * tgoto (const char *, int, int);
extern int tgetent (char *, const char *);
extern int tgetflag ( char *);
extern int tgetnum ( char *);
extern int tputs (const char *, int, int (*)(int));
# 137 "./test.priv.h" 2
# 153 "./test.priv.h"
extern char *optarg;
extern int optind;
# 163 "./test.priv.h"
# 1 "/usr/include/assert.h" 1 3 4
# 65 "/usr/include/assert.h" 3 4



extern void __assert_fail ( char *__assertion,  char *__file,
      unsigned int __line,  char *__function)
     ;


extern void __assert_perror_fail (int __errnum,  char *__file,
      unsigned int __line,
       char *__function)
     ;




extern void __assert (const char *__assertion, const char *__file, int __line)
     ;



# 164 "./test.priv.h" 2
# 1 "/usr/include/ctype.h" 1 3 4
# 30 "/usr/include/ctype.h" 3 4

# 48 "/usr/include/ctype.h" 3 4
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 81 "/usr/include/ctype.h" 3 4
extern  unsigned short int **__ctype_b_loc (void)
     ;
extern  __int32_t **__ctype_tolower_loc (void)
     ;
extern  __int32_t **__ctype_toupper_loc (void)
     ;
# 96 "/usr/include/ctype.h" 3 4






extern int isalnum (int);
extern int isalpha (int);
extern int iscntrl (int);
extern int isdigit (int);
extern int islower (int);
extern int isgraph (int);
extern int isprint (int);
extern int ispunct (int);
extern int isspace (int);
extern int isupper (int);
extern int isxdigit (int);



extern int tolower (int __c);


extern int toupper (int __c);


# 142 "/usr/include/ctype.h" 3 4
extern int isascii (int __c);



extern int toascii (int __c);



extern int _toupper (int);
extern int _tolower (int);
# 323 "/usr/include/ctype.h" 3 4

# 165 "./test.priv.h" 2
# 21 "hanoi.c" 2
# 36 "hanoi.c"
struct Peg {
    size_t Length[9];
    int Count;
};

static struct Peg Pegs[3];
static int PegPos[] =
{19, 39, 59};
static int TileColour[] =
{
    2,
    5,
    1,
    4,
    6,
    3,
    2,
    5,
    1,
};
static int NMoves = 0;

static void InitTiles(int NTiles);
static void DisplayTiles(void);
static void MakeMove(int From, int To);
static void AutoMove(int From, int To, int Num);
static void Usage(void);
static int Solved(int NumTiles);
static int GetMove(int *From, int *To);
static int InvalidMove(int From, int To);

int
main(int argc, char **argv)
{
    int NTiles, FromCol, ToCol;
    _Bool AutoFlag = 0;

    ;

    switch (argc) {
    case 1:
 NTiles = 7;
 break;
    case 2:
 NTiles = atoi(argv[1]);
 if (NTiles > 9 || NTiles < 3) {
     fprintf(stderr, "Range %d to %d\n", 3, 9);
     exit(1);
 }
 break;
    case 3:
 if (strcmp(argv[2], "a")) {
     Usage();
     exit(1);
 }
 NTiles = atoi(argv[1]);
 if (NTiles > 9 || NTiles < 3) {
     fprintf(stderr, "Range %d to %d\n", 3, 9);
     exit(1);
 }
 AutoFlag = 1;
 break;
    default:
 Usage();
 exit(1);
    }



    initscr();
    if (has_colors()) {
 int i;
 int bg = 0;
 start_color();




 for (i = 0; i < 9; i++)
     init_pair(i + 1, bg, TileColour[i]);
    }
    cbreak();
    if (LINES < 24) {
 endwin();
 fprintf(stderr, "Min screen length 24 lines\n");
 exit(1);
    }
    if (AutoFlag) {
 curs_set(0);
 leaveok(stdscr, 1);
    }
    InitTiles(NTiles);
    DisplayTiles();
    if (AutoFlag) {
 do {
     noecho();
     AutoMove(0, 2, NTiles);
 } while (!Solved(NTiles));
 sleep(2);
    } else {
 echo();
 for (;;) {
     if (GetMove(&FromCol, &ToCol))
  break;
     if (InvalidMove(FromCol, ToCol)) {
  (wmove(stdscr,(LINES-3),0) == (-1) ? (-1) : waddnstr(stdscr,"Invalid Move !!",-1));
  wrefresh(stdscr);
  beep();
  continue;
     }
     MakeMove(FromCol, ToCol);
     if (Solved(NTiles)) {
  mvprintw((LINES-3), 0,
    "Well Done !! You did it in %d moves", NMoves);
  wrefresh(stdscr);
  sleep(5);
  break;
     }
 }
    }
    endwin();
    exit(0);
}

static int
InvalidMove(int From, int To)
{
    if (From >= 3)
 return 1;
    if (From < 0)
 return 1;
    if (To >= 3)
 return 1;
    if (To < 0)
 return 1;
    if (From == To)
 return 1;
    if (!Pegs[From].Count)
 return 1;
    if (Pegs[To].Count &&
 Pegs[From].Length[Pegs[From].Count - 1] >
 Pegs[To].Length[Pegs[To].Count - 1])
 return 1;
    return 0;
}

static void
InitTiles(int NTiles)
{
    int Size, SlotNo;

    for (Size = NTiles * 2 + 1, SlotNo = 0; Size >= 3; Size -= 2)
 Pegs[0].Length[SlotNo++] = Size;

    Pegs[0].Count = NTiles;
    Pegs[1].Count = 0;
    Pegs[2].Count = 0;
}

static void
DisplayTiles(void)
{
    int Line, peg, SlotNo;
    char TileBuf[8192];

    werase(stdscr);
    (wmove(stdscr,1,24) == (-1) ? (-1) : waddnstr(stdscr,"T O W E R S   O F   H A N O I",-1));
    (wmove(stdscr,3,34) == (-1) ? (-1) : waddnstr(stdscr,"SJR 1990",-1));
    mvprintw(19, 5, "Moves : %d", NMoves);
    ((stdscr)->_attrs = (((1UL) << ((10) + 8))));
    (wmove(stdscr,16,8) == (-1) ? (-1) : waddnstr(stdscr,"                                                               ",-1));


    for (Line = 6; Line < 16; Line++) {
 (wmove(stdscr,Line,19) == (-1) ? (-1) : waddch(stdscr,' '));
 (wmove(stdscr,Line,39) == (-1) ? (-1) : waddch(stdscr,' '));
 (wmove(stdscr,Line,59) == (-1) ? (-1) : waddch(stdscr,' '));
    }
    (wmove(stdscr,16,19) == (-1) ? (-1) : waddch(stdscr,'1'));
    (wmove(stdscr,16,39) == (-1) ? (-1) : waddch(stdscr,'2'));
    (wmove(stdscr,16,59) == (-1) ? (-1) : waddch(stdscr,'3'));
    ((stdscr)->_attrs = (0L));


    for (peg = 0; peg < 3; peg++) {
 for (SlotNo = 0; SlotNo < Pegs[peg].Count; SlotNo++) {
     memset(TileBuf, ' ', Pegs[peg].Length[SlotNo]);
     TileBuf[Pegs[peg].Length[SlotNo]] = '\0';
     if (has_colors())
  ((stdscr)->_attrs = ((((((Pegs[peg].Length[SlotNo])-1)/2)) << ((0) + 8))));
     else
  ((stdscr)->_attrs = (((1UL) << ((10) + 8))));
     (wmove(stdscr,16 - (SlotNo + 1),(int) (PegPos[peg] - Pegs[peg].Length[SlotNo] / 2)) == (-1) ? (-1) : waddnstr(stdscr,TileBuf,-1));


 }
    }
    ((stdscr)->_attrs = (0L));
    wrefresh(stdscr);
}

static int
GetMove(int *From, int *To)
{
    (wmove(stdscr,(LINES-3),0) == (-1) ? (-1) : waddnstr(stdscr,"Next move ('q' to quit) from ",-1));
    wclrtoeol(stdscr);
    wrefresh(stdscr);
    if ((*From = wgetch(stdscr)) == 'q')
 return 1;
    *From -= ('0' + 1);
    waddnstr(stdscr," to ",-1);
    wclrtoeol(stdscr);
    wrefresh(stdscr);

    if ((*To = wgetch(stdscr)) == 'q')
 return 1;
    *To -= ('0' + 1);
    wrefresh(stdscr);
    napms(500);

    wmove(stdscr,(LINES-3),0);
    wclrtoeol(stdscr);
    wrefresh(stdscr);
    return 0;
}

static void
MakeMove(int From, int To)
{
    Pegs[From].Count--;
    Pegs[To].Length[Pegs[To].Count] = Pegs[From].Length[Pegs[From].Count];
    Pegs[To].Count++;
    NMoves++;
    DisplayTiles();
}

static void
AutoMove(int From, int To, int Num)
{
    if (Num == 1) {
 MakeMove(From, To);
 napms(500);
 return;
    }
    AutoMove(From, (3-((From)+(To))), Num - 1);
    MakeMove(From, To);
    napms(500);
    AutoMove((3-((From)+(To))), To, Num - 1);
}

static int
Solved(int NumTiles)
{
    int i;

    for (i = 1; i < 3; i++)
 if (Pegs[i].Count == NumTiles)
     return 1;
    return 0;
}

static void
Usage(void)
{
    fprintf(stderr, "Usage: hanoi [<No Of Tiles>] [a]\n");
    fprintf(stderr,
     "The 'a' option causes the tower to be solved automatically\n");
}
