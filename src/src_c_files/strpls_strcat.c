#include "../src_h_files/string_plus.h"

char *strpls_strcat(char *dest, const char *src) {
  strpls_size_t len = 0;
  strpls_size_t i = 0;

  while (dest[len]) {
    ++len;
  }

  for (i = 0; src[i]; i++) {
    dest[len + i] = src[i];
  }

  dest[len + i] = '\0';

  return dest;
}
