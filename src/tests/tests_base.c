#include "tests.h"

START_TEST(strcpy_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "MARIO CASSAR LONGEST!";
  ck_assert_pstr_eq(strcpy(b1, str_1_2), strpls_strcpy(b11, str_1_2));
}
END_TEST

START_TEST(strcpy_2) {
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_str_eq(strcpy(b2, str_2_2), strpls_strcpy(b22, str_2_2));
}
END_TEST

START_TEST(strcpy_3) {
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "MARIO";
  ck_assert_str_eq(strcpy(b3, str_3_2), strpls_strcpy(b33, str_3_2));
}
END_TEST

START_TEST(strncpy_0) {
  char s1[50] = "1234567890";
  char s2[50] = "1234567890";
  char s3[] = "5321";
  strpls_size_t n = 10;
  ck_assert_pstr_eq(strncpy(s1, s3, n), strpls_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_1) {
  strpls_size_t n1 = 3;
  char b1[1024] = "1111111111";
  char b11[1024] = "1111111111";
  char str_1_2[1024] = "123^0";

  char *s, *s1;
  s = strncpy(b1, str_1_2, n1);
  s1 = strpls_strncpy(b11, str_1_2, n1);
  // ck_assert_str_eq(strncpy(b1, str_1_2, n1), strpls_strncpy(b11, str_1_2, n1));
  ck_assert_str_eq(s, s1);
}
END_TEST

START_TEST(strncpy_2) {
  strpls_size_t n2 = 20;
  char b2[1024] = "1111";
  char b22[1024] = "1111";
  char str_2_2[1024] = "some words some letters";
  ck_assert_str_eq(strncpy(b2, str_2_2, n2), strpls_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncpy_3) {
  strpls_size_t n3 = 5;
  char b3[1024] = "11";
  char b33[1024] = "11";
  char str_3_2[1024] = "12345\0006789";
  ck_assert_str_eq(strncpy(b3, str_3_2, n3), strpls_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncpy_4) {
  strpls_size_t n2 = 20;
  char b2[1024] = "1111";
  char b22[1024] = "1111";
  char str_2_2[1024] = "words";

  char *s, *s1;
  s = strncpy(b2, str_2_2, n2);
  s1 = strpls_strncpy(b22, str_2_2, n2);

  ck_assert_str_eq(s, s1);
}
END_TEST

START_TEST(strrchr_0) {
  char str[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str, '\0'), strpls_strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_1) {
  char str[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str, '6'), strpls_strrchr(str, '6'));
}
END_TEST

START_TEST(strrchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str2, 'o'), strpls_strrchr(str2, 'o'));
}
END_TEST

START_TEST(strrchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str3, 'h'), strpls_strrchr(str3, 'h'));
}
END_TEST

START_TEST(strrchr_4) {
  char str4[] = "";
  ck_assert_pstr_eq(strrchr(str4, 'd'), strpls_strrchr(str4, 'd'));
}
END_TEST

START_TEST(strrchr_5) {
  char str5[] = {""};
  ck_assert_pstr_eq(strrchr(str5, 'z'), strpls_strrchr(str5, 'z'));
}
END_TEST

START_TEST(strpbrk_1) {
  char str[] = "this_is_a_";
  ck_assert_pstr_eq(strpbrk(str, "369"), strpls_strpbrk(str, "369"));
}
END_TEST

START_TEST(strpbrk_2) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strpbrk(str2, "fzx"), strpls_strpbrk(str2, "fzx"));
}
END_TEST

START_TEST(strpbrk_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strpbrk(str3, "saq"), strpls_strpbrk(str3, "saq"));
}
END_TEST

START_TEST(strstr_1) {
  char str[] = "";
  ck_assert_pstr_eq(strstr(str, ""), strpls_strstr(str, ""));
}
END_TEST

START_TEST(strstr_2) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strstr(str2, "sm"), strpls_strstr(str2, "sm"));
}
END_TEST

START_TEST(strstr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strstr(str3, "woo"), strpls_strstr(str3, "woo"));
}
END_TEST

START_TEST(strtok_1) {
  char str4_1[] = "/testing/with/original/string.h/";
  char str4_2[] = "/testing/with/original/string.h/";
  char del4[3] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = strpls_strtok(str4_2, del4);
  while (nstr_1 != strpls_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(strpls_NULL, del4);
    nstr_2 = strpls_strtok(strpls_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str4_1[] = ". . testing with original string.h";
  char str4_2[] = ". . testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = strpls_strtok(str4_2, del4);
  while (nstr_1 != strpls_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(strpls_NULL, del4);
    nstr_2 = strpls_strtok(strpls_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_3) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = strpls_strtok(str4_2, del4);
  while (nstr_1 != strpls_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(strpls_NULL, del4);
    nstr_2 = strpls_strtok(strpls_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_4) {
  char str4_1[] = " ";
  char str4_2[] = " ";
  char del4[3] = " ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = strpls_strtok(str4_2, del4);
  ck_assert_pstr_eq(nstr_1, nstr_2);
}
END_TEST

START_TEST(strtok_5) {
  char str4_1[] = " te st ";
  char str4_2[] = " te st ";
  char del4[3] = " ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = strpls_strtok(str4_2, del4);
  while (nstr_1 != strpls_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(strpls_NULL, del4);
    nstr_2 = strpls_strtok(strpls_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_correct_token_string) {
  char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_token_string) {
  char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_unary_delimiters) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_no_delims) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    ck_assert_ptr_null(got);
    ck_assert_ptr_null(expected);
  }
}
END_TEST

START_TEST(strtok_only_delims) {
  char str1[] = "++++++++";
  char str2[] = "++++++++";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(strtok_too_many_uses_non_segfault) {
  char str1[] = "Aboba_Floppa_Roba";
  char str2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  int i = 5;
  while (i) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    i--;
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_even_n_of_delims) {
  char str1[] = "Roba++++Kepa++A++++B__V";
  char str2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_odd_n_of_delims) {
  char str1[] = "Aboba__+Floppa_  Roba";
  char str2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_n_of_delims) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_mixed) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_hard_incorrect) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_very_hard_mixed) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";
  char *got = strpls_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = strpls_strtok(strpls_NULL, delims);
    expected = strtok(strpls_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(strpls_strlen(got), strpls_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

TCase *get_base_tests(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strcpy_1);
  tcase_add_test(tcase, strcpy_2);
  tcase_add_test(tcase, strcpy_3);
  tcase_add_test(tcase, strncpy_0);
  tcase_add_test(tcase, strncpy_1);
  tcase_add_test(tcase, strncpy_2);
  tcase_add_test(tcase, strncpy_3);
  tcase_add_test(tcase, strncpy_4);
  tcase_add_test(tcase, strrchr_0);
  tcase_add_test(tcase, strrchr_1);
  tcase_add_test(tcase, strrchr_2);
  tcase_add_test(tcase, strrchr_3);
  tcase_add_test(tcase, strrchr_4);
  tcase_add_test(tcase, strrchr_5);
  tcase_add_test(tcase, strpbrk_1);
  tcase_add_test(tcase, strpbrk_2);
  tcase_add_test(tcase, strpbrk_3);
  tcase_add_test(tcase, strstr_1);
  tcase_add_test(tcase, strstr_2);
  tcase_add_test(tcase, strstr_3);
  tcase_add_test(tcase, strtok_1);
  tcase_add_test(tcase, strtok_2);
  tcase_add_test(tcase, strtok_3);
  tcase_add_test(tcase, strtok_4);
  tcase_add_test(tcase, strtok_5);
  tcase_add_test(tcase, strtok_correct_token_string);
  tcase_add_test(tcase, strtok_hard_token_string);
  tcase_add_test(tcase, strtok_unary_delimiters);
  tcase_add_test(tcase, strtok_no_delims);
  tcase_add_test(tcase, strtok_only_delims);
  tcase_add_test(tcase, strtok_too_many_uses_non_segfault);
  tcase_add_test(tcase, strtok_even_n_of_delims);
  tcase_add_test(tcase, strtok_odd_n_of_delims);
  tcase_add_test(tcase, strtok_mixed_n_of_delims);
  tcase_add_test(tcase, strtok_hard_mixed);
  tcase_add_test(tcase, strtok_mixed_hard_incorrect);
  tcase_add_test(tcase, strtok_very_hard_mixed);

  return tcase;
}
