/*Problem 03
 * Álvaro García Tenorio
 * Doble grado de ingeniería informática y matemáticas*/

#include <iostream>
#include <cstdlib> //for the abs function.
#include <climits> //for INT_MAX
#include <map> //for the map data structure.
using namespace std;

int SPECIAL_CASE = 0;
bool JUNK = false;

bool solveCase();
void buildTree(map<int, bool> & tree, int keysNumber);
void solve(map<int, bool> & tree, int k1, int k2);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int keysNumber;
	cin >> keysNumber;
	if (keysNumber == SPECIAL_CASE) {
		return false;
	} else {
		map<int, bool> tree;
		buildTree(tree, keysNumber);
		int k1, k2;
		cin >> k1 >> k2;
		solve(tree, k1, k2);
		return true;
	}
}

void buildTree(map<int, bool> & tree, int keysNumber) {
	int key;
	for (int i = 0; i < keysNumber; i++) {
		cin >> key;
		tree.insert(pair<int, bool>(key, JUNK));
	}
}

void solve(map<int, bool> & tree, int k1, int k2) {
	map<int, bool>::iterator it;
	it = tree.lower_bound(k1);
	while (it != tree.end() && it->first <= k2) {
		cout << it->first;
		it++;
		if (it != tree.end() && it->first <= k2) {
			cout << " ";
		}
	}
	cout << endl;
}
