/*
 * DCL04-C. Do not declare more than one variable per declaration
 * */


char *src = 0, c = 0;

/*
 * DCL05-C. Use typedefs of non-pointer types only
 * */

struct obj {
  int i;
  float f;
};
typedef struct obj *ObjectPtr;

/*
 * DCL20-C. Always specify void even if a function accepts no arguments
 * */

/* In foo.h */
void foo();
 
/* In foo.c */
void foo() {
  int i = 3;
  printf("i value: %d\n", i);
}
 
/* In caller.c */
#include "foo.h"
 
foo(3);

/* ok */

/* In foo.h */
void foo(void);
 
/* In foo.c */
void foo(void) {
  int i = 3;
  printf("i value: %d\n", i);
}
 
/* In caller.c */
#include "foo.h"
 
foo(3);