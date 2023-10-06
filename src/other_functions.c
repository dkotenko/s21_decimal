#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  decimal_copy(result, value);
  if (value.bits[0] != 0 || value.bits[1] != 0 || value.bits[2] != 0) {
    if(value.sign == SIGN_NEGATIVE ) {
    result->sign = SIGN_POSITIVE;
    } else {result->sign = SIGN_NEGATIVE;}
  }
  return 0;
}