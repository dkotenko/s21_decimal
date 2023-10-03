#include "tests.h"

START_TEST(test_add_positive) {
  s21_decimal d1 = s21_new_decimal(2147483647, 0, 0, 2, 1);
  s21_decimal d2 = s21_new_decimal(1, 0, 0, 2, 1);
	s21_decimal result = s21_new_decimal(0, 0, 0, 0, 0);
  s21_add(d1, d2, &result);
  
	s21_print_decimal_bits(result);
} END_TEST

Suite *add_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Add decimal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_add_positive);
  suite_add_tcase(s, tc_core);

  return s;
}