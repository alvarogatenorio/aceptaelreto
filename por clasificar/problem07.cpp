/*Problem 07
 * Álvaro García Tenorio
 * Doble grado de ingeniería informática y matemáticas*/

#include <iostream>
#include <queue> //for heaps
using namespace std;

unsigned long long int SPECIAL_CASE = 0;

bool solveCase();
unsigned long long int solve(unsigned long long int age,
		priority_queue<unsigned long long int> & min,
		priority_queue<unsigned long long int> & max);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	unsigned long long int age, couples;
	cin >> age >> couples;
	if (age == SPECIAL_CASE && couples == SPECIAL_CASE) {
		return false;
	} else {
		priority_queue<unsigned long long int> min;
		priority_queue<unsigned long long int> max;
		for (unsigned long long int i = 0; i < couples; i++) {
			age = solve(age, min, max);
			cout << age;
			if (i != couples - 1)
				cout << " ";
		}
		cout << endl;
		return true;
	}
}

unsigned long long int solve(unsigned long long int age,
		priority_queue<unsigned long long int> & min,
		priority_queue<unsigned long long int> & max) {
	unsigned long long int bird1, bird2;
	cin >> bird1 >> bird2;
	if (age < bird1 && age < bird2) {
		max.push(age);
		min.push(-bird1);
		min.push(-bird2);
		age = -min.top();
		min.pop();
	} else if (bird1 < age && bird2 < age) {
		min.push(-age);
		max.push(bird1);
		max.push(bird2);
		age = max.top();
		max.pop();
	} else if (bird1 < age && age < bird2) {
		max.push(bird1);
		min.push(-bird2);
	} else {
		max.push(bird2);
		min.push(-bird1);
	}
	return age;
}
