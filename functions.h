#define _CRT_SECURE_NO_WARNINGS


float* read_frequency();
int number_of_char(char a, char* str);
float expected_num_of_char(char a, float* freq_arr, char* str);
float chi_squared(float* freq_arr, char* str);
void test_read_frequency();
void shift_letters(char* str, int n);
char* deciphered(float* freq_arr, char* str);