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
		printf("파일 열기 실패\n");
		return -1;
	}
	int userCount;
	fscanf(fp, "%d", &userCount);
	printf("%d\n", userCount);

	LOGIN_INFO* loginInfo = NULL;
	loginInfo = (LOGIN_INFO*)malloc(sizeof(LOGIN_INFO) * userCount);
	if (loginInfo == NULL) {
		printf("동적 메모리 할당 실패\n");
	}
	else {
		printf("%d만큼 동적할당 성공\n", userCount);
		memset(loginInfo, 0, sizeof(LOGIN_INFO) * userCount);
	}

	for (int i = 0; i < userCount; i++) {
		fscanf(fp, "%s %s", loginInfo[i].id, loginInfo[i].password);
	}
	LOGIN_INFO Key;
	while (1) {
		
		qsort(loginInfo, userCount, sizeof(LOGIN_INFO), compareById);
		printf("ID를 입력하세요:");
		gets(Key.id);
		
		LOGIN_INFO* idP = (int*)bsearch(&Key, loginInfo, userCount, sizeof(LOGIN_INFO), compareById);
		if (idP != NULL) {
			printf("비밀번호를 입력하세요:");
			gets(Key.password);
			qsort(loginInfo, userCount, sizeof(LOGIN_INFO), compareByPw);
			LOGIN_INFO* pwP = (int*)bsearch(&Key, loginInfo, userCount, sizeof(LOGIN_INFO), compareByPw);
			if (pwP != NULL) {
				printf("로그인 성공\n");
				break;
			}
			printf("잘못된 PW입니다.\n");

		}
		else {
			printf("잘못된 ID입니다.\n");
		}
	}
	fclose(fp);
	return 0;
}