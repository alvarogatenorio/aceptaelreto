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
	int N;
	if (scanf("%d", &N) == EOF) {
		return false;
	}
	vector<int> values(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &values[i]);
	}
	vector<int> availables(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &availables[i]);
	}
	int price;
	scanf("%d", &price);
	/*Filling table*/
	vector<int> table(price + 1, 2*N * 1000);
	table[0] = 0;
	for (int i = 1; (i < price + 1) && ((i / values[0]) <= availables[0]);
			i++) {
		if (i % values[0] == 0) {
			table[i] = i / values[0];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = price; j >= 0; j--) {
			/*Considering the current coin*/
			int currentCoin = 2*N * 1000;
			int aux = j - values[i];
			for (int k = 1; k <= availables[i] && aux >= 0; k++) {
				currentCoin = min(currentCoin, table[aux] + k);
				aux = j - (k + 1) * values[i];
			}
			/*Taking the minimum*/
			table[j] = min(table[j], currentCoin);
		}
	}
	if (table[price] == 2 * N * 1000) {
		printf("NO\n");
	} else {
		printf("SI %d\n", table[price]);
	}
	return true;
}
