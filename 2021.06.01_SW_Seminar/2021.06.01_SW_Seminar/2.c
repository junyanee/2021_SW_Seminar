#include <stdio.h>
#include <stdlib.h>

typedef struct person {
	char name[20];
	int age;
} Person;

int main(void) {

	int number = 0;
	int oldest = 0;
	int index = 0;
	Person* p = NULL;

	printf("저장할 사람의 수를 입력하시오");
	scanf("%d", &number);

	p = malloc(sizeof(Person) * number);

	for (int i = 0; i < number; i++) {
		printf("이름과 나이를 순서대로 입력하시오:");
		scanf("%s %d", &p[i].name, &p[i].age);
	}
	for (int i = 0; i < number; i++) {
		if (oldest < p[i].age) {
			oldest = p[i].age;
			index = i;
		}
	}
	printf("나이가 가장 많은 사람은 %s 입니다.", p[index].name);
	
	return 0;
}