#include "s21_decimal.h"

int main() {
	// s21_decimal d1 = s21_new_decimal(
	// 	3, 10, 1, 2, 1
	// );

	// s21_decimal d2 = s21_new_decimal(
	// 2, 6, 6, 2, 1
	// );
		s21_decimal d1 = s21_new_decimal(
	2147483647, 0, 0, 2, 1
	);

	s21_decimal d2 = s21_new_decimal(
	1, 0, 0, 2, 1
	);
		s21_decimal result = s21_new_decimal(
		0, 0, 0, 0, 0
	);
	printf("%d\n",s21_sub(d1, d2, &result));
	s21_print_decimal_bits(result);
	return 0;
}
