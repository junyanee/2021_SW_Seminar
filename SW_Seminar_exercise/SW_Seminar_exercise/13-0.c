#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[20];
    int age;
};

struct Person* allocPerson()
{
    struct Person* p = malloc(sizeof(struct Person));

    strcpy(p->name, "Kayle");
    p->age = 22;

    return p;
}

int main()
{
    struct Person* p1;

    p1 = allocPerson();

    printf("%s\n", p1->name);
    printf("%d\n", p1->age);

    free(p1);

    return 0;
}
