#include "s21_decimal.h"

int main() {
	s21_decimal a = s21_new_decimal(
		1, 1, 1, 2, 10
	);
	s21_print_decimal_bits(a);
	return 0;
}