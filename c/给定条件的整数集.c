/**
	����������6��������A�����Ǵ�A��ʼ������4�����֣����������������ɵ����ظ����ֵ�3λ��
*/

#include <stdio.h>
int main() {
	int A = 2;
	int a, b, c;
	int cnt = 0;
	a = A;
	while ( a <= A + 3 ) {
		b = A;
		while ( b <= A + 3 ) {
			c = A;
			while ( c <= A + 3 ) {
				if ( c != a && c != b && a != b ) {
					cnt ++;
					printf( "%d%d%d", a, b, c );
					if ( cnt % 6 == 0 ) {
						printf("\n");
					} else {
						printf("\t");
					}
				}
				c ++;
			}
			b ++;
		}
		a ++;
	}
	return 0;
}

