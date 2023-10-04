#include "s21_decimal.h"

s21_decimal s21_new_decimal(int b1, int b2, int b3, int exponent, unsigned int sign) {
	s21_decimal d = {
		.b1 = b1,
		.b2 = b2,
		.b3 = b3,
		.exponent = exponent,
		.sign = sign 
	};
	return d;
}