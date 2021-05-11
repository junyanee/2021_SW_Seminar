#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
	char name[20];
	char phoneNum[20];
} CONTACT;

int main(void) {
	char findName[20] = "";
	char saveSelect;
	int cnt = 0;

	CONTACT* con[100] = { NULL };

	while (1) {
		printf("검색할 이름: \n");
		gets(findName);

		if (strcmp(findName, ".") == 0) {
			break;
		}
		int found = -1;
		for (int i = 0; i < cnt; i++) {
			if (strcmp(findName, con[i]->name) == 0) {
				found = i;
				break;
			}
		}
		if (found == -1) {
			if (cnt < 100) {
				printf("저장되지 않은 연락처입니다. 저장하시겠습니까? (Y/N) : ");
				scanf("%c", &saveSelect);
				while (getchar() != '\n');

				if (saveSelect == 'Y' || saveSelect == 'y') {
					con[cnt] = (CONTACT*)malloc(sizeof(CONTACT));
					memset(con[cnt], 0, sizeof(CONTACT));
					strcpy(con[cnt]->name, findName);
					printf("전화번호 입력 : ");
					gets(con[cnt]->phoneNum);
					cnt++;
				}
				else {
					continue;
				}
			}
			else {
				printf("더 이상 연락처를 저장할 수 없습니다.\n");
			}
		}
		else {
			printf("찾은 전화번호 : ");
			puts(con[found]->phoneNum);
		}
		printf("\n");

	}
	for (int i = 0; i < cnt; i++) {
		free(con[i]);
		con[i] = NULL;
	}

	return 0;
}