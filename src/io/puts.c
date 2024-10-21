#include <stdio.h>
#include <string.h>
#include <unistd.h>
int puts(const char *str) {
  int ret = strlen(str);
  write(1, str, ret);
  write(1, "\n", 1);
  return ret+1;
}
