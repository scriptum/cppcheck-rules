/*
 * STR03-A. Do not inadvertently truncate a null terminated byte string
 * */

char *string_data;
char a[16];
/* ... */
strncpy(a, string_data, sizeof(a));

/*
 * STR05-A. Prefer making string literals const-qualified
 * */

/* bad */
char *c = "Hello";
char c2[] = "Hello";

/* good */
const char *s = "Hello";

/*
 * STR30-C. Do not attempt to modify string literals
 * */

mktemp("/tmp/edXXXXXX");

/*
 * STR31-C. Guarantee that storage for strings has sufficient space for character data and the null terminator
 * */

char dest[512];
for (int i=0; (i < sizeof(dest)); i++) {
	dest[i] = src[i];
}
dest[i] = '\0';

int main(int argc, char *argv[]) {
/* ... */
char prog_name[128];
strcpy(prog_name, argv[0]);
/* ... */
}


char buff[256];
strcpy(buff, getenv("EDITOR"));

/*
 * STR32-C. Guarantee that all byte strings are null-terminated
 * */

char a[16];
strncpy(a, "0123456789abcdef", sizeof(a));

/* good */

char a[16];
strncpy(a, "0123456789abcdef", sizeof(a)-1);
a[sizeof(a)-1] = '\0';

/* good */
strncpy (result, start, length);
result [length] = '\0';

/* baaaad */

char buf[BUFSIZ];
gets(buf);

