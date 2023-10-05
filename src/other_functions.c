#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  decimal_copy(result, value);
  if (value.bits[0] != 0 || value.bits[1] != 0 || value.bits[2] != 0) {
    if(value.sign == 1 ) {
    result->sign = 0;
    } else {result->sign = 1;}
  }
  return 0;
}