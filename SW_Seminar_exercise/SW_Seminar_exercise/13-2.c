#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
};

int main()
{
    struct Person* p = NULL;
    int i, n;
    int oldestIndex = 0;
    int age = 0;

    printf("저장할 사람의 수를 입력하시오: ");
    scanf("%d", &n);

    p = malloc(sizeof(struct Person) * n);

    for (i = 0; i < n; i++)
    {
        printf("이름과 나이를 순서대로 입력하시오: ");
        scanf("%s %d", &p[i].name, &p[i].age);
    }

    for (i = 0; i < n; i++)
    {
        if (age < p[i].age)
        {
            age = p[i].age;
            oldestIndex = i;
        }
    }

    printf(" 나이가 가장 많은 사람은 %s 입니다.\n", p[oldestIndex].name);

    free(p);
    p = NULL;

    return 0;
}