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

    printf("������ ����� ���� �Է��Ͻÿ�: ");
    scanf("%d", &n);

    p = malloc(sizeof(struct Person) * n);

    for (i = 0; i < n; i++)
    {
        printf("�̸��� ���̸� ������� �Է��Ͻÿ�: ");
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

    printf(" ���̰� ���� ���� ����� %s �Դϴ�.\n", p[oldestIndex].name);

    free(p);
    p = NULL;

    return 0;
}