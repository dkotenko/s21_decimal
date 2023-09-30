#include "s21_decimal.h"

static inline int exp_incr_fits_int(s21_decimal *d) {
	int64_t prev = 0;
	int64_t temp[4] = {0};
	for (int i = 0; i < 3; i++) {
		temp[i] = (int64_t)d->bits[i] * 10 + prev;
		if (temp[i] > INT_MAX) {
			prev = temp[i] / INT_MAX;
			temp[i] %= INT_MAX;
		} else {
			prev = 0;
		}
	}
	return prev == 0;
}

void align_exponent(s21_decimal *v1, s21_decimal *v2) {
	s21_decimal *greater;
	s21_decimal *lesser;

	greater = v1->exponent > v2->exponent ? v1 : v2;
	lesser = v1->exponent < v2->exponent ? v1 : v2;
	while (lesser->exponent < greater->exponent && exp_incr_fits_int(lesser)) {
		s21_increase_exponent(lesser);
	}
	while (lesser->exponent < greater->exponent) {
		s21_decrease_exponent(lesser);
	}
}

void s21_increase_exponent(s21_decimal *d) {
	s21_multiply_mantissa(d, 10);
	d->exponent++;
}

void s21_decrease_exponent(s21_decimal *d) {
	s21_divide_mantissa(d, 10);
	d->exponent--;
}