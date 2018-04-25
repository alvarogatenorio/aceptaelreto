/*Problem 02
 * Álvaro García Tenorio
 * Doble grado de ingeniería informática y matemáticas*/

#include <iostream>
#include <cstdlib> //for the abs function.
#include <climits> //for INT_MAX
using namespace std;

const bool LEFT = false;
const bool RIGHT = true;

void solveCase();
bool solve(int & height, int & extreme, bool wing = LEFT);

int main() {
	int casesNumber;
	cin >> casesNumber;
	for (int i = 0; i < casesNumber; i++) {
		solveCase();
	}
	return 0;
}

void solveCase() {
	int height, extreme;
	bool solution = solve(height, extreme);

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

bool solve(int & height, int & extreme, bool wing) {
	cin >> extreme; //here extreme means root
	if (extreme == -1) {
		height = 0;
		return true;
	} else {
		int leftHeight, rightHeight, leftExtreme, rightExtreme;
		bool avl = solve(leftHeight, leftExtreme, LEFT)
				&& solve(rightHeight, rightExtreme, RIGHT);
		avl &= abs(leftHeight - rightHeight) <= 1;
		avl &= extreme > leftExtreme
				&& (extreme < rightExtreme || rightExtreme == -1);
		height = max(leftHeight, rightHeight) + 1;
		//updating extremes carefully
		if (wing && leftExtreme != -1) {
			extreme = min(leftExtreme, extreme);
		} else if (!wing) {
			extreme = max(rightExtreme, extreme);
		}
		return avl;
	}
}
