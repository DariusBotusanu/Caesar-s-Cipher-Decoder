#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "functions.h"
#include "user_interface.h"
#include <string>

using namespace std;

char* read_string() {
    char* str_array = new char[1000];
    cin.get(str_array, 1000);
	return str_array;
}

void print_menu() {
	cout << "What would you like to do?" << endl;
	cout << " c - compute its chi^2 value" << endl;
	cout << " d- decipher the sting" << endl;
    cout << " e - exit the program" << endl;
}

void run_program() 
{
    float * freq_arr = read_frequency();
    cout << "Please enter a string!" << endl;;
    char* str = read_string();
    float  chi_sq = chi_squared(freq_arr, str);
    char* dec = deciphered(freq_arr, str);
    char op;
    while (true)
    {
        print_menu();
        cin >> op;
        switch (op)
        {
        case 'c':
            cout << "Chi squared is: " << chi_sq << endl;
            break;
        case 'd':
            cout << dec << endl;
            break;
        case 'e':
            cout << "So long!" << endl;
            exit(0);
            break;
        default:
            cout << "Please enter a valid operation!";
        }
    }
}
/*
Write a function that computes the normalized frequency of each character (a histogram) in a text.
● Write a function that computes the Chi squared distance between two histograms.
● Write a function that breaks the Caesar’s cipher using frequency analysis: iteratively shifts the encrypted code through all the possible permutations, computes the Chi squared distance between each permutation and the approximate distribution of letters in English, and returns the permutation with the least Chi squared distance as the solution.
● Finally, create a user-friendly menu based application for Caesar's cipher related tasks.
*/