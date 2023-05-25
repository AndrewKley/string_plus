#include "../src_h_files/string_plus.h"

char *strpls_strstr(const char *haystack, const char *needle) {
  strpls_size_t needle_size = strpls_strlen(needle);
  char *result = strpls_NULL;

  while (*haystack && strpls_strncmp(haystack, needle, needle_size)) {
    ++haystack;
  }

  result = *haystack || !*needle ? (char *)haystack : strpls_NULL;

  return result;
}
