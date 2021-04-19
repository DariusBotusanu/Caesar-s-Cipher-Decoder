#include <assert.h>
#include <string>
#include "test_functions.h"
#include "functions.h"

using namespace std;

void test_read_frequency() {
	float* arr = read_frequency();
	float freq_arr[] = { 8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0, 2.4, 6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1,
						 8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0, 2.4, 6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1 };
	for (int i = 0; i < 52; i++) {
		assert(arr[i] == freq_arr[i]);
	}
}

void test_deciphered() {
	float* freq_arr = read_frequency();
	string str = "Uf ime ftq nqef ar fuyqe, uf ime ftq iadef ar fuyqe, uf ime ftq msq ar iuepay, uf ime ftq msq ar raaxuetzqee, uf ime ftq qbaot ar nqxuqr, uf ime ftq qbaot ar uzodqpgxufk, uf ime ftq eqmeaz ar xustf, uf ime ftq eqmeaz ar pmdwzqee, uf ime ftq ebduzs ar tabq, uf ime ftq iuzfqd ar pqebmud.";
	char* str_arr = &str[0];
	char* dec = deciphered(freq_arr, str_arr);
	string str_dec = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of light, it was the season of darkness, it was the spring of hope, it was the winter of despair.";
	char* str_array_dec = &str_dec[0];
	assert(!(strcmp(dec, str_array_dec)));

	string motto = "Mjatnwnm bruqxdnccnb rw cqn larvbxw bth";
	string dec_motto = "Darkened silhouettes in the crimson sky";
	char* motto_arr = &motto[0];
	char* dec_motto_arr = &dec_motto[0];
	char* dec2 = deciphered(freq_arr, motto_arr);
	assert(!(strcmp(dec2, dec_motto_arr)));
}