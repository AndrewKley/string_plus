#include "../src_h_files/string_plus.h"

int in(char ch, const char *str) {
  int flag = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == ch) {
      flag = 1;
    }
  }
  return flag;
}

char *strpls_strtok(char *str, const char *delim) {
  static char *prev_ptr = strpls_NULL;
  char *result;

  if (!str) {
    str = prev_ptr;
  }
  if (!*str) {
    result = strpls_NULL;
  } else {
    while (in(*str, delim)) {
      ++str;
    }
    if (!*str) {
      str = strpls_NULL;
    }
    result = str;
    while (str && *str && !in(*str, delim)) {
      str++;
    }
    if (str && !*str) {
      prev_ptr = str;
    } else if (str && in(*str, delim)) {
      *str = '\0';
      prev_ptr = str + 1;
    }
  }

  return result;
}
