#include <stdio.h>
#include <string.h>

void Encrypt(char);
int main(void) {

	char str[20];
	char* p = str;

	gets(str);
	for (int i = 0; i < strlen(str); i++) {
	Encrypt(*(p+i));
	}

	return 0;
}
	void Encrypt(char c) {
		if (c >= 'A' && c <= 'Z') {
			if (c >= 'A' && c < 'Z') {
				c = c + 1;
				printf("%c", c);
			}
			else if (c == 'z') {
				c = c - 25;
				printf("%c", c);
			}
		} else if (c >= 'a' && c <= 'z') {
			if (c >= 'a' && c < 'z') {
				c = c + 1;
				printf("%c", c);
			}
			else if (c == 'Z') {
				c = c - 25;
				printf("%c", c);
			}
		}
	}