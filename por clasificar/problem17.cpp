#include <iostream>
#include <queue>
#include "GrafoDirigidoValorado.h"

using namespace std;

typedef struct {
	int vertex;
	int distance;
} tNode;

class compare {
public:
	bool operator()(const tNode & left, const tNode & right) const {
		return left.distance > right.distance;
	}
};

bool solveCase();
void solve(GrafoDirigidoValorado<int> & g, int source, vector<int> & distances);

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
	GrafoDirigidoValorado<int> g(V);
	for (int i = 0; i < E; i++) {
		int begining, ending, cost;
		scanf("%d %d %d", &begining, &ending, &cost);
		g.ponArista(AristaDirigida<int>(begining - 1, ending - 1, cost));
	}
	int office, destinations, solution = 0;
	scanf("%d %d", &office, &destinations);
	vector<int> distances1(V, 1000000000), distances2(V, 1000000000);
	solve(g, office - 1, distances1);
	g = g.reverse();
	solve(g, office - 1, distances2);
	for (int i = 0; i < destinations; i++) {
		int destination;
		scanf("%d", &destination);
		solution += distances1[destination - 1] + distances2[destination - 1];
	}
	if (solution > 1000000000) {
		printf("Imposible\n");
		return true;
	}
	printf("%d\n", solution);
	return true;
}

void solve(GrafoDirigidoValorado<int> & g, int source,
		vector<int> & distances) {
	distances[source] = 0;
	priority_queue<tNode, vector<tNode>, compare> q;
	tNode node;
	node.vertex = source;
	node.distance = 0;
	q.push(node);

	while (!q.empty()) {
		node = q.top();
		q.pop();
		for (int i = 0; i < (int) (g.adj(node.vertex).size()); i++) {
			if (distances[g.adj(node.vertex)[i].to()]
					> distances[node.vertex] + g.adj(node.vertex)[i].valor()) {
				distances[g.adj(node.vertex)[i].to()] = distances[node.vertex]
						+ g.adj(node.vertex)[i].valor();
				tNode aux;
				aux.vertex = g.adj(node.vertex)[i].to();
				aux.distance = distances[node.vertex]
						+ g.adj(node.vertex)[i].valor();
				q.push(aux);
			}
		}
	}
}
