#include "../src_h_files/string_plus.h"

void *strpls_memset(void *str, int c, strpls_size_t n) {
  long int s = (long int)str;
  while (n--) {
    ((strpls_byte *)s++)[0] = c;
  }

  return str;
}
