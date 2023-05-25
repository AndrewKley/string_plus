#include "../src_h_files/string_plus.h"

char *strpls_strerror(int errnum) {
  static char *s_err;
  static char buffer[50];

  if (0 <= errnum && errnum <= N) {
    static const char *array[] = error;
    s_err = (char *)array[errnum];
  } else {
    strpls_sprintf(buffer, "%s%d", UERROR, (int)errnum);
    s_err = buffer;
  }
  return s_err;
}
