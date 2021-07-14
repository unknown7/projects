#include <stdio.h>
#include <math.h>
int main() {
	const char *months[] = {
		"",
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};
	int month = 0;
	printf("请输入月份：");
	scanf("%d", &month);
	printf("您输入的是：%d，对应的月份为：%s\n", month, months[month]);
	return 0;
}

