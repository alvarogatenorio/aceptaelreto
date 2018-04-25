#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int begining;
	int ending;
} tFilm;

bool compare(const tFilm & f1, const tFilm & f2) {
	return f1.ending < f2.ending;
}

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int films;
	vector<tFilm> schedule;

	scanf("%d", &films);

	if (films == 0) {
		return false;
	}

	for (int i = 0; i < films; i++) {
		tFilm film;
		int data;
		char trash;
		scanf("%d", &data);
		film.begining = data * 60;
		scanf("%c", &trash);
		scanf("%d", &data);
		film.begining += data;
		scanf("%d", &data);
		film.ending = film.begining + data;
		schedule.push_back(film);
	}

	sort(schedule.begin(), schedule.end(), compare);

	int sum = 1;
	int previous = schedule[0].ending;
	for (int i = 0; i < films; i++) {
		if (schedule[i].begining >= previous + 10) {
			sum++;
			previous = schedule[i].ending;
		}
	}

	printf("%d\n", sum);
	return true;
}
