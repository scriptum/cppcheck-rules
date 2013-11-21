/*
 * EXP08-C. Ensure pointer arithmetic is used correctly
 * */

int buf[INTBUFSIZE];
int *buf_ptr = buf;
 
while (havedata() && buf_ptr < (buf + sizeof(buf))) {
  *buf_ptr++ = parseint(getdata());
}

/*
 * EXP06-C. Operands to the sizeof operator should not contain side effects
 * */

int a = 14;
int b = sizeof(a++);


/*
 * EXP02-A. The second operands of the logical AND and OR operators should
not contain side effects
 * */


int i;
int max;
if ( (i >= 0 && (i++) <= max) ) {
/* code */
}

/*
 * EXP04-A. Do not perform byte-by-byte comparisons between structures
 * */

struct my_buf {
  size_t size;
  char buffer[50];
};
unsigned int buf_compare(struct my_buf *s1, struct my_buf *s2) {
  if (!memcmp(s1, s2, sizeof(struct my_struct))) {
  return 1;
  }
  return 0;
}

/*
 * EXP30-C. Do not depend on order of evaluation between sequence points
 * */

a = i + b[++i];
i = ++i + 1;
a[i++] = i;
func(i++, i);

/*
 * EXP31-C. Do not modify constant values
 * */

char const **cpp;
char *cp;
char const c = 'A';
cpp = &cp; /* constraint violation */
*cpp = &c; /* valid */
*cp = 'B'; /* valid */

/*
 * EXP32-C. Do not access a volatile object through a non-volatile reference
 * */

static volatile int **ipp;
static int *ip;
static volatile int i = 0;
printf("i = %d.\n", i);
ipp = &ip; /* constraint violation */
*ipp = &i; /* valid */
if (*ip != 0) { /* valid */
/* ... */
}

/*
 * EXP33-C. Do not reference uninitialized variables
 * */

void set_flag(int number, int *sign_flag) {
if (number > 0) {
*sign_flag = 1;
}
else if (number < 0) {
*sign_flag = -1;
}
}
void func(int number) {
int sign;
set_flag(number,&sign);
/* ... */
}


int do_auth(void) {
  char username[MAX_USER];
  char password[MAX_PASS];
  puts("Please enter your username: ");
  fgets(username, MAX_USER, stdin);
  puts("Please enter your password: ");
  fgets(password, MAX_PASS, stdin);
  if (!strcmp(username, "user") && !strcmp(password, "password")) {
    return 0;
  }
  return -1;
}
void log_error(char *msg) {
  char *err;
  char *log;
  char buffer[24];
  sprintf(buffer, "Error: %s", log);
  printf("%s\n", buffer);
}
int main(void) {
  if (do_auth() == -1) {
  log_error("Unable to login");
  }
  return 0;
}

/*
 * EXP35-C. Do not access or modify the result of a function call after a subsequent sequence point
 * */

#include <stdio.h>
struct X { char a[6]; };
struct X addressee() {
  struct X result = { "world" };
  return result;
}
int main(void) {
printf("Hello, %s!\n", addressee().a);
return 0;
}

/*
 * EXP36-C. Do not cast between pointers to objects or types with differing alignments
 * */

char *loop_ptr;
int *int_ptr;
int *loop_function(void *v_pointer){
return v_pointer;
}
int_ptr = loop_function(loop_ptr);


/* good */
ad->pos = ad->constrained = pos--;
