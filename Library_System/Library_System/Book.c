#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "Menu.h"

BOOK* allocateBooks(int* nb) {
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * (*nb));
	if (result == NULL) {
		printf("疑旋 五乞軒 拝雁 叔鳶\n");
	}
	else {
		memset(result, 0, sizeof(BOOK) * (*nb));
	}
	return result;
}

BOOK* reallocateBooks(BOOK* books, int* nb) {

	BOOK* backUp = books;
	books = (BOOK*)realloc(books, sizeof(BOOK) * ((*nb) + 5));
	if (books == NULL) {
		printf("五乞軒 仙拝雁拭 叔鳶梅柔艦陥. 据掘 雌殿稽 差姥杯艦陥\n");
		books = backUp;
	}
	else {
		printf("五乞軒 仙拝雁 失因\n");
	}
	return books;
}

int freeMemory(BOOK* books) {
	free(books);
	books = NULL;
	return 0;
}

void addBook(BOOK* book, int* pc) {
	char title[40] = { NULL };
	char author[30] = { NULL };
	int price = 0;


	printf("===========歯稽錘 亀辞研 蓄亜杯艦陥===========\n");
	printf("薦鯉聖 脊径馬室推: ");
	gets(title);
	strcpy(book[*pc].name, title);
	printf("煽切研 脊径馬室推: ");
	gets(author);
	strcpy(book[*pc].author, author);
	printf("亜維聖 脊径馬室推: ");
	scanf("%d", &book[*pc].price);
	getchar();
	(*pc)++;
}

void showBook(const BOOK* books, int* pc) {
	printf("===========穿端 奪 鯉系===========\n");
	for (int i = 0; i < *pc; i++) {
		printf("%d腰\n", i+1);
		printf("薦鯉: %s\n", books[i].name);
		printf("煽切: %s\n", books[i].author);
		printf("亜維: %d据\n", books[i].price);
		printf("\n");
	}
	printf("==================================\n");
}

void findBookByAuthor(BOOK* books, int *pc, int *nb) {
	int modifySelect = -1;
	printf("伊事馬壱切 馬澗 煽切研 脊径馬室推: ");
	BOOK authorKey;
	gets(authorKey.author);
	BOOK* authorP = (int*)bsearch(&authorKey, books, *nb, sizeof(BOOK), compareByAuthor);
	if (authorP != NULL) {
		printBookInfo(authorP);
		printf("背雁 切戟研 呪舛 箸精 肢薦馬獣畏柔艦猿?\n");
		printf("1. 呪舛     2. 肢薦     3. 蟹亜奄");
		scanf("%d", &modifySelect);
		getchar();
		switch (modifySelect)
		{
		case 1:
			printf("===奪 舛左研 呪舛杯艦陥.===\n");
			printf("薦鯉聖 脊径馬室推: ");
			gets(authorP->name);
			printf("煽切研 脊径馬室推: ");
			gets(authorP->author);
			printf("亜維聖 脊径馬室推: ");
			scanf("%d", &authorP->price);
			getchar();
			break;
		case 2:
			printf("===奪 舛左研 肢薦杯艦陥.===\n");
		//	memset(authorP, NULL, sizeof(BOOK));
		//	(*nb)--;
		//	(*pc)--;
			break;
		case 3: 
			printf("五敢稽 宜焼逢艦陥.\n");
			break;
		default:
			printf("設公吉 脊径脊艦陥. 五敢稽 宜焼逢艦陥.\n");
			break;
		}

	}
	else {
		printf("背雁 切戟澗 蒸柔艦陥.\n");
	}
}

void findBookByTitle(BOOK* books, int* pc, int* nb) {
	int modifySelect = -1;
	printf("伊事馬壱切 馬澗 薦鯉聖 脊径馬室推: ");
	BOOK titleKey;
	gets(titleKey.name);
	BOOK* titleP = (int*)bsearch(&titleKey, books, *nb, sizeof(BOOK), compareByName);
	if (titleP != NULL) {
		printBookInfo(titleP);
		printf("背雁 切戟研 呪舛馬獣畏柔艦猿?\n");
		printf("1. 呪舛     2. 肢薦     3. 蟹亜奄");
		scanf("%d", &modifySelect);
		getchar();
		switch (modifySelect)
		{
		case 1:
			printf("===奪 舛左研 呪舛杯艦陥.===\n");
			printf("薦鯉聖 脊径馬室推: ");
			gets(titleP->name);
			printf("煽切研 脊径馬室推: ");
			gets(titleP->author);
			printf("亜維聖 脊径馬室推: ");
			scanf("%d", &titleP->price);
			getchar();
			break;
		case 2:
			// 壕伸税 昔畿什研 亜閃人辞 i拭 煽舌
			// i戚板税 壕伸拭辞 memcpy(i, i+1)
			printf("===奪 舛左研 肢薦杯艦陥.===\n");
			//memset(titleP, NULL, sizeof(BOOK));
			//(*nb)--;
			//(*pc)--;
			//int i, j = 0; //しし
			//i = titleP - books; //しし 肢薦馬壱切 馬澗 昔畿什
			//printf("%d", i); //しし
			//for (int j = i; j < (*pc) -1; j++) { //しし
			//	strcpy(books[i].name, books[i + 1].name);
			//	strcpy(books[i].author, books[i + 1].author);
			//	books[i].price = books[i + 1].price;
			//	memcpy(&books[i],&books[i+1], sizeof(BOOK)); //しし

		//	for (int i = titleP - books; i < sizeof(books) / sizeof(BOOK) -2; i++) {
		//		//memcpy(&books[i], &books[i + 1], sizeof(BOOK));
		//			strcpy(books[i].name, books[i + 1].name);
		//		strcpy(books[i].author, books[i + 1].author);
		//		books[i].price = books[i + 1].price;
		//	}

			for (int i = 0; i < sizeof(books) / sizeof(BOOK); i++) {
				if (strcmp(titleP->name, books[i].name) == 0) {
					(*pc)--;
					printf("肢薦刃戟");

					if (i!= sizeof(books) / sizeof(BOOK) - 1) {
						for (int j = i; j < sizeof(books) / sizeof(BOOK); j++) {
							strcpy(books[i].name, books[i + 1].name);
							strcpy(books[i].author, books[i + 1].author);
							books[i].price = books[i + 1].price;
						}
						*books[sizeof(books) / sizeof(BOOK) - 1].name = NULL;
						*books[sizeof(books) / sizeof(BOOK) - 1].author = NULL;
					}
				}
			}
			(*pc)--;
			break;
		case 3:
			printf("五敢稽 宜焼逢艦陥.\n");
			break;
		default:
			printf("設公吉 脊径脊艦陥. 五敢稽 宜焼逢艦陥.\n");
			break;
		}
	}
	else {
		printf("背雁 切戟澗 蒸柔艦陥.");
	}
}

void printBookInfo(const BOOK* p) {
	printf("==================================\n");
	printf("薦鯉: %s\n", p->name);
	printf("煽切: %s\n", p->author);
	printf("亜維: %d据\n", p->price);
	printf("==================================\n");
	printf("\n");
}