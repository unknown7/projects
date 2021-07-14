/*
习题7-2 求一批整数中出现最多的个位数字 （20 分）
给定一批整数，分析每个整数的每一位数字，求出现次数最多的个位数字。例如给定3个整数1234、2345、3456，其中出现最多次数的数字是3和4，均出现了3次。

输入格式：
输入在第1行中给出正整数N（≤1000），在第二行中给出N个不超过整型范围的非负整数，数字间以空格分隔。

输出格式：
在一行中按格式“M: n1 n2 ...”输出，其中M是最大次数，n1、n2、……为出现次数最多的个位数字，按从小到大的顺序排列。数字间以空格分隔，但末尾不得有多余空格。

输入样例：
3
1234 2345 3456
输出样例：
3: 3 4
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int result[10] = {0};
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (j = 0; j < n; j++) {
		int x = arr[j];
		int t1 = x;
		int t2 = x;
		int cnt = 0;
		int divisor = 1;
		while (t1 > 9) {
			cnt++;
			divisor *= 10;
			t1 /= 10;
		}
		while (t2 > 0) {
			result[t2/divisor]++;
			t2 %= divisor;
			if (t2 == 0) {
				result[0] += cnt;
			}
			divisor /= 10;
			cnt--;
		}
	}
	int max = 0;
	for (i = 0; i < 10; i++) {
		if (max < result[i]) {
			max = result[i];
		}
	}
	int numbers[10];
	int idx = 0;
	for (i = 0; i < 10; i++) {
		if (max == result[i]) {
			numbers[idx++] = i;
		}
	}
	
	printf("%d: ", max);
	for (i = 0; i < idx; i++) {
		printf("%d", numbers[i]);
		if (i < idx - 1) {
			printf(" ");
		}
	}
	return 0;
}

