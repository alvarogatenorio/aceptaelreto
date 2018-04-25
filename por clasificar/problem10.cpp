#include <iostream>
#include <vector>
#include "Grafo.h"

using namespace std;

bool solveCase();
bool solve(Grafo & g, int vertex, int v[], bool marked[], int color);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int V, E;
	if (scanf("%d %d", &V, &E) == EOF) {
		return false;
	}
	Grafo g(V);

	int v[100];
	bool marked[100];
	for (int i = 0; i < 100; i++) {
		v[i] = -1;
		marked[i] = false;
	}

	for (int i = 0; i < E; i++) {
		int begin, end;
		scanf("%d %d", &begin, &end);
		g.ponArista(begin, end);
	}

	for (int i = 0; i < V; i++) {
		if (v[i] != -1) {
			continue;
		} else {
			if (!solve(g, i, v, marked, 0)) {
				printf("NO\n");
				return true;
			}
		}
	}
	printf("SI\n");
	return true;
}

bool solve(Grafo & g, int vertex, int v[], bool marked[], int color) {
	marked[vertex] = true;
	v[vertex] = color;
	for (int i = 0; i < (int)(g.adj(vertex).size()); i++) {
		if (marked[g.adj(vertex).at(i)]
				&& v[g.adj(vertex).at(i)] != (color + 1) % 2) {
			return false;
		} else if (!marked[g.adj(vertex).at(i)]) {
			if (!solve(g, g.adj(vertex).at(i), v, marked, (color + 1) % 2)) {
				return false;
			}
		}
	}
	return true;
}
