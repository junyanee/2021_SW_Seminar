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
		printf("�˻��� �̸�: \n");
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
				printf("������� ���� ����ó�Դϴ�. �����Ͻðڽ��ϱ�? (Y/N) : ");
				scanf("%c", &saveSelect);
				while (getchar() != '\n');

				if (saveSelect == 'Y' || saveSelect == 'y') {
					con[cnt] = (CONTACT*)malloc(sizeof(CONTACT));
					memset(con[cnt], 0, sizeof(CONTACT));
					strcpy(con[cnt]->name, findName);
					printf("��ȭ��ȣ �Է� : ");
					gets(con[cnt]->phoneNum);
					cnt++;
				}
				else {
					continue;
				}
			}
			else {
				printf("�� �̻� ����ó�� ������ �� �����ϴ�.\n");
			}
		}
		else {
			printf("ã�� ��ȭ��ȣ : ");
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