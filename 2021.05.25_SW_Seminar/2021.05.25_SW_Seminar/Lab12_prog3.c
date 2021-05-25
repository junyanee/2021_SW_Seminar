#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct login_info {
	char id[20];
	char password[20];
} LOGIN_INFO;

int compareById(const void* login1, const void* login2) {
	const LOGIN_INFO* l1 = (const LOGIN_INFO*)login1;
	const LOGIN_INFO* l2 = (const LOGIN_INFO*)login2;
	return strcmp(l1->id, l2->id);
}

int compareByPw(const void* login1, const void* login2) {
	const LOGIN_INFO* l1 = (const LOGIN_INFO*)login1;
	const LOGIN_INFO* l2 = (const LOGIN_INFO*)login2;
	return strcmp(l1->password, l2->password);
}

int main(int argc, char* argv[]) {

	if (argc < 2) {
		return -1;
	}

	FILE* fp;
	fp = fopen("password.txt", "r");
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return -1;
	}
	int userCount;
	fscanf(fp, "%d", &userCount);
	printf("%d\n", userCount);

	LOGIN_INFO* loginInfo = NULL;
	loginInfo = (LOGIN_INFO*)malloc(sizeof(LOGIN_INFO) * userCount);
	if (loginInfo == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
	}
	else {
		printf("%d��ŭ �����Ҵ� ����\n", userCount);
		memset(loginInfo, 0, sizeof(LOGIN_INFO) * userCount);
	}

	for (int i = 0; i < userCount; i++) {
		fscanf(fp, "%s %s", loginInfo[i].id, loginInfo[i].password);
	}
	LOGIN_INFO Key;
	while (1) {
		
		qsort(loginInfo, userCount, sizeof(LOGIN_INFO), compareById);
		printf("ID�� �Է��ϼ���:");
		gets(Key.id);
		
		LOGIN_INFO* idP = (int*)bsearch(&Key, loginInfo, userCount, sizeof(LOGIN_INFO), compareById);
		if (idP != NULL) {
			printf("��й�ȣ�� �Է��ϼ���:");
			gets(Key.password);
			qsort(loginInfo, userCount, sizeof(LOGIN_INFO), compareByPw);
			LOGIN_INFO* pwP = (int*)bsearch(&Key, loginInfo, userCount, sizeof(LOGIN_INFO), compareByPw);
			if (pwP != NULL) {
				printf("�α��� ����\n");
				break;
			}
			printf("�߸��� PW�Դϴ�.\n");

		}
		else {
			printf("�߸��� ID�Դϴ�.\n");
		}
	}
	fclose(fp);
	return 0;
}