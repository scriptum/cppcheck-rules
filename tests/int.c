/*
 * INT01-A. Use size_t for all integer values representing the size of an object
 * */

char *copy(size_t n, char *str) {
  int i;
  if(p == NULL) {
  /* Handle malloc failure */
  }
  for ( i = 0; i < n; ++i ) {
  p[i] = *str++;
  }
  p[i] = '\0';
  return p;
}
char *p = copy(SIZE_MAX, argv[1]);

#define BUFF_SIZE 10
int main(int argc, char *argv[]){
int size;
char buf[BUFF_SIZE];
size= atoi(argv[1]);
if (size <= BUFF_SIZE){
memcpy(buf, argv[2], size);
}
}

void *alloc(unsigned int blocksize) {
  return malloc(blocksize);
}
int read_counted_string(int fd) {
  unsigned long length;
  unsigned char *data;
  if (read_integer_from_network(fd, &length) < 0) {
  return -1;
  }
  if (length + 1 == 0) {
  /* handle integer overflow */
  }
  data = alloc(length + 1);
  if (read_network_data(fd, data, length) < 0) {
  free(data);
  return -1;
  }
  /* ... */
}
