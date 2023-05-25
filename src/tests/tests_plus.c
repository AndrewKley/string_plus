#include "tests.h"

START_TEST(test_insert) {
  char str1[128];
  char answ[128];
  char *tok1;
  char *tok2;

  strcpy(str1, "123 TeSt StRiNg");
  strcpy(answ, "123 TeSt SHitRiNg");
  tok1 = strpls_insert(str1, "Hi", 10);
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  free(tok1);

  strcpy(str1, "123 TeSt StRiNg");
  strcpy(answ, "Hi123 TeSt StRiNg");
  tok1 = strpls_insert(str1, "Hi", 0);
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  free(tok1);
}
END_TEST

START_TEST(insert_two_words) {
  char str1[5] = "heli";
  char str2[7] = "copter";
  char *str3 = (char *)strpls_insert(str1, str2, 4);
  ck_assert_str_eq(str3, "helicopter");
  free(str3);
}
END_TEST

START_TEST(insert_check_for_error_null) {
  char str1[1] = "";
  char str2[5] = "null";
  char *str3 = (char *)strpls_insert(str1, str2, 1);
  ck_assert_ptr_eq(str3, strpls_NULL);
  free(str3);
}
END_TEST

START_TEST(insert_split_word) {
  char str1[11] = "helicopter";
  char str2[2] = " ";
  char *str3 = (char *)strpls_insert(str1, str2, 4);
  ck_assert_str_eq(str3, "heli copter");
  free(str3);
}
END_TEST

START_TEST(insert_add_to_null) {
  char str1[11] = "helicopter";
  char *str2 = strpls_NULL;
  char *str3 = (char *)strpls_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, strpls_NULL);
  free(str3);
}
END_TEST

START_TEST(insert_add_to_start) {
  char str1[7] = "copter";
  char str2[5] = "heli";
  char *str3 = (char *)strpls_insert(str1, str2, 0);
  ck_assert_str_eq(str3, "helicopter");
  free(str3);
}
END_TEST

START_TEST(insert_wrong_location) {
  char str1[5] = "heli";
  char str2[7] = "copter";
  char *str3 = (char *)strpls_insert(str1, str2, -1);
  ck_assert_ptr_eq(str3, strpls_NULL);
  free(str3);
}
END_TEST

START_TEST(insert_to_null) {
  char *str1 = strpls_NULL;
  char str2[7] = "copter";
  char *str3 = (char *)strpls_insert(str1, str2, 1);
  ck_assert_ptr_eq(str3, strpls_NULL);
  free(str3);
}
END_TEST

START_TEST(insert_string_size_check) {
  char str1[2] = " ";
  char str2[5] = "heli";
  char *str3 = (char *)strpls_insert(str1, str2, 3);
  ck_assert_ptr_eq(str3, strpls_NULL);
  free(str3);
}
END_TEST

START_TEST(insert_null_to_null) {
  char *str1 = strpls_NULL;
  char *str2 = strpls_NULL;
  char *str3 = (char *)strpls_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, strpls_NULL);
  free(str3);
}
END_TEST

START_TEST(insert_empty_addition) {
  char str1[1] = "";
  char str2[1] = "";
  char *str3 = (char *)strpls_insert(str1, str2, 1);
  ck_assert_ptr_eq(str3, strpls_NULL);
  free(str3);
}
END_TEST

// TEST strcspn

START_TEST(test_strcspn) {
  ck_assert_int_eq(strpls_strcspn("0123456789", "6789"),
                   strcspn("0123456789", "6789"));
  ck_assert_int_eq(strpls_strcspn("0123456789", "9876"),
                   strcspn("0123456789", "9876"));
  ck_assert_int_eq(strpls_strcspn("0123456789", "\n"),
                   strcspn("0123456789", "\n"));
  ck_assert_int_eq(strpls_strcspn("0123456789", "545454"),
                   strcspn("0123456789", "545454"));
  ck_assert_int_eq(strpls_strcspn("0123456789", "hel\n0"),
                   strcspn("0123456789", "hel\n0"));
  ck_assert_int_eq(strpls_strcspn("0123456789", ""), strcspn("0123456789", ""));
  ck_assert_int_eq(strpls_strcspn("", "123"), strcspn("", "123"));
  ck_assert_int_eq(strpls_strcspn("", ""), strcspn("", ""));
  ck_assert_int_eq(strpls_strcspn(" \n\n", " "), strcspn(" \n\n", " "));
  ck_assert_int_eq(strpls_strcspn(" \n\n", strpls_NULL), -1);
  ck_assert_int_eq(strpls_strcspn(strpls_NULL, "\n\n"), -1);
}
END_TEST

START_TEST(strcspn_empty_strings) {
  const char *s = "";
  const char *reject = "";

  ck_assert(strcspn(s, reject) == strpls_strcspn(s, reject));
}
END_TEST

START_TEST(strcspn_empty_str) {
  const char *s = "";
  const char *reject = "sad ajsjqp 129291- 29s";

  ck_assert(strcspn(s, reject) == strpls_strcspn(s, reject));
}
END_TEST

START_TEST(strcspn_empty_reject) {
  const char *s = "asd quwi saj1 29219 \n";
  const char *reject = "";

  ck_assert(strcspn(s, reject) == strpls_strcspn(s, reject));
}
END_TEST

START_TEST(strcspn_zero_result) {
  const char *s = "1234asdda";
  const char *reject = "4321";

  ck_assert(strcspn(s, reject) == 0);
  ck_assert(strcspn(s, reject) == strpls_strcspn(s, reject));
}
END_TEST

START_TEST(strcspn_nonzero_result) {
  const char *s = "asdkaskak123456789 asdda";
  const char *reject = "987654321";

  ck_assert(strcspn(s, reject) != 0);
  ck_assert(strcspn(s, reject) == strpls_strcspn(s, reject));
}
END_TEST

// TEST strspn

START_TEST(test_strspn) {
  ck_assert_int_eq(strpls_strspn("0123456789", "210 "),
                   strspn("0123456789", "210 "));
  ck_assert_int_eq(strpls_strspn("\n", "\n"), strspn("\n", "\n"));
  ck_assert_int_eq(strpls_strspn("\n", ""), strspn("\n", ""));
  ck_assert_int_eq(strpls_strspn("", ""), strspn("", ""));
  ck_assert_int_eq(strpls_strspn("a aa aaabbbbb", "a "),
                   strspn("a aa aaabbbbb", "a "));
}
END_TEST

START_TEST(strspn_empty_strings) {
  const char *s = "";
  const char *accept = "";

  ck_assert(strspn(s, accept) == strpls_strspn(s, accept));
}
END_TEST

START_TEST(strspn_empty_str) {
  const char *s = "";
  const char *accept = "sad ajsjqp 129291- 29s";

  ck_assert(strspn(s, accept) == strpls_strspn(s, accept));
}
END_TEST

START_TEST(strspn_empty_accept) {
  const char *s = "asd quwi saj1 29219 \n";
  const char *accept = "";

  ck_assert(strspn(s, accept) == strpls_strspn(s, accept));
}
END_TEST

START_TEST(strspn_zero_result) {
  const char *s = "a1234asdda";
  const char *accept = "4321";

  ck_assert(strspn(s, accept) == 0);
  ck_assert(strspn(s, accept) == strpls_strspn(s, accept));
}
END_TEST

START_TEST(strspn_nonzero_result) {
  const char *s = "123456789 asdda";
  const char *accept = "987654321";

  ck_assert(strspn(s, accept) != 0);
  ck_assert(strspn(s, accept) == strpls_strspn(s, accept));
}
END_TEST

// TEST to_upper

START_TEST(test_to_upper) {
  char str1[128];
  char answ[128];
  char *tok1;
  char *tok2;

  strcpy(str1, "123 TeSt\n StRiNg");
  strcpy(answ, "123 TEST\n STRING");
  tok1 = strpls_to_upper(str1);
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  free(tok1);
}
END_TEST

START_TEST(to_upper_nil) {
  char *str1 = NULL;
  char *str2 = strpls_to_upper(str1);
  ck_assert_ptr_eq(str1, str2);
  free(str2);
}
END_TEST

START_TEST(to_upper_just_word) {
  char str1[11] = "helicopter";
  char *str2 = strpls_to_upper(str1);
  ck_assert_str_eq(str2, "HELICOPTER");
  free(str2);
}
END_TEST

START_TEST(to_upper_just_word_2) {
  char str1[] = "{helicopter}";
  char *str2 = strpls_to_upper(str1);
  ck_assert_str_eq(str2, "{HELICOPTER}");
  free(str2);
}
END_TEST

START_TEST(to_upper_few_words) {
  char str1[22] = "some more helicopters";
  char *str2 = strpls_to_upper(str1);
  ck_assert_str_eq(str2, "SOME MORE HELICOPTERS");
  free(str2);
}
END_TEST

START_TEST(to_upper_empty_string) {
  char str1[1] = "";
  char *str2 = strpls_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_upper_no_change) {
  char str1[15] = "NOT HELICOPTER";
  char *str2 = strpls_to_upper(str1);
  ck_assert_str_eq(str2, "NOT HELICOPTER");
  free(str2);
}
END_TEST

START_TEST(to_upper_word_with_number) {
  char str1[14] = "helicopter123";
  char *str2 = strpls_to_upper(str1);
  ck_assert_str_eq(str2, "HELICOPTER123");
  free(str2);
}
END_TEST

START_TEST(to_upper_end_symbol) {
  char str1[15] = "new\0helicopter";
  char *str2 = strpls_to_upper(str1);
  ck_assert_str_eq(str2, "NEW");
  free(str2);
}
END_TEST

// TEST to_lower

START_TEST(test_to_lower) {
  char str1[128];
  char answ[128];
  char *tok1;
  char *tok2;

  strcpy(str1, "123 TeSt\n StRiNg");
  strcpy(answ, "123 test\n string");
  tok1 = strpls_to_lower(str1);
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  free(tok1);
}
END_TEST

START_TEST(to_lower_nil) {
  char *str1 = NULL;
  char *str2 = strpls_to_lower(str1);
  ck_assert_ptr_eq(str1, str2);
  free(str2);
}
END_TEST

START_TEST(to_lower_just_word) {
  char str1[11] = "HELICOPTER";
  char *str2 = strpls_to_lower(str1);
  ck_assert_str_eq(str2, "helicopter");
  free(str2);
}
END_TEST

START_TEST(to_lower_just_word_2) {
  char str1[] = "!HELICOPTER!";
  char *str2 = strpls_to_lower(str1);
  ck_assert_str_eq(str2, "!helicopter!");
  free(str2);
}
END_TEST

START_TEST(to_lower_few_words) {
  char str1[22] = "SOME MORE HELICOPTERS";
  char *str2 = strpls_to_lower(str1);
  ck_assert_str_eq(str2, "some more helicopters");
  free(str2);
}
END_TEST

START_TEST(to_lower_empty_string) {
  char str1[1] = "";
  char *str2 = strpls_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_lower_no_change) {
  char str1[16] = "not helicopter";
  char *str2 = strpls_to_lower(str1);
  ck_assert_str_eq(str2, "not helicopter");
  free(str2);
}
END_TEST

START_TEST(to_lower_word_with_number) {
  char str1[14] = "HELICOPTER123";
  char *str2 = strpls_to_lower(str1);
  ck_assert_str_eq(str2, "helicopter123");
  free(str2);
}
END_TEST

START_TEST(to_lower_end_symbol) {
  char str1[15] = "NEW\0HELICOPTER";
  char *str2 = strpls_to_lower(str1);
  ck_assert_str_eq(str2, "new");
  free(str2);
}
END_TEST

// TEST trim

START_TEST(test_trim) {
  char str1[128];
  char answ[128];
  char *tok1;
  char *tok2;

  strcpy(str1, "- - - Test- - - ");
  strcpy(answ, "Test");
  tok1 = strpls_trim(str1, "- ");
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  if (tok1) {
    free(tok1);
    tok1 = strpls_NULL;
  }

  strcpy(str1, "- - - Test- - - ");
  strcpy(answ, "- - - Test- - - ");
  tok1 = strpls_trim(str1, "");
  tok2 = answ;
  ck_assert_str_eq(tok1, tok2);
  if (tok1) {
    free(tok1);
    tok1 = strpls_NULL;
  }

  strcpy(str1, "- - - Test- - -");
  tok1 = strpls_trim(str1, strpls_NULL);
  ck_assert_ptr_null(tok1);
}
END_TEST

START_TEST(trim_one_char) {
  char *str1 = "    a     ";
  char *str2 = " ";
  char *str3 = (char *)strpls_trim(str1, str2);
  ck_assert_str_eq(str3, "a");
  if (str3) {
    free(str3);
    str3 = strpls_NULL;
  }
}
END_TEST

START_TEST(trim_remove_char) {
  char *str1 = "New Helicopter";
  char *str2 = "N";
  char *str3 = (char *)strpls_trim(str1, str2);
  ck_assert_str_eq(str3, "ew Helicopter");
  if (str3) {
    free(str3);
    str3 = strpls_NULL;
  }
}
END_TEST

START_TEST(trim_remove_chars) {
  char *str1 = "New Helicoptner";
  char *str2 = "Ner";
  char *str3 = (char *)strpls_trim(str1, str2);
  ck_assert_str_eq(str3, "w Helicoptn");
  if (str3) {
    free(str3);
    str3 = strpls_NULL;
  }
}
END_TEST

START_TEST(trim_empty_string) {
  char *str1 = "";
  char *str2 = "";
  char *str3 = (char *)strpls_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  if (str3) {
    free(str3);
    str3 = strpls_NULL;
  }
}
END_TEST

START_TEST(trim_remove_all) {
  char *str = "empty";
  char *str2 = "empty";
  char *str3 = (char *)strpls_trim(str, str2);
  ck_assert_str_eq(str3, "");
  if (str3) {
    free(str3);
    str3 = strpls_NULL;
  }
}
END_TEST

START_TEST(trim_test_null) {
  char *str = strpls_NULL;
  char *str2 = strpls_NULL;
  char *str3 = (char *)strpls_trim(str, str2);
  ck_assert_ptr_eq(str3, strpls_NULL);
}
END_TEST

START_TEST(trim_remove_null) {
  char *str = "";
  char *str2 = strpls_NULL;
  char *str3 = (char *)strpls_trim(str, str2);
  ck_assert_ptr_eq(str3, strpls_NULL);
}
END_TEST

START_TEST(trim_remove_from_null) {
  char *str = strpls_NULL;
  char *str2 = "          ";
  char *str3 = (char *)strpls_trim(str, str2);
  ck_assert_ptr_eq(str3, strpls_NULL);
}
END_TEST

START_TEST(trim_dont_remove_extra) {
  char *str = "helicopter";
  char *str2 = "t";
  char *str3 = (char *)strpls_trim(str, str2);
  ck_assert_str_ne(str3, "helicop");
  if (str3) {
    free(str3);
    str3 = strpls_NULL;
  }
}
END_TEST

TCase *get_plus_tests(void) {
  TCase *tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strcspn);
  tcase_add_test(tc_core, strcspn_empty_strings);
  tcase_add_test(tc_core, strcspn_empty_str);
  tcase_add_test(tc_core, strcspn_empty_reject);
  tcase_add_test(tc_core, strcspn_zero_result);
  tcase_add_test(tc_core, strcspn_nonzero_result);

  tcase_add_test(tc_core, test_strspn);
  tcase_add_test(tc_core, strspn_empty_strings);
  tcase_add_test(tc_core, strspn_empty_str);
  tcase_add_test(tc_core, strspn_empty_accept);
  tcase_add_test(tc_core, strspn_zero_result);
  tcase_add_test(tc_core, strspn_nonzero_result);

  tcase_add_test(tc_core, test_insert);
  tcase_add_test(tc_core, insert_two_words);
  tcase_add_test(tc_core, insert_check_for_error_null);
  tcase_add_test(tc_core, insert_split_word);
  tcase_add_test(tc_core, insert_add_to_null);
  tcase_add_test(tc_core, insert_add_to_start);
  tcase_add_test(tc_core, insert_wrong_location);
  tcase_add_test(tc_core, insert_to_null);
  tcase_add_test(tc_core, insert_string_size_check);
  tcase_add_test(tc_core, insert_null_to_null);
  tcase_add_test(tc_core, insert_empty_addition);

  tcase_add_test(tc_core, test_to_lower);
  tcase_add_test(tc_core, to_lower_nil);
  tcase_add_test(tc_core, to_lower_just_word);
  tcase_add_test(tc_core, to_lower_just_word_2);
  tcase_add_test(tc_core, to_lower_few_words);
  tcase_add_test(tc_core, to_lower_empty_string);
  tcase_add_test(tc_core, to_lower_no_change);
  tcase_add_test(tc_core, to_lower_word_with_number);
  tcase_add_test(tc_core, to_lower_end_symbol);

  tcase_add_test(tc_core, test_to_upper);
  tcase_add_test(tc_core, to_upper_nil);
  tcase_add_test(tc_core, to_upper_just_word);
  tcase_add_test(tc_core, to_upper_just_word_2);
  tcase_add_test(tc_core, to_upper_few_words);
  tcase_add_test(tc_core, to_upper_empty_string);
  tcase_add_test(tc_core, to_upper_no_change);
  tcase_add_test(tc_core, to_upper_word_with_number);
  tcase_add_test(tc_core, to_upper_end_symbol);

  tcase_add_test(tc_core, test_trim);
  tcase_add_test(tc_core, trim_one_char);
  tcase_add_test(tc_core, trim_remove_char);
  tcase_add_test(tc_core, trim_remove_chars);
  tcase_add_test(tc_core, trim_empty_string);
  tcase_add_test(tc_core, trim_remove_all);
  tcase_add_test(tc_core, trim_test_null);
  tcase_add_test(tc_core, trim_remove_null);
  tcase_add_test(tc_core, trim_remove_from_null);
  tcase_add_test(tc_core, trim_dont_remove_extra);

  return tc_core;
}
