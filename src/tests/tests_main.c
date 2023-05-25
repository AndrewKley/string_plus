#include "tests.h"

START_TEST(strlen_test) {
  char *test1 = "Hello, World. How are you?";
  char test2[50] = "suite *suite = ";
  char test3[10] = {'A', 'n', 'd', ' ', 'I', '\'', 'l', 'l', '\0'};
  char test4[1] = "\0";

  ck_assert_uint_eq(strpls_strlen(test1), strlen(test1));
  ck_assert_uint_eq(strpls_strlen(test2), strlen(test2));
  ck_assert_uint_eq(strpls_strlen(test3), strlen(test3));
  ck_assert_uint_eq(strpls_strlen(test4), strlen(test4));
}
END_TEST

START_TEST(strcat_test) {
  char test1[300] = "Hello, World. How are you?";
  char test2[50] = "suite *suite = ";
  char test3[10] = {'A', 'n', 'd', ' ', 'I', '\'', 'l', 'l', '\0'};
  char test4[50] = "";
  char test5[1] = "\0";
  char test6[1] = "\0";

  ck_assert_str_eq(strpls_strcat(test1, test2), strcat(test1, test2));
  ck_assert_str_eq(strpls_strcat(test3, test4), strcat(test3, test4));
  ck_assert_str_eq(strpls_strcat(test2, test4), strcat(test2, test4));
  ck_assert_str_eq(strpls_strcat(test4, test2), strcat(test4, test2));
  ck_assert_str_eq(strpls_strcat(test5, test6), strcat(test5, test6));
}
END_TEST

START_TEST(strncat_test) {
  char test1[300] = "Hello, World. How are you?";
  char test2[50] = "suite *suite = ";
  char test3[10] = {'A', 'n', 'd', '\0', 'I', '\'', 'l', 'l', '\0'};
  char test4[50] = "";

  for (int i = 0; i < 10; i++) {
    ck_assert_str_eq(strpls_strncat(test1, test2, i), strncat(test1, test2, i));
  }
  ck_assert_str_eq(strpls_strncat(test1, test2, 5), strncat(test1, test2, 5));
  ck_assert_str_eq(strpls_strncat(test1, test2, 0), strncat(test1, test2, 0));
  ck_assert_str_eq(strpls_strncat(test2, test1, 0), strncat(test2, test1, 0));
  ck_assert_str_eq(strpls_strncat(test1, test2, 50), strncat(test1, test2, 50));
  ck_assert_str_eq(strpls_strncat(test1, test2, 250), strncat(test1, test2, 250));
  ck_assert_str_eq(strpls_strncat(test2, test4, 10), strncat(test2, test4, 10));
  ck_assert_str_eq(strpls_strncat(test4, test2, 0), strncat(test4, test2, 0));
  ck_assert_str_eq(strpls_strncat(test3, test4, 9), strncat(test3, test4, 9));
  ck_assert_str_eq(strpls_strncat(test3, test4, 0), strncat(test3, test4, 0));
}
END_TEST

START_TEST(strcmp_test) {
  char test1[300] = "Hello, World. How are you?";
  char test11[300] = "Hello, World. How are you?";
  char test2[50] = "suite *suite = ";
  char test3[10] = {'A', 'n', 'd', ' ', 'I', '\'', 'l', 'l', '\0'};
  char test4[50] = "";
  char test5[1] = "\0";
  char test6[1] = "\0";
  char test7[10] = "123";
  char test8[10] = "000";
  char test9[10] = " 00";

  ck_assert_int_lt(strpls_strcmp(test1, test2), 0);
  ck_assert_int_lt(strcmp(test1, test2), 0);
  ck_assert_int_gt(strpls_strcmp(test2, test1), 0);
  ck_assert_int_gt(strcmp(test2, test1), 0);
  ck_assert_int_gt(strpls_strcmp(test3, test4), 0);
  ck_assert_int_gt(strcmp(test3, test4), 0);
  ck_assert_int_lt(strpls_strcmp(test4, test3), 0);
  ck_assert_int_lt(strcmp(test4, test3), 0);
  ck_assert_int_gt(strpls_strcmp(test2, test4), 0);
  ck_assert_int_gt(strcmp(test2, test4), 0);
  ck_assert_int_lt(strpls_strcmp(test4, test2), 0);
  ck_assert_int_lt(strcmp(test4, test2), 0);
  ck_assert_int_eq(strpls_strcmp(test5, test6), strcmp(test5, test6));
  ck_assert_int_eq(strpls_strcmp(test6, test5), strcmp(test6, test5));
  ck_assert_int_eq(strpls_strcmp(test1, test11), strcmp(test1, test11));
  ck_assert_int_eq(strpls_strcmp(test11, test1), strcmp(test11, test1));
  ck_assert_int_gt(strpls_strcmp(test7, test8), 0);
  ck_assert_int_gt(strcmp(test7, test8), 0);
  ck_assert_int_lt(strpls_strcmp(test8, test7), 0);
  ck_assert_int_lt(strcmp(test8, test7), 0);
  ck_assert_int_gt(strpls_strcmp(test8, test9), 0);
  ck_assert_int_gt(strcmp(test8, test9), 0);
  ck_assert_int_lt(strpls_strcmp(test9, test8), 0);
  ck_assert_int_lt(strcmp(test9, test8), 0);
}
END_TEST

START_TEST(strncmp_test) {
  char test1[50] = "Hello, World. How are you?";
  char test11[50] = "Hello, World. How are you?";
  char test00[50] = "Hello, World.\0 123";
  char test01[50] = "Hello, World.0 123";
  char test2[50] = "Hello, World. Tnx. Fine.";
  char test3[50] = "";
  char test4[50] = "";

  ck_assert_int_eq(strpls_strncmp(test00, test01, 5), strncmp(test00, test01, 5));
  ck_assert_int_lt(strpls_strncmp(test00, test01, 50), 0);
  ck_assert_int_lt(strncmp(test00, test01, 50), 0);
  ck_assert_int_gt(strpls_strncmp(test01, test00, 50), 0);
  ck_assert_int_gt(strncmp(test01, test00, 50), 0);
  ck_assert_int_eq(strpls_strncmp(test3, test4, 0), strncmp(test3, test4, 0));
  ck_assert_int_eq(strncmp(test3, test4, 0), strpls_strncmp(test4, test3, 0));
  ck_assert_int_eq(strpls_strncmp(test1, test2, 0), strncmp(test1, test2, 0));
  ck_assert_int_eq(strpls_strncmp(test1, test2, 14), strncmp(test1, test2, 14));
  ck_assert_int_eq(strpls_strncmp(test11, test1, 26), strncmp(test11, test1, 26));
  ck_assert_int_eq(strpls_strncmp(test1, test11, 27), strncmp(test1, test11, 27));
  ck_assert_int_lt(strpls_strncmp(test1, test2, 15), 0);
  ck_assert_int_lt(strncmp(test1, test2, 15), 0);
  ck_assert_int_gt(strpls_strncmp(test2, test1, 40), 0);
  ck_assert_int_gt(strncmp(test2, test1, 40), 0);
  ck_assert_int_lt(strpls_strncmp(test1, test2, 40), 0);
  ck_assert_int_lt(strncmp(test1, test2, 40), 0);
}
END_TEST

START_TEST(memcmp_test) {
  char mem1[10] = "123\0ayz";
  char mem2[10] = "123\0abc";
  int mem3[10] = {0, 1, 2, 3, 4, 5, 5, 5, 5, 5};
  int mem4[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(strpls_memcmp(mem1, mem2, i), memcmp(mem1, mem2, i));
    ck_assert_int_eq(strpls_memcmp(mem2, mem1, i), memcmp(mem2, mem1, i));
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(strpls_memcmp(mem3, mem4, i), memcmp(mem3, mem4, i));
    ck_assert_int_eq(strpls_memcmp(mem4, mem3, i), memcmp(mem4, mem3, i));
  }
}
END_TEST

START_TEST(strchr_test) {
  const char *str = "Try not. Do, or do not. There is no try.";
  char target = 'T';
  char *s1 = malloc(strlen(str) * sizeof(char) + 1);
  char *s2 = malloc(strlen(str) * sizeof(char) + 1);
  strcpy(s1, str);
  strcpy(s2, str);
  char *result1 = s1;
  char *result2 = s2;

  result1 = strpls_strchr(result1, target);
  result2 = strchr(result2, target);
  ck_assert_str_eq(result1, result2);
  ++result1;
  ++result2;
  result1 = strpls_strchr(result1, target);
  result2 = strchr(result2, target);
  ck_assert_str_eq(result1, result2);

  result1 = s1;
  result2 = s2;
  target = 'A';
  result1 = strpls_strchr(result1, target);
  result2 = strchr(result2, target);
  ck_assert_ptr_eq(result1, result2);

  free(s1);
  s1 = NULL;
  free(s2);
  s2 = NULL;
}
END_TEST

START_TEST(memchr_test) {
  const char *str = "Hello, World! How are you?";
  ck_assert_ptr_null(strpls_memchr(str, '!', 0));
  ck_assert_ptr_null(memchr(str, '!', 0));
  ck_assert_ptr_null(strpls_memchr(str, '?', 25));
  ck_assert_ptr_null(memchr(str, '?', 25));
  ck_assert_ptr_null(strpls_memchr(str, '?', 15));
  ck_assert_ptr_null(memchr(str, '?', 15));
  ck_assert_str_eq(strpls_memchr(str, '!', 13), memchr(str, '!', 13));
  ck_assert_str_eq(strpls_memchr(str, '!', 25), memchr(str, '!', 25));
}

START_TEST(memset_test) {
  char str1[] = "Hello, World! How are you?";
  char str2[] = "Hello, World! How are you?";

  ck_assert_str_eq(strpls_memset(str1, '!', 5), memset(str2, '!', 5));
  ck_assert_str_eq(strpls_memset(str1, 0, 1), memset(str2, 0, 1));
}
END_TEST

START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), strpls_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_HEX) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), strpls_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), strpls_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %p Test";
  char *val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), strpls_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_n) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o T%nest %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   strpls_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_ne(valn1, valn2);
  ck_assert_int_ne(valn3, valn4);
}
END_TEST

START_TEST(sprintf_1_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%.*s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  ck_assert_int_eq(sprintf(str1, str3, 3, val, val2, val4, val3),
                   strpls_sprintf(str2, str3, 3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  srunner_add_suite(srunner, test_sprintf_e());
  suite_add_tcase(suite, get_sprintf_case());
  suite_add_tcase(suite, get_plus_tests());
  suite_add_tcase(suite, get_base_tests());
  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, strlen_test);
  tcase_add_test(tcase, strcat_test);
  tcase_add_test(tcase, strncat_test);
  tcase_add_test(tcase, strcmp_test);
  tcase_add_test(tcase, strncmp_test);
  tcase_add_test(tcase, memcmp_test);
  tcase_add_test(tcase, strchr_test);
  tcase_add_test(tcase, memchr_test);
  tcase_add_test(tcase, memset_test);
  tcase_add_test(tcase, sprintf_1_hex);
  tcase_add_test(tcase, sprintf_1_HEX);
  tcase_add_test(tcase, sprintf_1_octal);
  tcase_add_test(tcase, sprintf_1_pointer);
  tcase_add_test(tcase, sprintf_1_n);
  tcase_add_test(tcase, sprintf_1_string);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
