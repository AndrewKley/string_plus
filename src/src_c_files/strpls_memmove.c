#include "../src_h_files/string_plus.h"

void *strpls_memmove(void *dest, const void *src, strpls_size_t n) {
  if (dest <= src) {
    dest = strpls_memcpy(dest, src, n);
  } else {
    strpls_byte *d = (strpls_byte *)dest + n;
    strpls_byte *s = (strpls_byte *)src + n;
    while (n--) {
      *(--d) = *(--s);
    }
  }

  return dest;
}
