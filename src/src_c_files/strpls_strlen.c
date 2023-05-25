#include "../src_h_files/string_plus.h"

strpls_size_t strpls_strlen(const char *str) {
  strpls_size_t result = 0;

  while (str[result]) {
    ++result;
  }

  return result;
}
