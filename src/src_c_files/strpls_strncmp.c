#include "../src_h_files/string_plus.h"

int strpls_strncmp(const char *str1, const char *str2, strpls_size_t n) {
  if (n) {
    while ((*str1++ == *str2++) && n-- && (*str1 || *str2)) {
    }
  }

  return n == 0 ? 0 : (*--str1 - *--str2);
}
