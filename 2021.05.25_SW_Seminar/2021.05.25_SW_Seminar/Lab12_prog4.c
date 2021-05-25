#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct login_info {
	char id[20];
	char password[20];
} LOGIN_INFO;

int main(int argc, char* argv[]) {

	if (argc < 2) {
		return -1;
	}

	FILE* fp;
	int userCount = 0;
	int count = 0;

	LOGIN_INFO* loginInfo = NULL;
	loginInfo = (LOGIN_INFO*)malloc(sizeof(LOGIN_INFO) * userCount);
	if (loginInfo == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
	}
	else {
		memset(loginInfo, 0, sizeof(LOGIN_INFO) * userCount);
	}

	printf("��ü ����� ���� �Է��ϼ���: ");

	fp = fopen("password.dat", "wb");
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return -1;
	}
	scanf("%d", &userCount);
	getchar();
	fprintf(fp, "%d\n", userCount);

	for (int i = 0; i < userCount; i++) {
		printf("id�� �Է��ϼ���: ");
		scanf("%s", loginInfo[i].id);
		printf("pw�� �Է��ϼ���: ");
		scanf("%s", loginInfo[i].password);
		fprintf(fp, "%s %s\n", loginInfo[i].id, loginInfo[i].password);
		fwrite(loginInfo, sizeof(LOGIN_INFO)*userCount, userCount, fp);
	}

	fclose(fp);
	return 0;
}