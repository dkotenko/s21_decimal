#include "s21_decimal.h"

s21_decimal s21_new_decimal(uint32_t b1, uint32_t b2, uint32_t b3, uint32_t exponent, uint32_t sign) {
	s21_decimal d = {
		.b1 = b1,
		.b2 = b2,
		.b3 = b3,
		.exponent = exponent,
		.sign = sign 
	};
	return d;
}