#include "s21_decimal.h"

int s21_compare(s21_decimal v1, s21_decimal v2) {
	int sign = 1;
	if (v1.sign != v2.sign) {
		return v1.sign == SIGN_POSITIVE ? CMP_FIRST : CMP_SECOND;
	} else if (v1.sign == SIGN_NEGATIVE) {
		sign *= -1;
	}
	if (v1.exponent != v2.exponent) {
		align_exponent(&v1, &v2);
	}
	if (v1.exponent != v2.exponent) {
		return v1.exponent > v2.exponent ? CMP_SECOND : CMP_FIRST;
	}
	return s21_compare_mantissa(v1, v2);
}

int s21_compare_mantissa(s21_decimal v1, s21_decimal v2) {
	int cmp = CMP_EQUAL;
	for (int i = 2; i > -1 && cmp == CMP_EQUAL; i--) {
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
