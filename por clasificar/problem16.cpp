#include <iostream>
#include <vector>
#include <queue>
#include "GrafoValorado.h"

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
	GrafoValorado<int> g(V);
	for (int i = 0; i < E; i++) {
		int begining, ending, cost;
		scanf("%d %d %d", &begining, &ending, &cost);
		g.ponArista(Arista<int>(begining - 1, ending - 1, cost));
	}

	vector<int> distances(V, 1000000000);
	vector<int> ways(V, 0);
	vector<bool> marked(V, false);
	distances[0] = 0;
	ways[0] = 1;
	priority_queue<tNode, vector<tNode>, compare> q;
	tNode node;
	node.vertex = 0;
	node.distance = 0;
	q.push(node);

	while (!q.empty()) {
		node = q.top();
		q.pop();
		if (marked[node.vertex]) {
			continue;
		}
		marked[node.vertex] = true;
		for (int i = 0; i < (int) (g.adj(node.vertex).size()); i++) {
			if (distances[g.adj(node.vertex)[i].otro(node.vertex)]
					> distances[node.vertex] + g.adj(node.vertex)[i].valor()) {
				distances[g.adj(node.vertex)[i].otro(node.vertex)] =
						distances[node.vertex] + g.adj(node.vertex)[i].valor();
				tNode aux;
				aux.vertex = g.adj(node.vertex)[i].otro(node.vertex);
				aux.distance = distances[node.vertex]
						+ g.adj(node.vertex)[i].valor();
				ways[aux.vertex] = ways[node.vertex];
				q.push(aux);
			} else if (distances[g.adj(node.vertex)[i].otro(node.vertex)]
					== distances[node.vertex] + g.adj(node.vertex)[i].valor()) {
				ways[g.adj(node.vertex)[i].otro(node.vertex)] +=
						ways[node.vertex];
			}
		}
	}
	printf("%d\n", ways[V - 1]);
	return true;
}
