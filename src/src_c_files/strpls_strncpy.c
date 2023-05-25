#include "../src_h_files/string_plus.h"

char *strpls_strncpy(char *dest, const char *src, strpls_size_t n) {
  strpls_size_t i = 0;
  char *d = dest;

  while (i < n && src[i]) {
    d[i] = src[i];
    ++i;
  }

  while (i < n) {
    d[i] = '\0';
    ++i;
  }

  return dest;
}
