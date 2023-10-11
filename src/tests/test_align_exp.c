#include "tests.h"

START_TEST(s21_align_exponent) {
  s21_decimal d1 = s21_new_decimal(10245, 0, 0, 3, SIGN_POSITIVE);
  s21_decimal d2 = s21_new_decimal(102450, 0, 0, 4, SIGN_POSITIVE);

  align_exponent(&d1, &d2);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
} END_TEST

Suite *align_exp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Align exponent");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_align_exponent);
  suite_add_tcase(s, tc_core);

  return s;
}