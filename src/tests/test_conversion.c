#include "tests.h"

START_TEST(test_f_to_demical) {
	float f = 12.345f;
	
  s21_decimal expected = s21_new_decimal(12345, 0, 0, 3, SIGN_POSITIVE);
  s21_decimal actual;
  s21_from_float_to_decimal(f, &actual);

  printf("expected: ");
  s21_print_decimal_bits(expected);
  printf("actual:   ");
  s21_print_decimal_bits(actual);
  ck_assert_int_eq(s21_is_equal(expected, actual), true);
	
} END_TEST

START_TEST(test_int_to_demical) {
	int values[3] = {
    123456, 0, INT_MAX
  };
	
  for (int i = 0; i < 3; i++) {
    s21_decimal expected = s21_new_decimal(values[i], 0, 0, 0, values[i] < 0);
    s21_decimal actual;
    s21_from_int_to_decimal(values[i], &actual);

    printf("expected: ");
    s21_print_decimal_bits(expected);
    printf("actual:   ");
    s21_print_decimal_bits(actual);
    ck_assert_int_eq(s21_is_equal(expected, actual), true);
  }
} END_TEST

Suite *conversion_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("conversion");
  tc_core = tcase_create("Core");

  (void)test_int_to_demical;
  tcase_add_test(tc_core, test_f_to_demical);
  //tcase_add_test(tc_core, test_int_to_demical);
  suite_add_tcase(s, tc_core);

  return s;
}