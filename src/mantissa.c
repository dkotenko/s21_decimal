#include "s21_decimal.h"


/**
 * s21_multiply_mantissa Doesn't handle overflow
 */
void s21_multiply_mantissa(s21_decimal *d, int n) {
	s21_multiply_array(d->bits, S21_DECIMAL_MANTISSA_SIZE, n);
}

void s21_multiply_array(uint32_t *arr, int arr_size, int n) {
	uint64_t prev = 0;
	for (int i = 0; i < arr_size; i++) {
		uint64_t temp = (uint64_t)arr[i] * n + prev;
		if (temp > UINT_MAX) {
			prev = temp / S21_DECIMAL_BASE;
			temp %= S21_DECIMAL_BASE;
		} else {
			prev = 0;
		}
		arr[i] = (int)temp;
	}
}

void s21_divide_array(uint32_t *arr, int arr_size, int n) {
	double prev = 0;
	for (int i = arr_size - 1; i > -1; i--) {
		double temp = ((double)arr[i] + prev) / n;
		arr[i] = (uint32_t)temp;
		prev = (temp - arr[i]) * S21_DECIMAL_BASE;
	}
}

void s21_divide_mantissa(s21_decimal *d, int n) {
	s21_divide_array(d->bits, S21_DECIMAL_MANTISSA_SIZE, n);
}