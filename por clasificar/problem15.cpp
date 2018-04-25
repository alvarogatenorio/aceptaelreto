#include <iostream>
#include <algorithm>
#include <vector>
#include "ConjuntosDisjuntos.h"

using namespace std;

typedef struct {
	int begining;
	int ending;
	int cost;
} tEdge;

bool compare(tEdge a, tEdge b) {
	return a.cost < b.cost;
}

bool solveCase();
void solve(ConjuntosDisjuntos & d, vector<tEdge> & edges, int V, int E);

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
	ConjuntosDisjuntos d(V);
	vector<tEdge> edges(E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &edges[i].begining, &edges[i].ending, &edges[i].cost);
	}
	solve(d, edges, V, E);
	return true;
}

void solve(ConjuntosDisjuntos & d, vector<tEdge> & edges, int V, int E) {
	int treeSize = 1;
	int edgeCounter = 0;
	int totalCost = 0;
	sort(edges.begin(), edges.end(), compare);
	while (edgeCounter < E && treeSize < V) {
		tEdge e = edges[edgeCounter];
		if (d.buscar(e.begining - 1) != d.buscar(e.ending - 1)) {
			d.unir(e.begining - 1, e.ending - 1);
			treeSize++;
			totalCost += e.cost;
		}
		edgeCounter++;
	}
	if (treeSize != V) {
		printf("Imposible\n");
	} else {
		printf("%d\n", totalCost);
	}
}
