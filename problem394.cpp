/*Problem 394*/

#include <iostream>
#include <algorithm>

using namespace std;

void solveCase();
int solve(int & uppermost);

int main() {
	int casesNumber;
	scanf("%d", &casesNumber);
	for (int i = 0; i < casesNumber; i++) {
		solveCase();
	}
	return 0;
}

void solveCase() {
	/*Represents the generations number of the complete family whose father
	 * is the root of the tree*/
	int uppermost;
	printf("%d\n", solve(uppermost));
}

int solve(int & uppermost) {
	int numSons;
	scanf("%d", &numSons);
	if (numSons == 0) {
		uppermost = 0;
		return 0;
	} else if (numSons == 1) {
		uppermost = 0;
		int up;
		return solve(up);
	} else {
		int upLeft, left = solve(upLeft);
		int upRight, right = solve(upRight);
		uppermost = min(upLeft, upRight) + 1;
		return max(uppermost, max(left, right));
	}
}
