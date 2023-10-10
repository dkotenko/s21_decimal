#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <math.h>

/*
** [.....96..mantissa...]
** [.....0-15....unused..]
** [.....16-23...exponent in range 0-28]
** [.....24-30....unused...]
** [.....31.-.sign.....]
*/

#define S21_DECIMAL_BASE ((int64_t)INT_MAX + 1)
#define S21_DECIMAL_MANTISSA_SIZE 3
#define S21_DECIMAL_MIN_EXPONENT 0
#define S21_DECIMAL_MAX_EXPONENT 28
#define S21_DECIMAL_MAX_VALUE 79228162514264337593543950335.
#define S21_DECIMAL_MIN_VALUE -79228162514264337593543950335.
#define S21_DECIMAL_EPSILON 1e-7

typedef union 
{
    uint32_t bits[4];
	struct {
		uint32_t		b1 : 32;
		uint32_t		b2 : 32;
		uint32_t		b3 : 32;
		short	unused1 : 16;
		char	exponent : 8;
		char	unused2 : 7;
		uint32_t		sign	: 1;
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

typedef enum {
	NO_ERR = 0,
	ERR_TOO_LAGRE,
	ERR_TOO_SMALL,
	ERR_ZERO_DIV
} e_calc_err;

typedef enum {
	CONV_OK = 0,
	CONV_ERROR
} e_conv_err;


int s21_add(s21_decimal v1, s21_decimal v2, s21_decimal *result);
int s21_sub(s21_decimal v1, s21_decimal v2, s21_decimal *result);
int s21_mul(s21_decimal v1, s21_decimal v2, s21_decimal *result);
int s21_div(s21_decimal v1, s21_decimal v2, s21_decimal *result);

int s21_is_less(s21_decimal v1, s21_decimal v2);
int s21_is_less_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_greater(s21_decimal v1, s21_decimal v2);
int s21_is_greater_or_equal(s21_decimal v1, s21_decimal v2);
int s21_is_equal(s21_decimal v1, s21_decimal v2);
int s21_is_not_equal(s21_decimal v1, s21_decimal v2);

int s21_compare(s21_decimal v1, s21_decimal v2);
void align_exponent(s21_decimal *v1, s21_decimal *v2);

/*
** convertation.c
*/
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
s21_decimal s21_new_decimal(int b1, int b2, int b3, int exponent, unsigned int sign);
/*
** mantissa.c
*/
void s21_multiply_mantissa(s21_decimal *d, int n);
void s21_divide_mantissa(s21_decimal *d, int n);
int s21_compare_mantissa(s21_decimal v1, s21_decimal v2);
void s21_divide_array(uint32_t *arr, int arr_size, int n);
void s21_multiply_array(uint32_t *arr, int arr_size, int n);

/*
** exponent.c
*/
void s21_increase_exponent(s21_decimal *d);
void s21_decrease_exponent(s21_decimal *d);
int exp_incr_fits_int(s21_decimal *d);

/*
** support
*/
int getBit(s21_decimal src, int number);
void s21_div_temp(int64_t *d, int n);
void decimal_copy(s21_decimal *value_1, s21_decimal value_2);
