#include "../src_h_files/string_plus.h"

void *strpls_insert(const char *src, const char *str, strpls_size_t start_index) {
  char *array = strpls_NULL;
  if (src && str && start_index <= (strpls_strlen(src))) {
    array = (char *)calloc(strpls_strlen(src) + strpls_strlen(str) + 1, sizeof(char));
    if (array) {
      strpls_size_t i = 0;
      for (; i < start_index; i++) {
        array[i] = src[i];
      }
      strpls_size_t end = i;
      for (strpls_size_t j = 0; j < strpls_strlen(str); j++, i++) {
        array[i] = str[j];
      }
      for (; end < strpls_strlen(src); end++, i++) {
        array[i] = src[end];
      }
      array[strpls_strlen(array)] = '\0';
    }
  }
  return (void *)array;
}
