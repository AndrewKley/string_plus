#include "../src_h_files/string_plus.h"

void *strpls_memchr(const void *str, int c, strpls_size_t n) {
  register const unsigned char *s = strpls_NULL;

  if (n) {
    s = str;
    while (!(*s++ == c) && --n) {
    }
  }

  return n ? (void *)--s : strpls_NULL;
}
