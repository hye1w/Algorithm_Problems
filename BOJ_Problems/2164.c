#include <stdio.h>
#define SIZE 500000

int main()
{
	int n, i, front = 0, rear;
	int q[SIZE];
	scanf("%d", &n);
	for (i = 0; i < n; i++) q[i] = i + 1;
	rear = n - 1;
	while (1) {
		front = (front + 1) % n;
		if (rear == front) break;
		rear = (rear + 1) % n;
		q[rear] = q[front];
		front = (front + 1) % n;
		if (rear == front) break;
	}
	printf("%d", q[rear]);
	return 0;
} 
