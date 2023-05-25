#include "../src_h_files/string_plus.h"

int strpls_memcmp(const void *str1, const void *str2, strpls_size_t n) {
  int result = 0;

  for (strpls_size_t i = 0; !result && i < n; i++) {
    result = *((unsigned char *)str1 + i) - *((unsigned char *)str2 + i);
  }

  return result;
}
