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
		printf("동적 메모리 할당 실패\n");
	}
	else {
		memset(loginInfo, 0, sizeof(LOGIN_INFO) * userCount);
	}

	printf("전체 사용자 수를 입력하세요: ");

	fp = fopen("password.dat", "wb");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	scanf("%d", &userCount);
	getchar();
	fprintf(fp, "%d\n", userCount);

	for (int i = 0; i < userCount; i++) {
		printf("id를 입력하세요: ");
		scanf("%s", loginInfo[i].id);
		printf("pw를 입력하세요: ");
		scanf("%s", loginInfo[i].password);
		fprintf(fp, "%s %s\n", loginInfo[i].id, loginInfo[i].password);
		fwrite(loginInfo, sizeof(LOGIN_INFO)*userCount, userCount, fp);
	}

	fclose(fp);
	return 0;
}