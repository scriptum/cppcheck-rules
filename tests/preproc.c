/*
 * PRE00-C. Prefer inline or static functions to function-like macros
 * */

#define CUBE(X) ((X) * (X) * (X))
/* ... */
int i = 2;
int a = 81 / CUBE(++i);



size_t count = 0;
/* bad */
#define EXEC_BUMP(func) (func(), ++count)
 
void g(void) {
  printf("Called g, count = %zu.\n", count);
}
 
void aFunc(void) {
  size_t count = 0;
  while (count++ < 10) {
    EXEC_BUMP(g);
  }
}

/*
 * PRE01-C. Use parentheses within macros around parameter names
 * */

/* bad */
#define foreach_c_array(item, array, len) for (item = array; item < &array[len]; item++)

/* good */
#define EMPTY(ptr)	(!(ptr) || !*(ptr))
#define FOO(a,b,c)	foo(a,b,c)

/*
 * PRE03-C. Prefer typedefs to defines for encoding types
 * */

#define cstring char * 
cstring s1, s2;

/*
 * PRE04-C. Do not reuse a standard header file name
 * */

#include "stdio.h"

/*
 * PRE07-C. Avoid using repeated question marks
 * */
size_t i = /* Some initial value */;
if (i > 9000) {
   if (puts("Over 9000!??!") == EOF) {
     /* Handle error */
   }
}

/* 
 * PRE10-C. Wrap multistatement macros in a do-while loop 
 * */

#define SWAP(x, y)                                                             \
  tmp = x; \
  x = y; \
  y = tmp

#define SWAP(x, y)                                                             \
  do { \
    tmp = x; \
    x = y; \
    y = tmp; } \
  while (0)
