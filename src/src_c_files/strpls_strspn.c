#include "../src_h_files/string_plus.h"

strpls_size_t strpls_strspn(const char *str1, const char *str2) {
  strpls_size_t res = 0;
  if (str1 && str2) {
    int is_found = 0;
    for (; !is_found && *str1; str1++, res++) {
      const char *p;
      p = str2;
      while (!(*p == *str1) && *p) {
        p++;
      }
      if (!*p) {
        is_found = 1;
        res--;
      }
    }
  }
  return res;
}
