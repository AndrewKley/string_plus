#include "../src_h_files/string_plus.h"

strpls_size_t strpls_strcspn(const char *str1, const char *str2) {
  strpls_size_t res = 0;

  if (!str1 || !str2) {
    res = -1;
  } else {
    strpls_size_t len1 = strpls_strlen(str1);
    strpls_size_t len2 = strpls_strlen(str2);
    strpls_size_t i = 0;
    strpls_size_t j;
    int is_found = 0;
    for (; !is_found && i < len1; i++, res++) {
      for (j = 0; !(str1[i] == str2[j]) && j < len2; j++) {
      }
      if (str1[i] == str2[j]) {
        is_found = 1;
        res--;
      }
    }
  }

  return res;
}
