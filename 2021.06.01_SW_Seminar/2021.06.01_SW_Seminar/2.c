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

	printf("������ ����� ���� �Է��Ͻÿ�");
	scanf("%d", &number);

	p = malloc(sizeof(Person) * number);

	for (int i = 0; i < number; i++) {
		printf("�̸��� ���̸� ������� �Է��Ͻÿ�:");
		scanf("%s %d", &p[i].name, &p[i].age);
	}
	for (int i = 0; i < number; i++) {
		if (oldest < p[i].age) {
			oldest = p[i].age;
			index = i;
		}
	}
	printf("���̰� ���� ���� ����� %s �Դϴ�.", p[index].name);
	
	return 0;
}