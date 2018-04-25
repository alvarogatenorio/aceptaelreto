#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Reading stuff*/
	int buckets;
	scanf("%d", &buckets);
	if (buckets == 0) {
		return false;
	}
	vector<int> quantity(buckets);
	for (int i = 0; i < buckets; i++) {
		scanf("%d", &quantity[i]);
	}
	/*Filling table*/
	vector<vector<int>> table(2, vector<int>(quantity.size() + 1, 0));
	for (int i = 1; i < (int) quantity.size() + 1; i++) {
		table[1][i] = quantity[i - 1];
	}
	int old = 0;
	for (int k = 1; k < (int) quantity.size(); k++) {
		for (int c = quantity.size(); c > k; c--) {
			table[old][c] = max(
					quantity[c - 1 - k]
							+ table[old][
									quantity[c - k] > quantity[c - 1] ?
											c : c - 1],
					quantity[c - 1]
							+ table[old][
									quantity[c - 2] > quantity[c - 1 - k] ?
											c - 2 : c - 1]);
		}
		old = (old + 1) % 2;
	}
	printf("%d\n", table[(old + 1) % 2][quantity.size()]);
	return true;
}
