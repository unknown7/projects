#include <stdio.h>

typedef struct {
	char *ch;
	int length;
} String;

void init(String *s, char *ch) {
	int i = 1;
	while (*ch != '\0') {
		s->ch[i] = *ch++;
		i++;
	}
	s->length = i - 1;
}

void get_next(String s, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < s.length) {
		if (j == 0 || s.ch[i] == s.ch[j]) {
			i++; j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int main() {
	char *ch = "abaabcaba";
	String s;
	init(&s, ch);

	int next[9];
	get_next(s, next);
	int i;
	for (i = 1; i <= 9; i++)
		printf("%d ", next[i]);
	printf("\n");
	return 0;
}












