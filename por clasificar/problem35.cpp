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
	int F, C;
	if (scanf("%d", &F) == EOF) {
		return false;
	}
	scanf("%d\n", &C);
	vector<vector<char>> bar(F, vector<char>(C));
	char trash;
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &bar[i][j]);
		}
		scanf("%c", &trash);
	}
	/*Filling table*/
	vector<vector<vector<vector<int>>>> table(F + 1,
			vector<vector<vector<int>>>(F + 1,
					vector<vector<int>>(C + 1, vector<int>(C + 1))));
	int i1, i2, j1, j2;
	for (int di = 1; di < F + 1; di++) {
		for (int ci = di; ci < F + 1; ci++) {
			for (int dj = 1; dj < C + 1; dj++) {
				for (int cj = dj; cj < C + 1; cj++) {
					i1 = ci - di;
					i2 = ci;
					j1 = cj - dj;
					j2 = cj;
					/*Just a square*/
					if (i1 + 1 == i2 && j1 + 1 == j2) {
						table[i1][i2][j1][j2] = 0;
						continue;
					}
					/*Not just a square*/
					int horizontally = 20 * 20 * 4;
					int H;
					int vertically = 20 * 20 * 4;
					int V;
					/*Try to cut horizontally*/
					if (i1 + 1 < i2) {
						for (int ki = i1 + 1; ki < i2; ki++) {
							int aux = table[i1][ki][j1][j2]
									+ table[ki][i2][j1][j2];
							if (aux < horizontally) {
								horizontally = aux;
								H = ki;
							}
						}
						horizontally++;
						if (horizontally - 1 == 0
								&& bar[H][j1] == bar[H - 1][j1]) {
							horizontally--;
						}
					}
					/*Try to cut vertically*/
					if (j1 + 1 < j2) {
						for (int kj = j1 + 1; kj < j2; kj++) {
							int aux = table[i1][i2][j1][kj]
									+ table[i1][i2][kj][j2];
							if (aux < vertically) {
								vertically = aux;
								V = kj;
							}
						}
						vertically++;
						if (vertically - 1 == 0
								&& bar[i1][V] == bar[i1][V - 1]) {
							vertically--;
						}
					}
					table[i1][i2][j1][j2] = min(horizontally, vertically);
				}
			}
		}
	}
	printf("%d\n", table[0][F][0][C]);
	return true;
}
