/*Problem 275
 * Álvaro García Tenorio*/

#include <iostream>
#include <cstdlib> //for the abs function.
#include <climits> //for INT_MAX
using namespace std;

void solveCase();
bool solve(int & height);

int main() {
	int casesNumber;
	cin >> casesNumber;
	cin.get(); //discarding the '\n' after the number of cases.
	for (int i = 0; i < casesNumber; i++) {
		solveCase();
	}
	return 0;
}

void solveCase() {
	int height;
	bool solution = solve(height);

	//reading the rest of the tree (in case of lazy evaluations)
	char lazy;
	cin.get(lazy);
	if (lazy != '\n') {
		cin.ignore(INT_MAX, '\n');
	}

	if (solution) {
		cout << "SI" << endl;
	} else {
		cout << "NO" << endl;
	}
}

bool solve(int & height) {
	char root;
	cin.get(root);
	if (root == '.') {
		height = 0;
		return true;
	} else {
		int leftHeight, rightHeight;
		bool balanced = solve(leftHeight) && solve(rightHeight);
		balanced &= abs(leftHeight - rightHeight) <= 1;
		height = max(leftHeight, rightHeight) + 1;
		return balanced;
	}
}
