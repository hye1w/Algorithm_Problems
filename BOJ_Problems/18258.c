#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 2000000

#include <stdio.h> 
#include <string.h>

int queue[MAXSIZE];
int front = 0;
int rear = -1;

void push(int key)
{
	queue[front] = key;
	front++;
}

int pop(void)
{
	if (empty()==1)
	{
		return -1;
	}
	rear++;
	return queue[rear];
}

int size(void)
{
	return front - rear - 1;
}

int empty(void)
{
	if (front - rear - 1 == 0) {
		return 1;
	}
	else 
        return 0;
}

int frontprint(void)
{
	if (empty() == 1) {
		return -1;
	}
	else return queue[rear + 1];
}

int backprint(void)
{
	if (empty() == 1) {
		return -1;
	}
	else return queue[front-1];
}

int main()
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) 
    {
		char user[6];
		scanf("%s", user);

		if (!strcmp(user, "push")) {
			int key;
			scanf("%d", &key);
			push(key);
		}

		else if (!strcmp(user, "pop")) {
			printf("%d\n", pop());
		}

		else if (!strcmp(user, "size")) {
			printf("%d\n", size());
		}

		else if (!strcmp(user, "empty")) {
			printf("%d\n", empty());
		}

		else if (!strcmp(user, "front")) {
			printf("%d\n", frontprint());
		}

		else if (!strcmp(user, "back")) {
			printf("%d\n", backprint());
		}
	}
}
