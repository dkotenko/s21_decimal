#include "s21_decimal.h"


/**
 * s21_multiply_mantissa Doesn't handle overflow
 */
void s21_multiply_mantissa(int *mantissa, int n) {
	s21_multiply_array(mantissa, S21_DECIMAL_MANTISSA_SIZE, n);
}

void s21_multiply_array(int *arr, int arr_size, int n) {
	int64_t prev = 0;
	for (int i = 0; i < arr_size; i++) {
		int64_t temp = (int64_t)arr[i] * n + prev;
		if (temp > INT_MAX) {
			prev = temp / INT_MAX;
			temp %= INT_MAX;
		} else {
			prev = 0;
		}
		arr[i] = (int)temp;
	}
}

void s21_divide_array(int *arr, int arr_size, int n) {
	double prev = 0;
	for (int i = arr_size - 1; i > -1; i--) {
		double temp = ((double)arr[i] + prev) / n;
		arr[i] = (int)temp;
		prev = (temp - arr) * S21_DECIMAL_BASE;
	}
}

void s21_divide_mantissa(int *mantissa, int n) {
	s21_divide_array(mantissa, S21_DECIMAL_MANTISSA_SIZE, n);
}