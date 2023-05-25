#include "../src_h_files/string_plus.h"

char *strpls_strncat(char *dest, const char *src, strpls_size_t n) {
  register char *d = dest + strpls_strlen(dest);
  register const char *s = src;

  for (; n-- && *s; ++d, ++s) {
    *d = *s;
  }

  return dest;
}
