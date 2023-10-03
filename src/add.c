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


	int64_t temp[4] = {0};
	int64_t prev = 0;
	for (int i = 0; i < 3; i++) {
		temp[i] = (int64_t)v1.bits[i] + v2.bits[i] + prev;
		prev = temp[i] / S21_DECIMAL_BASE;
		temp[i] %= S21_DECIMAL_BASE;
	}

	temp[3] = prev;
	int exp_minus = 0;
	while (temp[3] > 0) {
		s21_divide_array()(temp, 10
		);//функция находится в support_func
		exp_minus++;
	}
    
	for (int i = 0; i < 3; i++) {
		result->bits[i] = (int)temp[i];
		result->exponent-=exp_minus;
	}

	return NO_ERR;
} 