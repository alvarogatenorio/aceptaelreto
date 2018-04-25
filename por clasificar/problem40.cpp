#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int duration;
	int score;
} tSong;

typedef struct {
	vector<int> solution;
	int level;
	int durationSide1;
	int durationSide2;
	int score;
	double stimation;
} tNode;

bool compareSongs(const tSong & left, const tSong & right) {
	return (double) ((double) left.score / (double) left.duration)
			>= (double) ((double) right.score / (double) right.duration);
}

class compareNode {
public:
	bool operator()(const tNode & left, const tNode & right) const {
		return left.stimation < right.stimation;
	}
};

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

void computeBounds(double & optimist, int & pesimist, const tNode & node,
		const vector<tSong> & songs, int sideCapacity) {
	pesimist = node.score;
	optimist = node.score;
	int level = node.level + 1;
	int N = (int) node.solution.size();
	/*optimist bound*/
	int availableCapacity = 2 * sideCapacity;
	while (level < N && songs[level].duration <= availableCapacity) {
		availableCapacity -= songs[level].duration;
		optimist += songs[level].score;
		level++;
	}
	if (level < N) {
		optimist +=
				((double) availableCapacity / (double) songs[level].duration)
						* (double) songs[level].score;
	}
	level = node.level + 1;
	/*pesimist bound*/
	for (int side = 1; side <= 2; side++) {
		int availableCapacity = sideCapacity
				- (side == 1 ? node.durationSide1 : node.durationSide2);
		while (level < N && songs[level].duration <= availableCapacity) {
			availableCapacity -= songs[level].duration;
			pesimist += songs[level].score;
			level++;
		}
		if (level < N) {
			level++;
			while (level < N && availableCapacity >= 0) {
				if (songs[level].duration <= availableCapacity) {
					availableCapacity -= songs[level].duration;
					pesimist += songs[level].score;
				}
				level++;
			}
		}
	}
}

bool solveCase() {
	/*---Reading and calculating stuff---*/
	int N; /*number of songs*/
	scanf("%d", &N);
	if (N == 0) { /*last case*/
		return false;
	}
	int sideCapacity; /*capacity of one side of the tape*/
	scanf("%d", &sideCapacity);
	vector<tSong> songs(N); /*songs data*/
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &songs[i].duration, &songs[i].score);
	}
	sort(songs.begin(), songs.end(), compareSongs);
	/*---Solving the problem---*/
	int pesimist;
	int bestScore = 0;
	vector<int> bestSolution(N);
	tNode root; /*root node, nothing selected*/
	root.durationSide1 = 0;
	root.durationSide2 = 0;
	root.level = -1;
	root.score = 0;
	root.solution = vector<int>(N, 0);
	computeBounds(root.stimation, pesimist, root, songs, sideCapacity);
	bestScore = pesimist;
	priority_queue<tNode, vector<tNode>, compareNode> q;
	q.push(root);
	while (!q.empty() && (q.top().stimation > bestScore)) {
		tNode father = q.top();
		q.pop();
		tNode child = father;
		child.level++;
		if (father.durationSide1 + songs[child.level].duration
				<= sideCapacity) {
			child.solution[child.level] = 1;
			child.durationSide1 = father.durationSide1
					+ songs[child.level].duration;
			child.score = father.score + songs[child.level].score;
			computeBounds(child.stimation, pesimist, child, songs,
					sideCapacity);
			if (child.level == N - 1 && child.score > bestScore) {
				bestScore = child.score;
			} else if (child.level != N - 1 && child.stimation > bestScore) {
				q.push(child);
				bestScore = max(bestScore, pesimist);
			}
		}
		if (father.durationSide1 != father.durationSide2
				&& father.durationSide2 + songs[child.level].duration
						<= sideCapacity) {
			child.solution[child.level] = 2;
			child.durationSide1 = father.durationSide1;
			child.durationSide2 = father.durationSide2
					+ songs[child.level].duration;
			child.score = father.score + songs[child.level].score;
			computeBounds(child.stimation, pesimist, child, songs,
					sideCapacity);
			if (child.level == N - 1 && child.score > bestScore) {
				bestScore = child.score;
			} else if (child.level != N - 1 && child.stimation > bestScore) {
				q.push(child);
				bestScore = max(bestScore, pesimist);
			}
		}
		father.level++;
		computeBounds(child.stimation, pesimist, father, songs, sideCapacity);
		if (child.stimation > bestScore) {
			child.solution[child.level] = 0;
			child.durationSide1 = father.durationSide1;
			child.durationSide2 = father.durationSide2;
			child.score = father.score;
			if (child.level == N - 1 && child.score > bestScore) {
				bestScore = child.score;
			} else if (child.level != N - 1) {
				q.push(child);
				bestScore = max(bestScore, pesimist);
			}
		}
	}
	printf("%d\n", bestScore);
	return true;
}
