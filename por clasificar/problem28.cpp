#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct {
	int depth;
	int gold;
} tChest;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Reading stuff*/
	int T, N;
	if (scanf("%d", &T) == EOF) {
		return false;
	}
	scanf("%d", &N);
	vector<tChest> chests;
	for (int i = 0; i < N; i++) {
		tChest chest;
		scanf("%d %d", &chest.depth, &chest.gold);
		chests.push_back(chest);
	}

	/*Filling the table*/
	vector<vector<int>> table(N, vector<int>(T + 1, 0));
	for (int j = T; (j >= 0) && (j >= (3 * chests[0].depth)); j--) {
		table[0][j] = chests[0].gold;
	}
	for (int i = 1; i < N; i++) {
		for (int j = T; j >= 0; j--) {
			if ((j - (3 * chests[i].depth)) >= 0) {
				table[i][j] = max(table[i - 1][j],
						(table[i - 1][j - (3 * chests[i].depth)]
								+ chests[i].gold));
			} else {
				table[i][j] = table[i - 1][j];
			}
		}
	}

	/*Recovering results*/
	stack<tChest> recovered;
	printf("%d\n", table[N - 1][T]);
	int remaining = T;
	for (int i = N - 1; i >= 0; i--) {
		if (i > 0 && table[i][remaining] != table[i - 1][remaining]) {
			remaining = remaining - 3 * chests[i].depth;
			recovered.push(chests[i]);
		} else if (i == 0 && table[i][remaining] != 0) {
			recovered.push(chests[i]);
		}
	}
	int counter = (int) recovered.size();
	printf("%d\n", counter);
	for (int i = 0; i < counter; i++) {
		printf("%d %d\n", recovered.top().depth, recovered.top().gold);
		recovered.pop();
	}
	printf("----\n");
	return true;
}
