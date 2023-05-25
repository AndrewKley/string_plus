#include "../src_h_files/string_plus.h"

void *strpls_to_lower(const char *str) {
  strpls_byte *p = strpls_NULL;
  if (str) {
    int n = strpls_strlen(str) + 1;
    p = (strpls_byte *)malloc(sizeof(strpls_byte) * n);
    if (p) {
      for (int i = 0; i < n; i++, p++, str++) {
        if ('A' <= *str && *str <= 'Z') {
          *p = *str + 32;
        } else {
          *p = *str;
        }
      }
      p -= n;
    }
  }
  return (void *)p;
}
