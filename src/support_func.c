#include "../s21_decimal.h"

int getBit(s21_decimal src, int number) {
  return (src.bits[number / 32] >> (number % 32)) & 1;
}