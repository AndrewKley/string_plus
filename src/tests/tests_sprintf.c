#include "tests.h"

START_TEST(percent_test) {
  char str[100] = {0};
  char str1[100] = {0};
  strpls_sprintf(str, "%%");
  sprintf(str1, "%%");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(percent_test2) {
  char str[100] = {0};
  char str1[100] = {0};
  strpls_sprintf(str, "%%asd");
  sprintf(str1, "%%asd");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(percent_test3) {
  char str[100] = {0};
  char str1[100] = {0};
  strpls_sprintf(str, "% %asd");
  sprintf(str1, "%%asd");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(c_test) {
  char str[100] = {0};
  char str1[100] = {0};
  strpls_sprintf(str, "%c", 'a');
  sprintf(str1, "%c", 'a');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(c_test2) {
  char str[100] = {0};
  char str1[100] = {0};
  strpls_sprintf(str, "%casd", 'a');
  sprintf(str1, "%casd", 'a');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(c_test3) {
  char str[100] = {0};
  char str1[100] = {0};
  strpls_sprintf(str, "%c words", 'a');
  sprintf(str1, "%c words", 'a');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(d_test) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%d", 10);
  sprintf(str1, "%d", 10);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% d", 32000);
  sprintf(str1, "% d", 32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+d", -2345);
  sprintf(str1, "%+d", -2345);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%d some words", 0);
  sprintf(str1, "%d some words", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(flag_test) {
  char str[100] = {0};
  char str1[100] = {0};
  strpls_sprintf(str, "% d some words", 10);
  sprintf(str1, "% d some words", 10);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%04d some words", 10);
  sprintf(str1, "%04d some words", 10);
  ck_assert_pstr_eq(str, str1);
}
END_TEST

START_TEST(flag_test2) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%-d some word", 32000);
  sprintf(str1, "%-d some word", 32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+d some words", 32000);
  sprintf(str1, "%+d some words", 32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%.d some words", 32000);
  sprintf(str1, "%.d some words", 32000);
  ck_assert_str_eq(str, str1);

  char tstr[100] = "%  d some words";
  tstr[2] = '2';
  strpls_sprintf(str, tstr, 32000);
  sprintf(str1, tstr, 32000);
  ck_assert_str_eq(str, str1);

  tstr[2] = '1';
  strpls_sprintf(str, tstr, 32000);
  sprintf(str1, tstr, 32000);
  ck_assert_str_eq(str, str1);

  tstr[3] = 'c';
  strpls_sprintf(str, tstr, 32000);
  sprintf(str1, tstr, 32000);
  ck_assert_str_ne(str, str1);
}
END_TEST

START_TEST(flag_test3) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%-d some words", -32000);
  sprintf(str1, "%-d some words", -32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% d some word", -32000);
  sprintf(str1, "% d some word", -32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+d some word", -32000);
  sprintf(str1, "%+d some word", -32000);
  ck_assert_str_eq(str, str1);

  char tstr[100] = "%5 d some words";
  tstr[2] = '2';
  strpls_sprintf(str, tstr, -32000);
  sprintf(str1, tstr, -32000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(width_test) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%10d some words", -32000);
  sprintf(str1, "%10d some words", -32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% 10d some word", -32000);
  sprintf(str1, "% 10d some word", -32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+10d some word", -32000);
  sprintf(str1, "%+10d some word", -32000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(width_test2) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%10d some words", 32000);
  sprintf(str1, "%10d some words", 32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% 10d some word", 32000);
  sprintf(str1, "% 10d some word", 32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+10d some word", 32000);
  sprintf(str1, "%+10d some word", 32000);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%10x some word", -32000);
  sprintf(str1, "%10x some word", -32000);
  ck_assert_pstr_eq(str, str1);
}
END_TEST

START_TEST(width_test3) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%37d some words", 0);
  sprintf(str1, "%37d some words", 0);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% 37d some word", 0);
  sprintf(str1, "% 37d some word", 0);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+37d some word", 0);
  sprintf(str1, "%+37d some word", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(i_test) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%i", -0xA);
  sprintf(str1, "%i", -0xA);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% i", 0x7D00);
  sprintf(str1, "% i", 0x7D00);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%i", -02345);
  sprintf(str1, "%i", -02345);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%i some words", 0);
  sprintf(str1, "%i some words", 0);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%-i some word", 76400);
  sprintf(str1, "%-i some word", 76400);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+i some words", 012);
  sprintf(str1, "%+i some words", 012);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%.i some words", 076400);
  sprintf(str1, "%.i some words", 076400);
  ck_assert_str_eq(str, str1);

  char tstr[100] = "%  i some words";
  tstr[2] = '2';
  strpls_sprintf(str, tstr, -32000);
  sprintf(str1, tstr, -32000);
  ck_assert_pstr_eq(str, str1);
  tstr[2] = '1';
  strpls_sprintf(str, tstr, 32000);
  sprintf(str1, tstr, 32000);
  ck_assert_str_eq(str, str1);

  tstr[3] = 'c';
  strpls_sprintf(str, tstr, 32000);
  sprintf(str1, tstr, 32000);
  ck_assert_str_ne(str, str1);
}
END_TEST

START_TEST(f_test) {
  char str[100] = {0};
  char str1[100] = {0};
  float num = 0.00f;

  strpls_sprintf(str, "%f", num);
  sprintf(str1, "%f", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% f", num);
  sprintf(str1, "% f", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%f some words", num);
  sprintf(str1, "%f some words", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%-f some word", num);
  sprintf(str1, "%-f some word", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+f some words", num);
  sprintf(str1, "%+f some words", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%.f some words", num);
  sprintf(str1, "%.f some words", num);
  ck_assert_str_eq(str, str1);

  char tstr[100] = "%  f some words";
  tstr[2] = '1';
  strpls_sprintf(str, tstr, num);
  sprintf(str1, tstr, num);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(f_test2) {
  char str[100] = {0};
  char str1[100] = {0};
  float num = 23435.23f;

  strpls_sprintf(str, "%f", num);
  sprintf(str1, "%f", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% f", num);
  sprintf(str1, "% f", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%f some words", num);
  sprintf(str1, "%f some words", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%-f some word", num);
  sprintf(str1, "%-f some word", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+f some words", num);
  sprintf(str1, "%+f some words", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%.f some words", num);
  sprintf(str1, "%.f some words", num);
  ck_assert_pstr_eq(str, str1);

  char tstr[100] = "%  f some words";
  tstr[2] = '2';
  strpls_sprintf(str, tstr, -num);
  sprintf(str1, tstr, -num);
  ck_assert_str_eq(str, str1);

  tstr[2] = '1';
  strpls_sprintf(str, tstr, num);
  sprintf(str1, tstr, num);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(f_test3) {
  char str[100] = {0};
  char str1[100] = {0};
  float num = -140.35346f;

  strpls_sprintf(str, "%f", num);
  sprintf(str1, "%f", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "% f", num);
  sprintf(str1, "% f", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%f some words", num);
  sprintf(str1, "%f some words", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%-f some word", num);
  sprintf(str1, "%-f some word", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+f some words", num);
  sprintf(str1, "%+f some words", num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%.f some words", num);
  sprintf(str1, "%.f some words", num);
  ck_assert_pstr_eq(str, str1);

  char tstr[100] = "%  f some words";
  tstr[2] = '2';
  strpls_sprintf(str, tstr, -num);
  sprintf(str1, tstr, -num);
  ck_assert_str_eq(str, str1);

  tstr[2] = '1';
  strpls_sprintf(str, tstr, num);
  sprintf(str1, tstr, num);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(str_test) {
  char str[300] = {0};
  char str1[300] = {0};
  char tstr[100] =
      "some words and some numbers: fresh, rebel, string, 153, 353.345";

  char sstr[100] = "%s";
  char sstr1[100] = "%s$$ backs";
  char fstr[100] = "% s";

  strpls_sprintf(str, sstr, tstr);
  sprintf(str1, sstr, tstr);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, fstr, tstr);
  sprintf(str1, fstr, tstr);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, sstr1, tstr);
  sprintf(str1, sstr1, tstr);
  ck_assert_str_eq(str, str1);

  tstr[6] = '\0';
  strpls_sprintf(str, sstr, tstr);
  sprintf(str1, sstr, tstr);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(u_test) {
  char str[100] = {0};
  char str1[100] = {0};

  strpls_sprintf(str, "%u", (unsigned int)-0xA);
  sprintf(str1, "%u", (unsigned int)-0xA);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%u", (unsigned int)0x7D00);
  sprintf(str1, "%u", (unsigned int)0x7D00);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%u", (unsigned int)-02345);
  sprintf(str1, "%u", (unsigned int)-02345);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%u some words", (unsigned int)0);
  sprintf(str1, "%u some words", (unsigned int)0);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%-u some word", (unsigned int)76400);
  sprintf(str1, "%-u some word", (unsigned int)76400);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%u some words", (unsigned int)012);
  sprintf(str1, "%u some words", (unsigned int)012);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%.u some words", (unsigned int)076400);
  sprintf(str1, "%.u some words", (unsigned int)076400);
  ck_assert_str_eq(str, str1);

  char tstr[100] = "%  u some words";
  tstr[2] = '2';
  strpls_sprintf(str, tstr, -32000);
  sprintf(str1, tstr, -32000);
  ck_assert_str_eq(str, str1);

  tstr[2] = '1';
  strpls_sprintf(str, tstr, 32000);
  sprintf(str1, tstr, 32000);
  ck_assert_str_eq(str, str1);

  tstr[3] = 'c';
  strpls_sprintf(str, tstr, 32000);
  sprintf(str1, tstr, 32000);
  ck_assert_str_ne(str, str1);
}
END_TEST

START_TEST(length_test) {
  char str[100] = {0};
  char str1[100] = {0};
  char tstr[100] =
      "some words and some numbers: fresh, rebel, string, 153, 353.345";
  unsigned int num = 0xAF;

  strpls_sprintf(str, "%%some words %lc", (wint_t)'a');
  sprintf(str1, "%%some words %lc", (wint_t)'a');
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%hd%% $$$ %lcletters", (short int)-2345, (wint_t)'V');
  sprintf(str1, "%hd%% $$$ %lcletters", (short int)-2345, (wint_t)'V');
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%4ld some%s words", (long int)10, &tstr[30]);
  sprintf(str1, "%4ld some%s words", (long int)10, tstr + 40);
  ck_assert_str_ne(str, str1);

  strpls_sprintf(str, "%-hu some wo%urd", (unsigned short int)-32000.3523, num);
  sprintf(str1, "%-hu some wo%urd", (unsigned short int)-32000.3523, num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%ld some %% %4hi% fwords", (long int)-2, (short)40,
              3.2516357352);
  sprintf(str1, "%ld some %% %4hi% fwords", (long int)-2, (short)40,
          3.2516357352);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%+5ld some %% %4lu% fwords", (long int)-2,
              (unsigned long int)40, 3.2516357352);
  sprintf(str1, "%+5ld some %% %4lu% fwords", (long int)-2,
          (unsigned long int)40, 3.2516357352);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%*f some %% %4lc% fwords", 5, -2., (wint_t)45,
              3.2516357352);
  sprintf(str1, "%*f some %% %4lc% fwords", 5, -2., (wint_t)45, 3.2516357352);
  ck_assert_str_eq(str, str1);

  char tstr1[100] = "Hi mazafi %.hi some %-lswor%%ds";

  tstr1[10] = '\0';
  strpls_sprintf(str, tstr1, 076400, (wchar_t *)L"Hello World!");
  sprintf(str1, tstr1, 076400, (wchar_t *)L"Hello World!");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(combination_test) {
  char str[100] = {0};
  char str1[100] = {0};
  char tstr[100] =
      "some words and some numbers: fresh, rebel, string, 153, 353.345";
  unsigned int num = 0xAF;

  strpls_sprintf(str, "%s%d", UERROR, (int)-123);
  sprintf(str1, "%s%d", UERROR, (int)-123);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%%some words %c", 'a');
  sprintf(str1, "%%some words %c", 'a');
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%d%% $$$ %cletters", -2345, 'V');
  sprintf(str1, "%d%% $$$ %cletters", -2345, 'V');
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%04d some%s words", 10, &tstr[30]);
  sprintf(str1, "%04d some%s words", 10, tstr + 40);
  ck_assert_str_ne(str, str1);

  strpls_sprintf(str, "%-.*f some wo%urd", 8, -32000.3523, num);
  sprintf(str1, "%-.*f some wo%urd", 8, -32000.3523, num);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%d some %% %4i% fwords", -2, 40, 3.2516357352);
  sprintf(str1, "%d some %% %4i% fwords", -2, 40, 3.2516357352);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%f some %% %4c% fwords", -2., 45, 3.2516357352);
  sprintf(str1, "%f some %% %4c% fwords", -2., 45, 3.2516357352);
  ck_assert_str_eq(str, str1);

  strpls_sprintf(str, "%c some%c words%s", '\n', 'B', "Hello World!");
  sprintf(str1, "%c some%c words%s", '\n', 'B', "Hello World!");
  ck_assert_str_eq(str, str1);

  char tstr1[100] = "Hi mazafi %.i some %-swor%%ds";
  strpls_sprintf(str, tstr1, 076400, "Hello World!");
  sprintf(str1, tstr1, 076400, "Hello World!");
  ck_assert_str_eq(str, str1);

  tstr1[10] = '\0';
  strpls_sprintf(str, tstr1, 076400, "Hello World!");
  sprintf(str1, tstr1, 076400, "Hello World!");
  ck_assert_str_eq(str, str1);
}
END_TEST

TCase *get_sprintf_case(void) {
  TCase *sprintf_case = tcase_create("strpls_sprintf_test");

  tcase_add_test(sprintf_case, percent_test);
  tcase_add_test(sprintf_case, percent_test2);
  tcase_add_test(sprintf_case, percent_test3);

  tcase_add_test(sprintf_case, c_test);
  tcase_add_test(sprintf_case, c_test2);
  tcase_add_test(sprintf_case, c_test3);

  tcase_add_test(sprintf_case, d_test);

  tcase_add_test(sprintf_case, i_test);

  tcase_add_test(sprintf_case, f_test);
  tcase_add_test(sprintf_case, f_test2);
  tcase_add_test(sprintf_case, f_test3);

  tcase_add_test(sprintf_case, str_test);

  tcase_add_test(sprintf_case, u_test);

  tcase_add_test(sprintf_case, flag_test);
  tcase_add_test(sprintf_case, flag_test2);
  tcase_add_test(sprintf_case, flag_test3);

  tcase_add_test(sprintf_case, width_test);
  tcase_add_test(sprintf_case, width_test2);
  tcase_add_test(sprintf_case, width_test3);

  tcase_add_test(sprintf_case, length_test);

  tcase_add_test(sprintf_case, combination_test);

  return sprintf_case;
}
