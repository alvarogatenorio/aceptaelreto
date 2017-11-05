/*Problem 303
 * Álvaro García Tenorio*/

#include <iostream>
#include <cstdlib> //for the abs function.
using namespace std;

const bool LEFT = false;
const bool RIGHT = true;

void solveCase();
bool solve(int & height, int & extreme, bool wing = LEFT);

int main() {
	int casesNumber;
	scanf("%d", &casesNumber);
	for (int i = 0; i < casesNumber; i++) {
		solveCase();
	}
	return 0;
}

void solveCase() {
	int height, extreme;
	bool solution = solve(height, extreme);

	//reading the rest of the tree (in case of lazy evaluations)
	while (getchar() != '\n')
		;

	if (solution) {
		printf("SI\n");
	} else {
		printf("NO\n");
	}
}

bool solve(int & height, int & extreme, bool wing) {
	scanf("%d", &extreme);
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
