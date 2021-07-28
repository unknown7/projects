#include <stdio.h>
#include <stdlib.h>

typedef struct SString {
	char *ch;
	int length;
} *String;

String new_string(char *ch) {
	String s = (String) malloc(sizeof(struct SString));
	s->ch = (char*) malloc(sizeof(char) * 255);
	int i = 0;
	s->ch[i++] = ' ';
	while (*ch != '\0')
		s->ch[i++] = *ch++;
	s->length = i - 1;
	return s;
}

void get_next(String s, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < s->length) {
		if (j == 0 || s->ch[i] == s->ch[j]) {
			i++; j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int index_of(String s, String t, int next[]) {
	int i = 1, j = 1;
	while (i <= s->length && j <= t->length) {
		if (j == 0 || s->ch[i] == t->ch[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}

	if (j > t->length)
		return i - t->length;
	return -1;
}

int main() {
	char input1[255], input2[255];
	printf("input s:");
	scanf("%s", input1);
	String s = new_string(input1);

	printf("input pattern:");
	scanf("%s", input2);
	String pattern = new_string(input2);

	int next[pattern->length];
	get_next(pattern, next);

	int i;
	for (i = 1; i <= pattern->length; i++)
		printf("%d ", next[i]);
	printf("\n");

	int idx = index_of(s, pattern, next);
	printf("index of %s in %s is : %d\n", pattern->ch, s->ch, idx);

	return 0;
}












