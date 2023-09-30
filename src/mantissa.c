#include "s21_decimal.h"


/**
 * s21_multiply_mantissa Doesn't handle overflow
 */
void s21_multiply_mantissa(s21_decimal *d, int n) {
	int64_t prev = 0;
	for (int i = 0; i < 3; i++) {
		int64_t temp = (int64_t)d->bits[i] * n + prev;
		if (temp > INT_MAX) {
			prev = temp / INT_MAX;
			temp %= INT_MAX;
		} else {
			prev = 0;
		}
		d->bits[i] = (int)temp;
	}
}

void s21_divide_mantissa(s21_decimal *d, int n) {
	double prev = 0;
	for (int i = 2; i > -1; i--) {
		double temp = ((double)d->bits[i] + prev) / n;
		d->bits[i] = (int)temp;
		prev = (temp - d->bits[i]) * ((int64_t)INT_MAX + 1);
	}
}