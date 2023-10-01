#include "s21_decimal.h"


int s21_add(s21_decimal v1, s21_decimal v2, s21_decimal *result) {
	if (v1.sign > 0 && v2.sign < 0) {
		return s21_sub(v1, v2, result);
	} else if (v1.sign < 0 && v2.sign > 0) {
		return s21_sub(v2, v1, result);
	}
	
	if (v1.exponent != v2.exponent) {
		align_exponent(&v1, &v2);
	}

	int64_t temp[4];

	for (int i = 0; i < 3; i++) {
		temp[i] = (int64_t)v1.bits[i] + (int64_t)v2.bits[i];
		if (temp[i] > INT_MAX) {
			
			int64_t prev = temp[i] / INT_MAX;
			temp[i+1] += prev;
			temp[i] %= INT_MAX;
		} 

		//result->bits[i] = (int)temp[i];
	}
	int exp_minus = 0;
	
	if (temp[3] > 0) {
		
		while (temp[3] > 0) {
			s21_div_temp(temp, 10);//функция находится в support_func
			exp_minus++;
		}
	}
    
	for (int i = 0; i < 3; i++) {
		result->bits[i] = (int)temp[i];
		result->exponent-=exp_minus;
	}

	return NO_ERR;
} 