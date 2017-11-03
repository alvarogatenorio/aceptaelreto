/*Problem 126
 * Álvaro García Tenorio*/

#include <stdio.h>

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	unsigned long long int p, n;
	scanf("%llu %llu", &p, &n);
	if ((signed long long int) (p) <= 0 || (signed long long int) (n) < 0) {
		return false;
	}
	if (n == 0) {
		n++;
	}
	if (p <= n) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return true;
}
