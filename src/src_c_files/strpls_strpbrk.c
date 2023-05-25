#include "../src_h_files/string_plus.h"

char *strpls_strpbrk(const char *str1, const char *str2) {
  const char *scanp;
  int c;
  int sc;
  int is_found = 0;

  while (!(is_found) && (c = *str1++)) {
    for (scanp = str2; !(is_found) && (sc = *scanp++);) {
      if (sc == c) {
        is_found = 1;
      }
    }
  }
  return is_found ? (char *)(str1 - 1) : strpls_NULL;
}
