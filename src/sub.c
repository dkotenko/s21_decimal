#include "s21_decimal.h"

int s21_sub(s21_decimal v1, s21_decimal v2, s21_decimal *result) {
	if (v1.sign == SIGN_NEGATIVE) {
		if (v2.sign == SIGN_NEGATIVE) {
			(void)result;
		}
	}
	return NO_ERR;
}