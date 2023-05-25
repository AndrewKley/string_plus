#ifndef SRC_TESTS_H
#define SRC_TESTS_H

#include <check.h>
#include <string.h>

#include "../src_h_files/string_plus.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"
#define SIZE 1024

TCase *get_sprintf_case(void);
TCase *get_plus_tests(void);
TCase *get_base_tests(void);
Suite *test_sprintf_c(void);
Suite *test_sprintf_e(void);
Suite *test_sprintf_g(void);

#endif  // SRC_TESTS_H
