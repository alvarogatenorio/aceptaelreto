#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	vector<int> solution;
	int level;
	int cost;
	int optimistCost;
	vector<bool> taken;
} tNode;

class compare {
public:
	bool operator()(const tNode & left, const tNode & right) const {
		return left.optimistCost > right.optimistCost;
	}
};

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Reading and calculating useful stuff*/
	int N;
	scanf("%d", &N);
	if (N == 0) {
		return false;
	}
	vector<vector<int>> table(N, vector<int>(N));
	vector<int> fast(N, 10000);
	vector<int> slow(N, 0);
	vector<int> lowerBound(N + 1, 0);
	vector<int> upperBound(N + 1, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &table[i][j]);
			slow[i] = max(slow[i], table[i][j]);
			fast[i] = min(fast[i], table[i][j]);
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		lowerBound[i] = lowerBound[i + 1] + fast[i];
		upperBound[i] = upperBound[i + 1] + slow[i];
	}
	/*Finding the solution to the problem*/
	vector<int> bestSolution(N);
	int bestCost = upperBound[0];
	tNode root;
	root.cost = 0;
	root.level = -1;
	root.optimistCost = lowerBound[0];
	root.taken = vector<bool>(N, false);
	root.solution = bestSolution;
	priority_queue<tNode, vector<tNode>, compare> q;
	q.push(root);
	while (!q.empty() && q.top().optimistCost < bestCost) {
		tNode father = q.top();
		q.pop();
		tNode child = father;
		child.level++;
		for (int i = 0; i < N; i++) {
			if (!father.taken[i]) {
				child.solution[child.level] = i;
				child.taken[i] = true;
				child.cost = father.cost + table[child.level][i];
				child.optimistCost = child.cost + lowerBound[child.level + 1];
				if (child.optimistCost < bestCost) {
					if (child.level == N - 1) {
						bestCost = child.optimistCost;
						bestSolution = child.solution;
					} else {
						q.push(child);
						bestCost = min(bestCost,
								child.cost + upperBound[child.level + 1]);
					}
				}
				child.taken[i] = false;
			}
		}
	}
	printf("%d\n", bestCost);
	return true;
}
