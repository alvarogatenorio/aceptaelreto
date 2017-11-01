/*Problem 100
 * Álvaro García Tenorio*/

#include <iostream>
#include <cmath>
using namespace std;

const int DIGITS = 4;
const int EMPTY = -1;
const int REPDIGIT = 8;
const int KAPREKAR = 6174;

void solveCase();
void solve(int number, int & iterations);
void insert(int descomposition[], int digit, int occupied);

int main() {
	int casesNumber;
	cin >> casesNumber;
	for (int i = 0; i < casesNumber; i++) {
		solveCase();
	}
	return 0;
}

void solveCase() {
	int number, iterations = 0;
	cin >> number;
	solve(number, iterations);
	cout << iterations << endl;
}

void solve(int number, int & iterations) {
	if (number != KAPREKAR) {
		int descomposition[DIGITS];
		int digit = number % 10, counter = 0;
		for (int i = 0; i < DIGITS && counter < DIGITS; i++) {
			if (counter != EMPTY && digit == number % 10) {
				counter++;
			} else {
				counter = EMPTY;
			}
			digit = number % 10;
			insert(descomposition, number % 10, i);
			number = number / 10;
		}
		if (counter != DIGITS) {
			int increasing = 0, decreasing = 0;
			for (int i = 0; i < DIGITS; i++) {
				increasing += descomposition[i] * pow(10, i);
				decreasing += descomposition[i] * pow(10, DIGITS - 1 - i);
			}
			iterations++;
			solve(decreasing - increasing, iterations);
		} else {
			iterations = REPDIGIT;
		}
	}
}

void insert(int descomposition[], int digit, int occupied) {
	int i;
	for (i = 0; i < occupied; i++) {
		if (descomposition[i] <= digit) {
			for (int j = occupied; j > i; j--) {
				descomposition[j] = descomposition[j - 1];
			}
			descomposition[i] = digit;
			break;
		}
	}
	if (i == occupied) {
		descomposition[occupied] = digit;
	}
}
