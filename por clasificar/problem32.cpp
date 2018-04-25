#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solveCase();
void readWord(char separator, vector<char> & word);
int mapInsertion(int & counter, map<vector<char>, int> & names,
		const vector<char> & name);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Reading stuff*/
	int people;
	int relations;
	if (scanf("%d %d\n", &people, &relations) == EOF) {
		return false;
	}
	vector<vector<int>> table(people, vector<int>(people, people + 1));
	int counter = 0;
	map<vector<char>, int> names;
	for (int i = 0; i < relations; i++) {
		vector<char> name;
		readWord(' ', name);
		int id1 = mapInsertion(counter, names, name);
		name.clear();
		readWord('\n', name);
		int id2 = mapInsertion(counter, names, name);
		table[id1][id2] = 1;
		table[id2][id1] = 1;
	}
	for (int i = 0; i < people; i++) {
		table[i][i] = 0;
	}
	/*Filling table*/
	int maxSeparation;
	for (int k = 0; k < people; k++) {
		maxSeparation = 0;
		for (int i = 0; i < people; i++) {
			for (int j = 0; j < people; j++) {
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
				maxSeparation = max(maxSeparation, table[i][j]);
			}
		}
	}
	if (maxSeparation == people + 1) {
		printf("DESCONECTADA\n");
	} else {
		printf("%d\n", maxSeparation);
	}
	return true;
}

void readWord(char separator, vector<char> & word) {
	char c;
	scanf("%c", &c);
	while (c != separator) {
		word.push_back(c);
		scanf("%c", &c);
	}
}

int mapInsertion(int & counter, map<vector<char>, int> & names,
		const vector<char> & name) {
	map<vector<char>, int>::iterator it = names.find(name);
	if (it == names.end()) {
		it = names.insert(pair<vector<char>, int>(name, counter)).first;
		counter++;
	}
	return it->second;
}
