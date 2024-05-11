#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Student {
    char name[20];
    int age;
    int grade;
    int id;
};
 
int compare(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;

    // 성적이 같으면 나이가 많은 순으로 정렬
    if (studentA->id == studentB->id) {
        if (studentA->grade == studentB->grade) {
            return studentB->age - studentA->age;
        }
        return studentB->grade - studentA->grade;
    }
    // 성적이 다르면 성적이 높은 순으로 정렬
    return studentB->id - studentA->id;
}

int main() {
    int n;
    scanf("%d", &n);
 
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
 
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", students[i].name, &students[i].age, &students[i].grade, &students[i].id);
    }

    // 정렬
    qsort(students, n, sizeof(struct Student), compare);

    // 가장 나이가 많은 사람과 가장 어린 사람 출력
    printf("%s\n", students[0].name);
    printf("%s\n", students[n - 1].name);
 
    free(students);

    return 0;
}
