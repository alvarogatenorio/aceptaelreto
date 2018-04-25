#include <iostream>
#include <algorithm>
#include "ConjuntosDisjuntos.h"

using namespace std;

void solveCase();

int main() {
	int casesNumber;
	scanf("%d", &casesNumber);
	for (int i = 0; i < casesNumber; i++) {
		solveCase();
	}
	return 0;
}

void solveCase() {
	int V, E;
	scanf("%d %d", &V, &E);
	ConjuntosDisjuntos g(V);
	for (int i = 0; i < E; i++) {
		int begin, end;
		scanf("%d %d", &begin, &end);
		g.unir(begin - 1, end - 1);
	}
	int m = 0;
	for (int i = 0; i < V; i++) {
		m = max((int)g.size(i), m);
	}
	printf("%d\n", m);
}
