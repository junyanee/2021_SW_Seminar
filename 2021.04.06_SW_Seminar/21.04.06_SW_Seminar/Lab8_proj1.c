#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

struct date {
	int year;
	int month;
	int day;
} myTime;

time_t time(time_t* timer);
struct tm* localtime(const time_t* timer);

int main(void) {

	time_t timeNow;
	struct tm* p_time;
	time(&timeNow);
	p_time = localtime(&timeNow);

	struct date myTime = {p_time->tm_year + 1900, p_time->tm_mon + 1, p_time->tm_mday};

	printf("오늘의 날짜는 %d년 %d월 %d일 입니다. \n", myTime.year, myTime.month, myTime.day);

	return 0;
}