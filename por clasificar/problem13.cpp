#include <iostream>
#include <vector>
#include "ConjuntosDisjuntos.h"

using namespace std;

bool solveCase();
void solve(vector<vector<char>> & image, int rows, int columns, int blacks);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int rows, columns;
	if (scanf("%d %d\n", &columns, &rows) == EOF) {
		return false;
	}
	vector<vector<char>> image(rows, vector<char>(columns));
	char trash;
	int blacks = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			scanf("%c", &image[i][j]);
			if (image[i][j] == 'X') {
				blacks++;
			}
		}
		scanf("%c", &trash);
	}
	solve(image, rows, columns, blacks);
	return true;
}

void solve(vector<vector<char>> & image, int rows, int columns, int blacks) {
	ConjuntosDisjuntos components(rows * columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (image[i][j] == '.') {
				if (i - 1 >= 0 && image[i - 1][j] == '.') {
					components.unir(columns * (i - 1) + j, columns * i + j);
				}
				if (i + 1 < rows && image[i + 1][j] == '.') {
					components.unir(columns * (i + 1) + j, columns * i + j);
				}
				if (j - 1 >= 0 && image[i][j - 1] == '.') {
					components.unir(columns * i + j - 1, columns * i + j);
				}
				if (j + 1 < columns && image[i][j + 1] == '.') {
					components.unir(columns * i + j + 1, columns * i + j);
				}
			}
		}
	}
	printf("%d\n", (unsigned int) (components.count() - blacks - 1));
}
