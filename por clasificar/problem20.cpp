#include <iostream>
#include <algorithm>
using namespace std;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int holes;
	int length;

	if (scanf("%d %d", &holes, &length) == EOF) {
		return false;
	}

	int patchs = 0;
	int holePosition;
	int lastPatchPosition;

	if (holes > 0) {
		scanf("%d", &holePosition);
		lastPatchPosition = holePosition;
		patchs++;
	}
	for (int i = 1; i < holes; i++) {
		scanf("%d", &holePosition);
		if (abs(lastPatchPosition - holePosition) > length) {
			lastPatchPosition = holePosition;
			patchs++;
		}
	}

	printf("%d\n", patchs);
	return true;
}
