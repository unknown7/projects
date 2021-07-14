#include <stdio.h>
int main() {
	double sum;
	int count = 0;
	int number;
	printf("请输入：");
	scanf("%d", &number);
	while (number != -1) {
		sum += number;
		count++;
		printf("请输入：");
		scanf("%d", &number);
	}
	printf("共输入了%d个数，平均数为：%lf", count, sum / count);
	return 0;
}
