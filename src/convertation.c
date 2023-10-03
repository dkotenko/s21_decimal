#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
	if (src == INT_MIN) {
		dst->b1 = INT_MAX;
		dst->b2 = 1;
	} else {
		if (src < 0) {
			dst->sign = SIGN_NEGATIVE;
			src *= -1;
		}
		dst->b1 = src;
	}
	return CONV_OK;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
	double val = (double)src;
	if (val < 0) {
		dst->sign = SIGN_NEGATIVE;
		val *= -1;
	}
	if (val > S21_DECIMAL_MAX_VALUE) {
		return CONV_ERROR;
	}
	double fractional = val - floor(some_double);
	double bit2 = floor(val / S21_DECIMAL_BASE);
	dst->b3 = (int)floor(bit2 / S21_DECIMAL_BASE);
	
	int targer_precision = 7;
	for (int i = 0; i < targer_precision && val > S21_DECIMAL_MAX_VALUE; i++) {
		;
	}
	return CONV_OK;
}



int s21_from_decimal_to_int(s21_decimal src, int *dst) {return CONV_OK;}
int s21_from_decimal_to_float(s21_decimal src, float *dst) {return CONV_OK;}
