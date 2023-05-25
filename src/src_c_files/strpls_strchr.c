#include "../src_h_files/string_plus.h"

char *strpls_strrchr(const char *str, int c) {
  char *p = strpls_NULL;
  if (!c) {
    p = (char *)str + strpls_strlen(str);
  } else {
    unsigned char uc = (unsigned char)c;
    while (*str) {
      if (*str == uc) {
        p = (char *)str;
      }
      str++;
    }
  }
  return p;
}
