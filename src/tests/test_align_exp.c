#include "tests.h"

START_TEST(s21_align_exponent) {

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