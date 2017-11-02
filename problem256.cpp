/*Problem 256
 * Álvaro García Tenorio*/

#include <iostream>
#include <cmath>

using namespace std;

bool solveCase();
unsigned long long int solve(unsigned long long int & a,
		unsigned long long int & b, unsigned long long int & c, bool & error);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	unsigned long long int a, b, c;
	bool error;
	cin >> a >> b >> c;
	if (!cin) {
		return false;
	}
	a = solve(a, b, c, error);
	if (error) {
		cout << "RUIDO COSMICO" << endl;
	} else {
		cout << a << endl;
	}
	return true;
}

unsigned long long int solve(unsigned long long int & a,
		unsigned long long int & b, unsigned long long int & c, bool & error) {
	error = false;
	unsigned long long int original = 0;
	int powerCounter = 0;
	while (a != 0 || b != 0 || c != 0) {
		if (a % 10 == b % 10 || a % 10 == c % 10) {
			original += (a % 10) * pow(10, powerCounter);
			powerCounter++;
		} else if (b % 10 == c % 10) {
			original += (b % 10) * pow(10, powerCounter);
			powerCounter++;
		} else {
			error = true;
			break;
		}
		a = a / 10;
		b = b / 10;
		c = c / 10;
	}
	return original;
}
