#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int length;
	int cost;
} tCord;

typedef struct {
	unsigned long long int waysNumber;
	unsigned long long int minCords;
	unsigned long long int minCost;
} tSolution;

bool solveCase();
int euclides(int a, int b);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	int cords;
	if (scanf("%d", &cords) == EOF) {
		return false;
	}
	int target;
	scanf("%d", &target);

	vector<tCord> cordsData;
	int gcd = 0;
	for (int i = 0; i < cords; i++) {
		tCord s;
		scanf("%d %d", &(s.length), &(s.cost));
		cordsData.push_back(s);
		gcd = euclides(s.length, gcd);
	}

	int reduced = target / gcd + 1;
	if (target % gcd != 0) {
		printf("NO\n");
		return true;
	}

	vector<tSolution> table(reduced);
	table[0].waysNumber = 1;
	table[0].minCords = 0;
	table[0].minCost = 0;
	for (int i = 1; i < reduced; i++) {
		if (cordsData[0].length / gcd == i) {
			table[i].waysNumber = 1;
			table[i].minCords = 1;
			table[i].minCost = cordsData[0].cost;
		} else {
			table[i].waysNumber = 0;
			table[i].minCords = 0;
			table[i].minCost = 0;
		}
	}

	for (int i = 1; i < cords; i++) {
		for (int j = reduced - 1;
				(j >= 1) && ((j - cordsData[i].length / gcd) >= 0); j--) {

			/*Updating the ways number*/
			table[j].waysNumber = table[j].waysNumber
					+ table[j - cordsData[i].length / gcd].waysNumber;

			/*Updating the minimum cords and the minimum cost*/
			if (table[j - cordsData[i].length / gcd].waysNumber != 0
					&& table[j].waysNumber
							== table[j - cordsData[i].length / gcd].waysNumber) {
				table[j].minCords =
						table[j - cordsData[i].length / gcd].minCords + 1;
				table[j].minCost = table[j - cordsData[i].length / gcd].minCost
						+ cordsData[i].cost;
			} else if ((table[j - cordsData[i].length / gcd].waysNumber != 0
					&& table[j].waysNumber
							!= table[j - cordsData[i].length / gcd].waysNumber)) {
				table[j].minCords = min(table[j].minCords,
						table[j - cordsData[i].length / gcd].minCords + 1);
				table[j].minCost = min(table[j].minCost,
						table[j - cordsData[i].length / gcd].minCost
								+ cordsData[i].cost);
			}
		}
	}

	if (table[reduced - 1].waysNumber == 0) {
		printf("NO\n");
	} else {
		printf("SI %llu %llu %llu\n", table[reduced - 1].waysNumber,
				table[reduced - 1].minCords, table[reduced - 1].minCost);
	}

	return true;
}

int euclides(int a, int b) {
	return (b == 0) ? a : euclides(b, a % b);
}
