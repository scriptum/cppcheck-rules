/*
 * FIO33-C. Detect and handle input output errors resulting in undefined behavior
 * */

#include <stdio.h>
 
int fmt_data(char *buffer, size_t bufsize, char *s, char c,
             int i, float fp) {
  int j;
 
  j = snprintf(buffer, bufsize, " String:    %s\n", s);
  j += snprintf(buffer + j, bufsize - j, " Character: %c\n",
                (unsigned char)c);
  j += snprintf(buffer + j, bufsize - j, " Integer:   %d\n",
                i);
  j += snprintf(buffer + j, bufsize - j, " Real:      %f\n",
                fp);
 
  return j;
}
