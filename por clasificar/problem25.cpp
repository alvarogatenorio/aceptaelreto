#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int begining;
	int ending;
} tConf;

bool compare(const tConf & f1, const tConf & f2) {
	return f1.begining < f2.begining;
}

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int confs;
	vector<tConf> schedule;
	priority_queue<int> rooms;

	scanf("%d", &confs);

	if (confs == 0) {
		return false;
	}

	for (int i = 0; i < confs; i++) {
		tConf conf;
		scanf("%d %d", &conf.begining, &conf.ending);
		schedule.push_back(conf);
	}

	sort(schedule.begin(), schedule.end(), compare);

	for (int i = 0; i < confs; i++) {
		if (!rooms.empty() && rooms.top() >= -schedule[i].begining) {
			rooms.pop();
		}
		rooms.push(-schedule[i].ending);
	}

	printf("%d\n", (int) (rooms.size()));
	return true;
}
