/*
练习7-4 找出不是两个数组共有的元素 （20 分）
给定两个整型数组，本题要求找出不是两者共有的元素。

输入格式:
输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。

输出格式:
在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。

输入样例:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1
输出样例:
3 5 -15 6 4 1
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int contains(int arr[], int length, int number);
int main() {
	// 初始化第一个数组 
	int num1;
	scanf("%d", &num1);
	int nums1[num1];
	int *p1 = nums1;
	int idx = 0;
	while (idx++ < num1) {
		scanf("%d", p1++);
	}
	// 初始化第二个数组
	int num2;
	scanf("%d", &num2);
	int nums2[num2];
	int l;
	for (l = 0; l < num2; l++) {
		scanf("%d", &nums2[l]);
	}
	
	int ret[40];
	int retc = 0;
	int length = sizeof(nums2) / sizeof(nums2[0]);
	int i;
	for (i = 0; i < num1; i++) {
		if (!contains(nums2, length, nums1[i]) && !contains(ret, retc, nums1[i])) {
			ret[retc++] = nums1[i];
		}
	}
	length = sizeof(nums1) / sizeof(nums1[0]);
	int j;
	for (j = 0; j < num2; j++) {
		if (!contains(nums1, length, nums2[j]) && !contains(ret, retc, nums2[j])) {
			ret[retc++] = nums2[j];
		}
	}
	
	int k;
	for (k = 0; k < retc; k++) {
		printf("%d", ret[k]);
		if (k < retc - 1) {
			printf(" ");
		}
	}
	
	return 0;
}
int contains(int arr[], int length, int number) {
	int ret = 0;
	int i;
	for (i = 0; i < length; i++) {
		if (arr[i] == number) {
			ret = 1;
			break;
		}
	}
	return ret;
}
