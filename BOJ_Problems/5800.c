#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Class %d\n", i + 1);

        int size;
        scanf("%d", &size);

        int* classI = (int*)malloc(size * sizeof(int));
        for (int k = 0; k < size; k++)
            scanf("%d", &classI[k]);
 
        for (int m = 0; m < size - 1; m++) {
            for (int j = 0; j < size - m - 1; j++) {
                if (classI[j] > classI[j + 1]) {
                    int temp = classI[j];
                    classI[j] = classI[j + 1];
                    classI[j + 1] = temp;
                }
            }
        }

        printf("Max %d, Min %d, ", classI[size - 1], classI[0]);

        int gap = 0;
        for (int j = 0; j < size - 1; j++) {
            if ((classI[j + 1] - classI[j]) > gap) {
                gap = classI[j + 1] - classI[j];
            }
        }
        printf("Largest gap %d\n", gap);

        free(classI);
    }

    return 0;
}
