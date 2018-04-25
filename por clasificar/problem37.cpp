#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int beginning;
	int length;
} tFilm;

bool solveCase();

bool compare(const tFilm & left, const tFilm & right) {
	return left.beginning < right.beginning;
}

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Reading stuff*/
	int N;
	scanf("%d", &N);
	if (N == 0) {
		return false;
	}
	vector<tFilm> films(N);
	for (int i = 0; i < N; i++) {
		int hour, minute;
		scanf("%d:%d", &hour, &minute);
		scanf("%d", &films[i].length);
		films[i].beginning = hour * 60 + minute;
	}
	sort(films.begin(), films.end(), compare);
	/*Filling table*/
	vector<int> table(N);
	for (int i = N - 1; i >= 0; i--) {
		int maximum = 0;
		/*For every film overlapping with j beginning after i*/
		for (int j = i;
				j < N
						&& (films[j].beginning
								- (films[i].beginning + films[i].length)) < 10;
				j++) {
			int remaining = 0;
			for (int k = j + 1; k < N; k++) {
				if ((films[k].beginning - (films[j].beginning + films[j].length))
						>= 10) {
					remaining = table[k];
					break;
				}
			}
			maximum = max(maximum, films[j].length + remaining);
		}
		table[i] = maximum;
	}
	printf("%d\n", table[0]);
	return true;
}
