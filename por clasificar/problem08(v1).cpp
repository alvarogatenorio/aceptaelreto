/*Problem 08
 * Álvaro García Tenorio
 * Doble grado de ingeniería informática y matemáticas*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int sheets;
	int musicians;
} tInstrument;

class compare {
public:
	bool operator()(const tInstrument & left, const tInstrument & right) const {
		int remLeft = 0, remRight = 0;
		if (left.musicians % left.sheets != 0) {
			remLeft = 1;
		}
		if (right.musicians % right.sheets != 0) {
			remRight = 1;
		}
		return (left.musicians / left.sheets) + remLeft
				< (right.musicians / right.sheets) + remRight;
	}
};

bool solveCase();
int solve(int remaining,
		priority_queue<tInstrument, vector<tInstrument>, compare> & list);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int sheets, instruments;
	cin >> sheets >> instruments;
	if (!cin) {
		return false;
	} else {
		priority_queue<tInstrument, vector<tInstrument>, compare> list;
		for (int i = 0; i < instruments; i++) {
			tInstrument instrument;
			cin >> instrument.musicians;
			instrument.sheets = 1;
			list.push(instrument);
		}
		int remaining = sheets - instruments;
		cout << solve(remaining, list) << endl;
		return true;
	}
}

int solve(int remaining,
		priority_queue<tInstrument, vector<tInstrument>, compare> & list) {
	for (int i = 0; i < remaining; i++) {
		tInstrument instrument = list.top();
		list.pop();
		instrument.sheets++;
		list.push(instrument);
	}
	if ((list.top().musicians % list.top().sheets) == 0) {
		return list.top().musicians / list.top().sheets;
	} else
		return (list.top().musicians / list.top().sheets) + 1;
}
