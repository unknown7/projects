#include <stdio.h>
#include <math.h>
struct date {
	int month;
	int day;
	int year;
};

int main() {
	struct date today = {
		03, 02, 2019
	};
	today = (struct date){03, 03, 2019};
	struct date tomorrow = today;
	tomorrow.day = 04;
	printf("Today's date is %i-%i-%i\n", today.year, today.month, today.day);
	printf("Tomorrow's date is %i-%i-%i\n", tomorrow.year, tomorrow.month, tomorrow.day);
	printf("today=%p\n", &today);
	printf("tomorrow=%p\n", &tomorrow);
	return 0;
}

