#include "../src_h_files/string_plus.h"

void *strpls_memcpy(void *dest, const void *src, strpls_size_t n) {
  strpls_byte *d = (strpls_byte *)dest;
  strpls_byte *s = (strpls_byte *)src;
  while (n--) {
    *d++ = *s++;
  }

  return dest;
}
