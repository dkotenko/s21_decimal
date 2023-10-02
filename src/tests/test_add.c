#include "tests.h"

START_TEST(test_add_positive) {

	
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