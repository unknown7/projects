#include <stdio.h>

static int tab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31}
};

int get_day_of_year(int year, int month, int day);
void set_date_by_day(int year, int day_of_year, int* month, int* day);

int main()
{
	int year = 2021;
	int day_of_year = get_day_of_year(year, 7, 8);
	printf("day_of_year:%d\n", day_of_year);
	int month, day;
	set_date_by_day(year, day_of_year, &month, &day);
	printf("%d-%d-%d\n", year, month, day);
	return 0;
}

int get_day_of_year(int year, int month, int day)
{
	int result = 0;
	int leap = (year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0;
	for (int i = 1; i < month; ++i)
	{
		result += tab[leap][i];
	}
	result += day;
	return result;
}
void set_date_by_day(int year, int day_of_year, int* month, int* day)
{
	int leap = (year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0;

	int i = 1;
	while ((day_of_year - tab[leap][i]) > 0)
	{
		day_of_year -= tab[leap][i];
		i++;
	}
	*month = i;
	*day = day_of_year;
}