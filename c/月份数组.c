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
	printf("�������·ݣ�");
	scanf("%d", &month);
	printf("��������ǣ�%d����Ӧ���·�Ϊ��%s\n", month, months[month]);
	return 0;
}

