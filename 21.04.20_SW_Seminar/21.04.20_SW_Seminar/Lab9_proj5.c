#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct contact {
	char name[32];
	char phone[32];
} CONTACT;

CONTACT* allocateContacts(int count);
void inputContacts(CONTACT* contacts, int count);
void printContacts(const CONTACT* contacts, int count);

int main() {

	CONTACT* contacts = NULL;
	int cnt = 0;

	printf("������ ����ó�� ���� : ");
	scanf("%d", &cnt);
	while (getchar() != '\n');

	contacts = allocateContacts(cnt);
	if (contacts == NULL) {
		return -1;
	}

	inputContacts(contacts, cnt);
	printContacts(contacts, cnt);

	free(contacts);
	contacts = NULL;

	return 0;
}
CONTACT* allocateContacts(int count) {

	CONTACT* result = NULL;
	result = (CONTACT*)malloc(sizeof(CONTACT) * count);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(CONTACT) * count);
	return result;
}
void inputContacts(CONTACT* contacts, int count) {
	int i;
	for (i = 0; i < count; i++) {
		printf("��   �� : ");
		gets(contacts[i].name);
		printf("��ȭ��ȣ : ");
		gets(contacts[i].phone);
	}
}
void printContacts(const CONTACT* contacts, int count) {
	int i;

	printf(" --- ��ü ����ó ��� ---\n");
	for (i = 0; i < count; i++) {
		printf("%-16s\n", contacts[i].name, contacts[i].phone);
	}
}
