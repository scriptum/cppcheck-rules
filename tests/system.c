/* 
 * ENV03-C. Sanitize the environment when invoking external programs 
 * ENV04-C. Do not call system() if you do not need a command processor
 * */

if (system("/bin/ls dir.`date +%Y%m%d`") == -1) {
  /* Handle error */
}