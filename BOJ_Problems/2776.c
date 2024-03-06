#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int idx = left; idx <= right; idx++)
        arr[idx] = temp[idx - left];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return 1;  
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0; 
}

int main() {
    int T;
    scanf("%d", &T); 

    while (T--) {
        int N, M;
        scanf("%d", &N); 
        int notebook1[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &notebook1[i]);  

        scanf("%d", &M); 
        int notebook2[M];
        for (int i = 0; i < M; i++)
            scanf("%d", &notebook2[i]); 
        
        mergeSort(notebook1, 0, N - 1);
 
        for (int i = 0; i < M; i++) {
            int found = binarySearch(notebook1, 0, N - 1, notebook2[i]);
            printf("%d ", found);
        }
        printf("\n");
    }

    return 0;
}
