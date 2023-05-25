#include "../src_h_files/string_plus.h"

void *strpls_trim(const char *src, const char *trim_chars) {
  char *str = strpls_NULL;
  const char *end;

  if (src && trim_chars) {
    const char *begin = src;
    while (*begin && strpls_strchr(trim_chars, *begin)) {
      ++begin;
    }
    if (!*begin) {
      str = (char *)calloc(1, sizeof(char));
    } else {
      end = src + strpls_strlen(src) - 1;
      while (end != begin && strpls_strchr(trim_chars, *end)) {
        --end;
      }
      size_t len = end - begin + 1;
      str = (char *)calloc(1, sizeof(char) * (len + 1));
      if (str) {
        strpls_memcpy(str, begin, len);
        str[len] = '\0';
      }
    }
  }

  return ((void *)str);
}
