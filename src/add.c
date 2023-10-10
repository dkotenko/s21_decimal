#include "s21_decimal.h"


int s21_add(s21_decimal v1, s21_decimal v2, s21_decimal *result) {
	if (v1.sign != v2.sign) {
		if (v1.sign == SIGN_POSITIVE && v2.sign == SIGN_NEGATIVE) {
			v2.sign = SIGN_POSITIVE;
			return s21_sub(v1, v2, result);
		} else if (v1.sign == SIGN_NEGATIVE && v2.sign == SIGN_POSITIVE) {
			v1.sign = SIGN_POSITIVE;
			return s21_sub(v2, v1, result);
		}
	}
	
	if (v1.sign == SIGN_NEGATIVE) 
	{
		result->sign = SIGN_NEGATIVE;
	}
	
	if (v1.exponent != v2.exponent) {
		align_exponent(&v1, &v2);
	}
	result->exponent = v1.exponent;

	uint32_t temp_arr[4] = {0};
	int64_t prev = 0;
	int64_t temp;
	for (int i = 0; i < 3; i++) {
		temp = (int64_t)v1.bits[i] + v2.bits[i] + prev;
		prev = temp / S21_DECIMAL_BASE;
		temp_arr[i] = temp % S21_DECIMAL_BASE;
	}

	temp_arr[3] = prev;
	while (temp_arr[3] > 0) {
		s21_divide_array(temp_arr, 4, 10);
		result->exponent--;
		if (result->exponent < S21_DECIMAL_MIN_EXPONENT) {
			return ERR_TOO_SMALL;
		}
	}
	memcpy(result->bits, temp_arr, sizeof(int) * 3);
	return NO_ERR;
} 