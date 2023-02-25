#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>


int gcd(int, int);
int mirror_number(int);
int r_mirror_number(int);
int pow(int, int);
int count_dig(int);
void fill_arr(int* arr, const int size, int low, int hi);
void print_arr(int* arr, const int size);
int find_and_sort(int* arr, const int length, int value);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	srand(time(NULL));

	// Exercise 1.
	/*
		Create a function that takes two numbers and
	returns their greatest common divisor.
	*/
	/*std::cout << "Exercise 1.\nEnter two integer numbers -> ";
	int a, b;
	std::cin >> a >> b;
	std::cout << "The greatest common divisor of numbers " << a << " and " << b << " is equal " << gcd(a, b) << ".\n";*/

	// Exercise 2.
	/*
		Write a mirror_number function that
	takes a number and returns it in a reflected form.
	*/
	/*int num;
	std::cout << "Exercise 2.\nProgram for return number in a reflected form.\n";
	std::cin >> num;
	std::cout << mirror_number(num);*/

	// Exercise 3.
	/*
		Создайте функцию, которая принимает массив, его
	длину и число N. Функция возвращает первую позицию
	числа N в массиве, а также сортирует все элементы,
	которые находятся справа от N.
	*/
	const int length = 10;
	int arr[length];
	fill_arr(arr, length, 0, 10);
	std::cout << "Array:\n";
	print_arr(arr, length);
	int val;
	std::cin >> val;
	find_and_sort(arr, length, val);
	print_arr(arr, length);
	return 0;
}

int find_and_sort(int* arr, const int length, int value) {
	int position = -1;
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == value) {
			position = i;
			break;
		}
	}
	if (position != -1) {
		for (size_t i = position+1; i < length; i++) {
			for (size_t j = i; j > position; j--)
			{
				if (arr[j - 1] > arr[j]) {
					int tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
		}
	}
	return position;
}

void print_arr(int* arr, const int size) {
	std::cout << "[ ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b ]\n";
}

void fill_arr(int* arr, const int size, int low, int hi) {
	for (int i = 0; i < size; ++i) {

		arr[i] = rand() % (hi + 1 - low) + low;

	}
}


int r_mirror_number(int n) {
	int digit_counter = count_dig(n);
	digit_counter--;
	int p = pow(10, digit_counter);
	if (n <= 10)
		return n;
	return r_mirror_number(n / 10) * p + r_mirror_number(n / 10) * p;
}


// function for counting the number of digits of a number
int count_dig(int n) {
	int count_dig = 0;
	while (n) {
		n /= 10;
		count_dig++;
	}
	return count_dig;
}

// function for exponentiating a number
int pow(int n, int p) {
	int num = n;
	for (int i = 1; i < p; ++i) {
		n *= num;
	}
	return n;
}

// function for the mirror reversal of a number
int mirror_number(int n) {
	int number = 0;
	int num;
	int digit_counter = count_dig(n); // counting the number of digits
	digit_counter--;
	while (n >= 10) {
		num = (n % 10) * pow(10, digit_counter);
		number += num;
		n /= 10;
		digit_counter--;
	}
	number += n;
	return number;
}

// function for calculating the greatest common divisor
int gcd(int a=0, int b=0) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0)
		return a;
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a - b);
}