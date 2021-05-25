#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* fp1, * fp2;
	if (argc < 3) {
		return -1;
	}
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}

	fp2 = fopen(argv[2], "r");
	if (fp2 == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}

	while (1) {
		int c1 = fgetc(fp1);
		int c2 = fgetc(fp2);
		if (c1 == EOF || c2 == EOF) {
			break;
		}
		else if (c1 != c2) {
			printf("두 파일은 서로 다릅니다.\n");
			return 0;
			}
	}
	printf("두 파일은 같습니다.\n");
	fclose(fp1);
	fclose(fp2);

	return 0;
}