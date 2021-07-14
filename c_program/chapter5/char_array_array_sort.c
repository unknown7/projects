#include <stdio.h>

int get_line(char*);
char* alloc(int);
void str_cpy(char* , char* );
int str_cmp(char*, char* );
void q_sort(char*[], int, int);
void swap(char*[], int, int);

int main()
{
	char* coll[10000];
	char line[100];
	int i, j, l;
	i = 0;
	while ((l = get_line(line)) > 0)
	{
		char *item = alloc(l);
		str_cpy(line, item);
		coll[i++] = item;
	}

	q_sort(coll, 0, i - 1);

	printf("[");
	for (j = 0; j < i; j++)
	{
		char suffix = (j + 1 < i) ? ',' : '\0';
		printf("%s%c", coll[j], suffix);
	}
	printf("]");
	
	return 0;
}

int get_line(char* p)
{
	int c, l;

	l = 0;
	while ((c = getchar()) != EOF)
	{
		l++;
		if (c != '\n')
			*p++ = c;
		else {
			*p = '\0';
			break;
		}
	}

	return l;
}

#define SIZE 65536
static char buff[SIZE];
static char* buff_pn = buff;
char* alloc(int n)
{
	char* result;
	if (buff_pn + n < buff + SIZE)
	{
		result = buff_pn;
		buff_pn += n;
	}
	else
	{
		result = 0;
	}

	return result;
}

void str_cpy(char* from, char* to)
{
	while ((*to++ = *from++) != '\0')
		;
}

int str_cmp(char* a, char* b)
{
	for (; *a == *b; a++, b++)
		if (*a == '\0')
			return 0;
	return *a - *b;
}

void q_sort(char* p[], int begin, int end)
{

	if (begin >= end)
		return;

	int i, j, base;

	i = begin + 1, j = end, base = begin;

	while (i < j)
	{

		while (i < end && str_cmp(p[i], p[base]) < 0)
			i++;

		while (j > begin && str_cmp(p[j], p[base]) > 0)
			j--;

		if (i < j)
			swap(p, i, j);

	}
	swap(p, base, j);

	q_sort(p, begin, j - 1);
	q_sort(p, j + 1, end);
}

void swap(char* p[], int i, int j)
{
	char* t = p[i];
	p[i] = p[j];
	p[j] = t;
}

















