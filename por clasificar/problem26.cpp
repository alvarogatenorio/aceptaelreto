#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int begining;
	int ending;
} tWork;

bool compare(const tWork & f1, const tWork & f2) {
	return f1.begining < f2.begining;
}

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int C, F, N;
	vector<tWork> works;

	scanf("%d %d %d", &C, &F, &N);
	if (C == 0 && F == 0 && N == 0) {
		return false;
	}

	for (int i = 0; i < N; i++) {
		tWork work;
		scanf("%d %d", &work.begining, &work.ending);
		works.push_back(work);
	}

	sort(works.begin(), works.end(), compare);

	int sum = 0;
	int leftmost = C;
	int rightmost = C;
	int chosenIndex = -1;
	for (int i = 0; i < N && rightmost < F; i++) {
		if (works[i].begining <= leftmost) {
			if (works[i].ending > rightmost) {
				rightmost = works[i].ending;
				chosenIndex = i;
			}
		} else {
			if (chosenIndex != -1) {
				leftmost = rightmost;
				chosenIndex = -1;
				sum++;
				i--;
			} else {
				break;
			}
		}
	}

	if (chosenIndex != -1) {
		sum++;
	}

	if (rightmost < F) {
		printf("Imposible\n");
	} else {
		printf("%d\n", sum);
	}

	return true;
}
