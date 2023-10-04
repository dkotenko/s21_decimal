#include "tests.h"

START_TEST(test_f_to_demical) {
	float f = 10.245f;
	
  s21_decimal expected = s21_new_decimal(10245, 0, 0, 3, SIGN_POSITIVE);
  s21_decimal actual;
  s21_from_float_to_decimal(f, &actual);


  s21_print_decimal_bits(expected);
  s21_print_decimal_bits(actual);
  ck_assert_int_eq(s21_is_equal(expected, actual), true);
	
} END_TEST

Suite *conversion_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("conversion");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_f_to_demical);
  suite_add_tcase(s, tc_core);

  return s;
}