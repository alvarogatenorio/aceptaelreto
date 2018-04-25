#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Getting stuff*/
	int value, sectors;
	if (scanf("%d", &value) == EOF) {
		return false;
	}
	scanf("%d", &sectors);
	vector<int> points(sectors);
	for (int i = 0; i < sectors; i++) {
		scanf("%d", &points[i]);
	}

	/*Filling table*/
	vector<int> table(value + 1, 0);
	for (int j = 1; j < value + 1; j++) {
		if (j % points[0] == 0) {
			table[j] = j / points[0];
		}
	}
	for (int i = 1; i < sectors; i++) {
		for (int j = 1; j < value + 1; j++) {
			if (j - points[i] >= 0) {
				if (table[j] != 0
						&& (table[j - points[i]] != 0 || j - points[i] == 0)) {
					table[j] = min(table[j], table[j - points[i]] + 1);
				} else if (table[j] == 0
						&& ((table[j - points[i]] != 0) || (j - points[i] == 0))) {
					table[j] = table[j - points[i]] + 1;
				}
			}
		}
	}

	if (table[value] == 0) {
		printf("Imposible\n");
		return true;
	}

	/*Recovering stuff*/
	int remaining = value;
	int sector = sectors - 1;
	queue<int> stuff;
	while (remaining > 0) {
		if (remaining - points[sector] >= 0
				&& table[remaining] == table[remaining - points[sector]] + 1) {
			stuff.push(points[sector]);
			remaining = remaining - points[sector];
		} else {
			sector--;
		}
	}
	printf("%d: ", table[value]);
	int counter = (int) stuff.size();
	for (int i = 0; i < counter - 1; i++) {
		printf("%d ", stuff.front());
		stuff.pop();
	}
	printf("%d\n", stuff.front());
	return true;
}
