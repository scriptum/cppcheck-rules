/*
 * TMP30-C. Temporary files must created with unique and unpredictable file names
 * */

FILE *fp = fopen("/tmp/some_file", "w");

int fd = open("/tmp/some_file", O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);

