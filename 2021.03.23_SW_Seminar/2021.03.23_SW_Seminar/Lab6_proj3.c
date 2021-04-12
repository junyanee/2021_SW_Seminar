#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 64

void MakeLower(char);
void MakeUpper(char);

int main(void) {

    char str[10];
    char* p = str;

    while (1) {
        printf("문자열을 입력하세요: ");

        gets(str);

        for (int i = 0; i < strlen(str); i++) {
            MakeLower(*(p + i));
            MakeUpper(*(p + i));
        }

        printf("\n");

        if (*p == NULL) break;
    }

    return 0;
}

void MakeLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
        printf("%c", c);
    }
}

void MakeUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 32;
        printf("%c", c);
    }
}