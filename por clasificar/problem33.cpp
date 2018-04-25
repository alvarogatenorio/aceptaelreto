#include <iostream>
#include <vector>

using namespace std;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int originalLength, cutsNumber;
	scanf("%d %d", &originalLength, &cutsNumber);
	if ((originalLength == 0) && (cutsNumber == 0)) {
		return false;
	}
	vector<int> cuts(cutsNumber + 2);
	cuts[0] = 0;
	for (int i = 1; i <= cutsNumber; i++) {
		scanf("%d", &cuts[i]);
	}
	cuts[cutsNumber + 1] = originalLength;
	vector<vector<int>> table(cutsNumber + 2, vector<int>(cutsNumber + 2, 0));
	for (int d = 2; d < cutsNumber + 2; d++) {
		for (int c = d; c < cutsNumber + 2; c++) {
			int minimum = table[c - d][c - d + 1] + table[c - d + 1][c];
			for (int k = c - d + 2; k < c; k++) {
				minimum = min(minimum, table[c - d][k] + table[k][c]);
			}
			table[c - d][c] = 2 * (cuts[c] - cuts[c - d]) + minimum;
		}
	}
	printf("%d\n", table[0][cutsNumber + 1]);
	return true;
}
