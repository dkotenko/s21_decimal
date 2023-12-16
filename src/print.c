#include "s21_decimal.h"

/*
** { [ 31 : 30 - 24 : 23 - 16 : 15-0 ] [95 - 64] [63 - 32] [31 - 0] }
*/

static void s21_print_byte_bits(int n) {
	int mask = 1 << 7;

	for (int i = 0; i < 8 ; i++) {
		printf("%u", (n & mask) > 0);
		mask = mask >> 1;
	}
}

void s21_print_int_bits(int n) {
	union s21_int {
		int n;
		char bits[4];
	};

	union s21_int intval = {n};
	printf("[ ");
	for (int i = 3; i > -1 ; i--) {
		s21_print_byte_bits(intval.bits[i]);

		printf(" ");
	}
	printf("]");
}


void s21_print_decimal_bits(s21_decimal d) {
	for (int i = 3; i > -1 ; i--) {
		s21_print_int_bits(d.bits[i]);
		printf(" ");
	}
	printf("\n");
}


static inline char* s21_int_bits_to_char(int n) {
	(void)n;
	for (int i = 0; i < 8; i++) {
		;		
	}
	return 0;
}

void s21_print_decimal(s21_decimal d) {
	(void)d;
	
	printf("{[]}");
}




