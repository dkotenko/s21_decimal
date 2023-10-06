#include "tests.h"

START_TEST(test_add_positive) {
  s21_decimal d1, d2, result, result_to_eq;

  // -21474836,47
  d1 = s21_new_decimal(2147483647, 0, 0, 2, 1);
	s21_print_decimal_bits(d1);

  // -0,01
  d2 = s21_new_decimal(1, 0, 0, 2, 1);

  // -21474836,48
  result_to_eq = s21_new_decimal(2147483648, 0, 0, 2, 1);

	result = s21_new_decimal(0, 0, 0, 0, 0);
  
  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // -21474836,47 + (-0,01) = -21474836,48; 

	s21_print_decimal_bits(result);
	s21_print_decimal_bits(result_to_eq);

  // 1
    d1 = s21_new_decimal(1, 0, 0, 0, 0);

  // 2  
    d2 = s21_new_decimal(2, 0, 0, 0, 0);

  // 3
    result_to_eq = s21_new_decimal(3, 0, 0, 0, 0);

  // 0
    result = s21_new_decimal(0, 0, 0, 0, 0);

  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(result.bits[0], result_to_eq.bits[0]);  // 1+2 = 3;

  // -1
  d1.sign = 1;
  // -2
  d2.sign = 1;
  // -3
  result_to_eq.sign = 1;
  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // (-1)+(-2) = -3;

    // 16
  d1 = s21_new_decimal(16, 0, 0, 0, 0);

  // 21.6
  d2 = s21_new_decimal(216, 0, 0, 1, 0);

  // 37.6
  result_to_eq = s21_new_decimal(376, 0, 0, 1, 0);

  result = s21_new_decimal(0, 0, 0, 0, 0);

  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // 16 + 21,6 = 37,6; 

      // -16
  d1 = s21_new_decimal(16, 0, 0, 0, 1);

  // -21.6
  d2 = s21_new_decimal(216, 0, 0, 1, 1);

  // -37.6
  result_to_eq = s21_new_decimal(376, 0, 0, 1, 1);

  result = s21_new_decimal(0, 0, 0, 0, 0);

  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // -16 + (-21,6) = -37,6; 

        // 12,345678
  d1 = s21_new_decimal(12345678, 0, 0, 6, 0);

  // 1,7
  d2 = s21_new_decimal(17, 0, 0, 1, 0);

  // 14,045678
  result_to_eq = s21_new_decimal(14045678, 0, 0, 6, 0);

  result = s21_new_decimal(0, 0, 0, 0, 0);

  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // 12,345678 + 1,7 = 14,045678;

        // -12,345678
  d1 = s21_new_decimal(12345678, 0, 0, 6, 1);

  // -1,7
  d2 = s21_new_decimal(17, 0, 0, 1, 1);

  // -14,045678
  result_to_eq = s21_new_decimal(14045678, 0, 0, 6, 1);

  result = s21_new_decimal(0, 0, 0, 0, 0);

  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // -12,345678 + (-1,7) = -14,045678;

    // 0
  d1 = s21_new_decimal(0, 0, 0, 0, 0);

  // 1,7
  d2 = s21_new_decimal(17, 0, 0, 1, 0);

  // 1,7
  result_to_eq = s21_new_decimal(17, 0, 0, 1, 0);

  result = s21_new_decimal(0, 0, 0, 0, 0);


  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // 0 + 1,7 = 1,7;

      // 0,0
  d1 = s21_new_decimal(0, 0, 0, 1, 0);

  // 1,7
  d2 = s21_new_decimal(17, 0, 0, 1, 0);

  // 1,7
  result_to_eq = s21_new_decimal(17, 0, 0, 1, 0);

  result = s21_new_decimal(0, 0, 0, 0, 0);


  ck_assert_int_eq(s21_add(d1, d2, &result), 0);  // функция возвращает 0;
  ck_assert_int_eq(s21_is_equal(result, result_to_eq), 1);  // 0,0 + 1,7 = 1,7;

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