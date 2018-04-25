#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int games;
	vector<int> theirPoints;
	vector<int> ourPoints;

	scanf("%d", &games);
	if (games == 0) {
		return false;
	}

	for (int i = 0; i < games; i++) {
		int points;
		scanf("%d", &points);
		theirPoints.push_back(points);
	}

	for (int i = 0; i < games; i++) {
		int points;
		scanf("%d", &points);
		ourPoints.push_back(points);
	}

	sort(theirPoints.begin(), theirPoints.end());
	sort(ourPoints.begin(), ourPoints.end());

	int sum = 0;
	for (int i = 0; i < games; i++) {
		int difference = ourPoints[games - 1 - i] - theirPoints[i];
		if (difference > 0) {
			sum += difference;
		} else {
			break;
		}
	}

	printf("%d\n", sum);
	return true;
}
