#include "tests.h"

Suite *align_exp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Free matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_free_matrix);
  suite_add_tcase(s, tc_core);

  return s;
}