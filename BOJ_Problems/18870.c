#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Coord {
	int x;		 
	int loc;	 
	int compress;	 
} Coord;

int flag;	 

int compare(const void* a, const void* b) {
	Coord A = *(Coord*)a;
	Coord B = *(Coord*)b;
	
	if (!flag) {
		if (A.x > B.x)
			return 1;
		else if (A.x < B.x)
			return -1;
		else
			return 0;
	}
	else { 
		if (A.loc > B.loc)
			return 1;
		else if (A.loc < B.loc)
			return -1;
		else
			return 0;
	}
}

int main() {
	int N, i;
	scanf("%d", &N);
	Coord* coord = (Coord*)calloc(N, sizeof(Coord));
	for (i = 0; i < N; i++) {
		scanf("%d", &coord[i].x);
		coord[i].loc = i;
	}
	 
	qsort(coord, N, sizeof(Coord), compare);

	for (i = 1; i < N; i++) {
		if (coord[i].x == coord[i - 1].x)
			coord[i].compress = coord[i - 1].compress;
		else
			coord[i].compress = coord[i - 1].compress + 1;
	}
	flag = 1;
	
	qsort(coord, N, sizeof(Coord), compare);

	for (i = 0; i < N; i++)
		printf("%d ", coord[i].compress);

	return 0;
}
