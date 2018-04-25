/*Problem 425*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool solveCase();
unsigned char solve(char word[], unsigned char size);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*-----Reads the word-----*/
	char word[101];
	unsigned char i = 0; /*Represents the word size*/
	if (scanf("%c", &word[i]) == EOF) {
		return false;
	}
	while (word[i] != '\n') {
		i++;
		scanf("%c", &word[i]);
	}
	printf("%d\n", solve(word, i));
	return true;
}

unsigned char solve(char word[], unsigned char size) {
	unsigned char miniTable[2][size];
	memset(miniTable[0], 0, size);
	memset(miniTable[1], 0, size);

	/*Walk by diagonals (i represents the diagonal number)*/
	for (int i = 1; i < size; i++) {
		/*j represents the row*/
		for (int j = size - i - 1; j >= 0; j--) {
			unsigned char aux = miniTable[0][j + i];
			/*column can be obtained as i+j*/
			if (word[j] == word[j + i]) {
				miniTable[0][j + i] = miniTable[1][(j + i) - 1];
			} else {
				miniTable[0][j + i] = min(miniTable[0][j + i],
						miniTable[0][j + i - 1]) + 1;
			}
			miniTable[1][j + i] = aux;
		}
	}
	return miniTable[0][size - 1];
}
