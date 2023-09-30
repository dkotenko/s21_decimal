#include "s21_decimal.h"

int main() {
	s21_decimal d1 = s21_new_decimal(
		1, 1, 1, 15, 10
	);

	s21_decimal d2 = s21_new_decimal(
		1, 1, 1, 2, 10
	);
	printf("%d\n",s21_is_less_or_equal(d1, d2));
	return 0;
}