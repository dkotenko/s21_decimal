#include "s21_decimal.h"

int getBit(s21_decimal src, int number) {
  return (src.bits[number / 32] >> (number % 32)) & 1;
}

void s21_div_temp(int64_t *d, int n) {
	double prev = 0;
	for (int i = 3; i > -1; i--) {
		double temp = ((double)d[i] + prev) / n;
		d[i] = (int)temp;
		prev = (temp - d[i]) * ((int64_t)INT_MAX + 1);
	}
}