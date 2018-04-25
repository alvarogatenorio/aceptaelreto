#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solveCase();
void readWord(char c, vector<char> & word, char separator);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Reading stuff*/
	vector<char> word1, word2;
	char c;
	if (scanf("%c", &c) == EOF) {
		return false;
	}
	readWord(c, word1, ' ');
	scanf("%c", &c);
	readWord(c, word2, '\n');
	/*Filling table*/
	vector<vector<int>> table(2, vector<int>(word1.size() + 1, 0));
	int updated = 1;
	int outdated = 0;
	for (int i = 1; i < (int) word2.size() + 1; i++) {
		for (int j = 1; j < (int) word1.size() + 1; j++) {
			if (word2[i - 1] == word1[j - 1]) {
				table[updated][j] = table[outdated][j - 1] + 1;
			} else {
				table[updated][j] = max(table[updated][j - 1],
						table[outdated][j]);
			}
		}
		updated = (updated + 1) % 2;
		outdated = (outdated + 1) % 2;
	}
	/*Printing results*/
	printf("%d\n", table[outdated][word1.size()]);
	return true;
}

void readWord(char c, vector<char> & word, char separator) {
	while (c != separator) {
		word.push_back(c);
		scanf("%c", &c);
	}
}
