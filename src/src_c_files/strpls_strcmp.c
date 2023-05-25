#include "../src_h_files/string_plus.h"

int strpls_strcmp(const char *str1, const char *str2) {
  const char *s1 = str1;
  const char *s2 = str2;
  while (*s1 && *s2 && (*s1 == *s2)) {
    s1++;
    s2++;
  }

  return (*s1 - *s2);
}
