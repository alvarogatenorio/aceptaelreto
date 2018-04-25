/*Problem 05
 * Álvaro García Tenorio
 * Doble grado de ingeniería informática y matemáticas*/

#include <iostream>
#include <queue> //for the priority queue
using namespace std;

int SPECIAL_CASE = 0;

bool solveCase();
unsigned long long int solve(
		priority_queue<unsigned long long int> & priorityQueue);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int teamsNumber;
	cin >> teamsNumber;
	if (teamsNumber == SPECIAL_CASE) {
		return false;
	} else {
		priority_queue<unsigned long long int> priorityQueue;
		for (int i = 0; i < teamsNumber; i++) {
			unsigned long long int followers;
			cin >> followers;
			priorityQueue.push(-followers);
		}
		cout << solve(priorityQueue) << endl;
		return true;
	}
}

unsigned long long int solve(
		priority_queue<unsigned long long int> & priorityQueue) {
	unsigned long long int hats = 0;
	while (priorityQueue.size() > 1) {
		unsigned long long int team1 = priorityQueue.top();
		priorityQueue.pop();
		unsigned long long int team2 = priorityQueue.top();
		priorityQueue.pop();
		hats += team1 + team2;
		priorityQueue.push(team1 + team2);
	}
	return -hats;
}
