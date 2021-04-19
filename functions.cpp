#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "functions.h"

using namespace std;

const char ALPHABET[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
						  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };


float* read_frequency() {
	float* frequency_arr = new float[52];
	ifstream dist_file;
	dist_file.open("distribution.txt");
	string line;
	int i = 0;
	float a;
	while (dist_file >> a) {
		frequency_arr[i] = a;
		i++;
	}
	dist_file.close();
	return frequency_arr;
}

int number_of_char(char a, char* str) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == a) {
			count++;
		}
	}
	return count;
}

float expected_num_of_char(char a, float* freq_arr, char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (ALPHABET[i] == a) {
			return (freq_arr[i] * strlen(str)) / 100;
		}
	}
	return -1;
}

float chi_squared(float* freq_arr, char* str) {
	float sum = 0;
	for (int i = 0; i < 52; i++) {
		float C = number_of_char(ALPHABET[i], str);
		float E = expected_num_of_char(ALPHABET[i], freq_arr, str);
		sum += pow((C - E), 2) / E;
	}
	return sum;
}

void shift_letters(char* str, int n)
{
	for (unsigned int i = 0; i < strlen(str); i++)
	{

		if (str[i] >= 65 && str[i] <= 90)
		{
			char res = str[i] - n;
			while (res < 65)
			{
				res = 90 - (65 - res - 1);
			}
			while (res > 90)
			{
				res = 65 + (90 - res - 1);
			}
			str[i] = res;
		}

		if (str[i] >= 97 && str[i] <= 122)
		{
			char res = str[i] - n;
			while (res < 97)
			{
				res = 122 - (97 - res - 1);
			}
			while (res > 122)
			{
				res = 97 + (122 - res - 1);
			}
			str[i] = res;
		}
	}
}

char* deciphered(float* freq_arr, char* str) {
	float min_chi_sq = chi_squared(freq_arr, str);
	char* deciphered = new char[strlen(str)];
	strcpy(deciphered, str);
	for (int j = 1; j <= 25; j++) {
		shift_letters(str, 1);
		if (chi_squared(freq_arr, str) < min_chi_sq) {
			min_chi_sq = chi_squared(freq_arr, str);
			strcpy(deciphered, str);
		}
	}
	return deciphered;
}

