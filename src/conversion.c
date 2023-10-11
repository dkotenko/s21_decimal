#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
	memset(dst, 0, sizeof(s21_decimal));
	int64_t temp = (int64_t)src;
	if (temp < 0) {
		dst->sign = SIGN_NEGATIVE;
		temp *= -1;
	}
	dst->b1 = (uint32_t)temp;
	return CONV_OK;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
	memset(dst, 0, sizeof(s21_decimal));
	double val = (double)src;
	if (val < 0) {
		dst->sign = SIGN_NEGATIVE;
		val *= -1;
	}
	if (val > S21_DECIMAL_MAX_VALUE) {
		return CONV_ERROR;
	}
	double t = (double)S21_DECIMAL_BASE * (double)S21_DECIMAL_BASE;
	double dividers[3] = {1., S21_DECIMAL_BASE, t};
	double bits[3] = {0};
	double temp_val = val;
	for (int i = 2; i > -1; i--) {
		bits[i] = temp_val / dividers[i];
		double whole = floor(bits[i]);
		temp_val = (bits[i] - whole) * dividers[i];
		//printf("whole bit %d: %lf\n", i, whole);
		dst->bits[i] = (uint32_t)whole;
	}
	
	uint32_t fractional = temp_val * 1e6;
	//printf("%u\n", fractional);
	int digits_num = 6;
	while (!(fractional % 10) && digits_num) {
		fractional /= 10;
		digits_num--;
	}
	//printf("%u\n", digits_num);
	while (exp_incr_fits_int(dst) && digits_num--) {
		s21_increase_exponent(dst);
	}
	dst->b1 += fractional; //TODO handle int overflow - add_mantissa
	//printf("%u\n", dst->b1);
	return CONV_OK;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
	(void)src;
	(void)dst;
	return CONV_OK;
}
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
	(void)src;
	(void)dst;
	return CONV_OK;
}
