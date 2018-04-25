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
	int cities;
	vector<int> theirUnits;
	vector<int> ourUnits;

	if (scanf("%d", &cities) == EOF) {
		return false;
	}

	for (int i = 0; i < cities; i++) {
		int units;
		scanf("%d", &units);
		theirUnits.push_back(units);
	}

	for (int i = 0; i < cities; i++) {
		int units;
		scanf("%d", &units);
		ourUnits.push_back(units);
	}

	sort(theirUnits.begin(), theirUnits.end());
	sort(ourUnits.begin(), ourUnits.end());

	int sum = 0;
	int counter = cities - 1;
	for (int i = cities - 1; i >= 0 && counter >= 0; i--) {
		if (ourUnits[i] >= theirUnits[counter]) {
			sum++;
		} else {
			i++;
		}
		counter--;
	}

	printf("%d\n", sum);
	return true;
}
