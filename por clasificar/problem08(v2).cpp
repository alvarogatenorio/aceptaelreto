/*Problem 08
 * Álvaro García Tenorio
 * Doble grado de ingeniería informática y matemáticas*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool solveCase();
int solve(int begining, int ending, int n, const vector<int> & list);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int sheets, instruments;
	cin >> sheets >> instruments;
	if (!cin) {
		return false;
	} else {
		vector<int> list;
		int maximum = 0;
		for (int i = 0; i < instruments; i++) {
			int musicians;
			cin >> musicians;
			maximum = max(musicians, maximum);
			list.push_back(musicians);
		}
		cout << solve(1, maximum, sheets - instruments, list) << endl;
		return true;
	}
}

int nop(int m, const vector<int> & list, int n) {
	int sum = 0;
	for (int i = 0; i < (int) (list.size()); i++) {
		if (list.at(i) % m == 0) {
			sum += ((list.at(i) / m) - 1);
		} else {
			sum += (list.at(i) / m);
		}
	}
	return sum;
}

int solve(int begining, int ending, int n, const vector<int> & list) {
	int m = (begining + ending) / 2;
	int nopm = nop(m, list, n);
	if (nopm > n) {
		if (m + 1 == ending) {
			return ending;
		} else {
			return solve(m + 1, ending, n, list);
		}
	} else {
		if (begining == m) {
			return m;
		} else {
			return solve(begining, m, n, list);
		}
	}
}
