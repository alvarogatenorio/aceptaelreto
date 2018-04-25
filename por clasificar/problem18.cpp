#include <iostream>
#include <vector>
#include <cmath>
#include "ConjuntosDisjuntos.h"

using namespace std;

typedef struct {
	int x;
	int y;
} tTree;

bool solveCase();
void solve(ConjuntosDisjuntos & g, int N, int M, vector<vector<bool>> & iberia,
		int x, int y, int K);
int dist(int x1, int y1, int x2, int y2);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int N, M, K, n;
	if (scanf("%d %d %d %d", &N, &M, &K, &n) == EOF) {
		return false;
	}
	vector<tTree> trees(n);
	vector<vector<bool>> iberia(N + 1, vector<bool>(M + 1, false));
	iberia[0][0] = true;
	iberia[N][M] = true;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &trees[i].x, &trees[i].y);
	}
	ConjuntosDisjuntos g((N + 1) * (M + 1));
	int i;
	for (i = n - 1; i >= 0; i--) {
		iberia[trees[i].x][trees[i].y] = true;
		solve(g, N+1, M+1, iberia, trees[i].x, trees[i].y, K);
		if (g.buscar(0) == g.buscar((N + 1) * (M + 1) - 1)) {
			printf("%d %d\n", trees[i].x, trees[i].y);
			break;
		}
	}
	if (i == -1) {
		printf("Nunca se pudo\n");
	}
	return true;
}

void solve(ConjuntosDisjuntos & g, int N, int M, vector<vector<bool>> & iberia,
		int x, int y, int K) {
	for (int i = -K; i <= K; i++) {
		for (int j = -K; j <= K; j++) {
			if ((x + i >= 0 && x + i < N) && (y + j >= 0 && y + j < M)
					&& dist(x, y, x + i, y + j) <= K && iberia[x + i][y + j]) {
				g.unir(x * M + y, (x + i) * M + y + j);
			}
		}
	}
}

int dist(int x1, int y1, int x2, int y2) {
	return ceil(sqrt(pow((double) (x1 - x2), 2) + pow((double) (y1 - y2), 2)));
}
