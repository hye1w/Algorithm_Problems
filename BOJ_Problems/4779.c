#include <stdio.h>
#include <math.h>

void kan(int n) {
	if (n) {
		kan(n - 1);
		for (int i = 0; i < pow(3, n-1); i++) {
			printf(" ");
		}
		kan(n - 1);
	}
	else {
		printf("-");
	}
}

int main() {
	int n = 0;
	while (scanf("%d", &n) != EOF) {
		kan(n);
		printf("\n");
	}
}
