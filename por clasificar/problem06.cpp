/*Problem 06
 * Álvaro García Tenorio
 * Doble grado de ingeniería informática y matemáticas*/

#include <iostream>
#include <vector>
#include <queue> //for the priority queue
using namespace std;

int SPECIAL_CASE = 0;

typedef struct {
	unsigned long long int originalPeriod;
	unsigned long long int period;
	unsigned long long int id;
} tUser;

class compare {
public:
	bool operator()(const tUser & left, const tUser & right) const {
		if (left.period == right.period) {
			return left.id > right.id;
		} else {
			return left.period > right.period;
		}
	}
};

bool solveCase();
void solve(priority_queue<tUser, vector<tUser>, compare> & priorityQueue,
		int notifications);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int usersNumber;
	cin >> usersNumber;
	if (usersNumber == SPECIAL_CASE) {
		return false;
	} else {
		priority_queue<tUser, vector<tUser>, compare> priorityQueue;
		for (int i = 0; i < usersNumber; i++) {
			tUser user;
			cin >> user.id >> user.period;
			user.originalPeriod = user.period;
			priorityQueue.push(user);
		}
		int notifications;
		cin >> notifications;
		solve(priorityQueue, notifications);
		return true;
	}
}

void solve(priority_queue<tUser, vector<tUser>, compare> & priorityQueue,
		int notifications) {
	tUser user;
	for (int i = 0; i < notifications; i++) {
		user = priorityQueue.top();
		cout << user.id << endl;
		priorityQueue.pop();
		user.period += user.originalPeriod;
		priorityQueue.push(user);
	}
	cout << "----" << endl;
}
