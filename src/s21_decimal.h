#pragma once

#include "stdbool.h"
#include "stdio.h"
#include "stdbool.h"

/*
** [.....96..mantissa...]
** [.....0-15....unused..]
** [.....16-23...exponent in range 0-28]
** [.....24-30....unused...]
** [.....31.-.sign.....]
*/

typedef union 
{
    int bits[4];
	struct {
		int		b1 : 32;
		int		b2 : 32;
		int		b3 : 32;
		short	unused1 : 16;
		char	exponent : 8;
		char	unused2 : 7;
		int		sign	: 1;
	};
} s21_decimal;

typedef enum {
	SIGN_POSITIVE = 0,
	SIGN_NEGATIVE,
	SIGN_NUM
} e_signs;

/*
** Which number is greater
*/
typedef enum {
	CMP_FIRST = 1,
	CMP_SECOND = -1,
	CMP_EQUAL = 0
} e_cmp_results;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal v1, s21_decimal v2);
int s21_is_less_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_greater(s21_decimal v1, s21_decimal v2);
int s21_is_greater_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_equal(s21_decimal v1, s21_decimal v2);
int s21_is_not_equal(s21_decimal v1, s21_decimal v2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

/*
** print.c
*/

void s21_print_decimal(s21_decimal d);
void s21_print_decimal_bits(s21_decimal d);
void s21_print_int_bits(int n);

/*
** new.c
*/
s21_decimal s21_new_decimal(int b1, int b2, int b3, int exponent, bool sign);

/*
** sub.c
*/
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
/*
** support
*/
int getBit(s21_decimal src, int number)