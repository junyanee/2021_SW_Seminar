#include <stdio.h>


typedef struct mobilePhone {
	int nationNum;
	unsigned long long phoneNum;
} Phone;

typedef struct personInfo {
	char name[20];
	int age;
	Phone phone;
} Person;

struct a {
	int a;
	int b;
	struct k {
		int p;
		int q;
	};
};

int main(void) {

	Person a = {"±è±è±è", 20, 82, 1012341230};
	printf("%s, %d, %d, %llu\n", a.name, a.age, a.phone.nationNum, a.phone.phoneNum);

	Person b;
	b.age = 25;
	strcpy(b.name, "¹Ú¹Ú¹Ú");
	b.phone.nationNum = 82;
	b.phone.phoneNum = 1055449966;
	printf("%s, %d, %d, %llu\n", b.name, b.age, b.phone.nationNum, b.phone.phoneNum);

	
	return 0;
}