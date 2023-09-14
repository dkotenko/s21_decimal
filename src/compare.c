#include "s21_decimal.h"

static inline void align_exponent(s21_decimal *v1, s21_decimal *v2) {
	(void)v1;
	(void)v2;
	return ;
}

static inline int s21_compare(s21_decimal v1, s21_decimal v2) {
	if (v1.exponent != v2.exponent) {
		align_exponent(&v1, &v2);
	}
	return 0;
}

static inline int s21_compare_mantissa(s21_decimal v1, s21_decimal v2) {
	int cmp = CMP_EQUAL;
	for (int i = 0; i < 3 && cmp == 0; i++) {
		if (v1.bits[i] > v2.bits[i]) {
			cmp = CMP_FIRST;
		} else if (v1.bits[i] < v2.bits[i]) {
			cmp = CMP_SECOND;
		}
	}
	return cmp;
}

int s21_is_less(s21_decimal v1, s21_decimal v2) {
	return s21_compare(v1, v2) == CMP_SECOND;
}

int s21_is_less_or_equal(s21_decimal v1, s21_decimal v2) {
	int cmp = s21_compare(v1, v2);
	return cmp == CMP_SECOND || cmp == CMP_EQUAL;
}

int s21_is_greater(s21_decimal v1, s21_decimal v2) {
	return s21_compare(v1, v2) == CMP_FIRST;
}

int s21_is_greater_or_equal(s21_decimal v1, s21_decimal v2) {
	int cmp = s21_compare(v1, v2);
	return cmp == CMP_FIRST || cmp == CMP_EQUAL;
}

int s21_is_equal(s21_decimal v1, s21_decimal v2) {
	return s21_compare(v1, v2) == CMP_EQUAL;
}

int s21_is_not_equal(s21_decimal v1, s21_decimal v2) {
	return s21_compare(v1, v2) != CMP_EQUAL;
}
