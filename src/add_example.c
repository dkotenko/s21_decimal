#include "s21_decimal.h"

int s21_add(s21_decimal v1, s21_decimal v2, s21_decimal *result) {
	if (v1.sign > 0 && v2.sign < 0) {
		return s21_sub(v1, v2, result);
	} else if (v1.sign < 0 && v2.sign > 0) {
		return s21_sub(v2, v1, result);
	}
	
	if (v1.exponent != v2.exponent) {
		align_exponent(&v1, &v2);
	}
	
	return NO_ERR;
}