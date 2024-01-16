#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) { 
    if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;

	return 0;
}

int main() {
	int num1, num2;
	int a[200000];
	int b[200000];

	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < num2; i++)
		scanf("%d", &b[i]);

	qsort(a, num1, sizeof(int), compare);
	qsort(b, num2, sizeof(int), compare);

	int i = 0;
	int j = 0;
	int ans = 0;
	while (i < num1 && j < num2) {
        if (a[i] == b[j]) {
			++ans;
			++i;
			++j;
		} else if (a[i] < b[j])
			++i;
        else
			++j;
	}
	printf("%d\n", num1 - ans + num2 - ans);
}
