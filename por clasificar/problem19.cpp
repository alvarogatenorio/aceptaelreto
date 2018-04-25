#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int numBooks;
	vector<int> bookPrices;

	if (scanf("%d", &numBooks) == EOF) {
		return false;
	}

	for (int i = 0; i < numBooks; i++) {
		int price;
		scanf("%d", &price);
		bookPrices.push_back(price);
	}

	sort(bookPrices.begin(), bookPrices.end());

	int sum = 0;
	for (int i = numBooks - 3; i >= 0; i -= 3) {
		sum += bookPrices[i];
	}

	printf("%d\n", sum);
	return true;
}
