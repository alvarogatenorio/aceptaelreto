#include <iostream>
#include <vector>
#include <algorithm>
#include "ConjuntosDisjuntos.h"

using namespace std;

bool solveCase();
void solve(vector<vector<char>> & sea, int rows, int columns);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int rows, columns;
	if (scanf("%d %d", &rows, &columns) == EOF) {
		return false;
	}
	vector<vector<char>> sea(rows, vector<char>(columns));
	char trash;
	scanf("%c", &trash);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			scanf("%c", &sea[i][j]);
		}
		scanf("%c", &trash);
	}
	solve(sea, rows, columns);
	return true;
}

void solve(vector<vector<char>> & sea, int rows, int columns) {
	ConjuntosDisjuntos g(rows * columns);
	int m = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (sea[i][j] == '#') {
				m = max(m, (int) (g.size(i * columns + j)));
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						if ((k != 0 || l != 0) && (i + k >= 0 && i + k < rows)
								&& (j + l >= 0 && j + l < columns)) {
							if (sea[i + k][j + l] == '#') {
								g.unir(i * columns + j,
										(i + k) * columns + j + l);
								m = max(m, (int) (g.size(i * columns + j)));
							}
						}
					}
				}
			}
		}
	}
	printf("%d", m);
	int images;
	scanf("%d", &images);
	if (images > 0) {
		printf(" ");
	} else {
		printf("\n");
	}
	for (int i = 0; i < images; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		r--;
		c--;
		sea[r][c] = '#';
		m = max(m, (int) (g.size(r * columns + c)));
		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if ((k != 0 || l != 0) && (r + k >= 0 && r + k < rows)
						&& (c + l >= 0 && c + l < columns)) {
					if (sea[r + k][c + l] == '#') {
						g.unir(r * columns + c, (r + k) * columns + c + l);
						m = max(m, (int) (g.size(r * columns + c)));
					}
				}
			}
		}
		if (i != images - 1) {
			printf("%d ", m);
		} else {
			printf("%d\n", m);
		}
	}
}
