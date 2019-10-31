#include <iostream>
#include <algorithm>    // std::sort

using namespace std;

const int MAX_N = 1000000; // 1 million

struct Date
{
	int year;
	int month;
	int day;
};

struct BirthsOnDate
{
	Date date;
	int bithsCount;
};

bool withinOneYear(Date date1, Date date2)
{
	bool result = false;
	if (date1.year == date2.year)
	{
		if (date1.month == date2.month)
		{
			if (date1.day <= date2.day)
			{
				result = true;
			}
		}
		else if (date1.month <= date2.month)
		{
			result = true;
		}
	}
	else if (date1.year + 1 == date2.year)
	{
		if (date1.month == date2.month)
		{
			if (date1.day > date2.day)
			{
				result = true;
			}
		}
		else if (date1.month >= date2.month)
		{
			result = true;
		}
	}
	return result;
}
/// <summary>
/// Treu if date1 is earlyer in time than date2.
/// </summary>
/// <param name="date1">Represents the first date.</param>
/// <param name="date2">Represents the second date.</param>
bool compareTwoBirthsOnDate(BirthsOnDate date1, BirthsOnDate date2)
{
	bool result;
	if (date1.date.year != date2.date.year)
	{
		result = date1.date.year < date2.date.year;
	}
	else if (date1.date.month != date2.date.month)
	{
		result = date1.date.month < date2.date.month;
	}
	else
	{
		result = date1.date.day < date2.date.day;
	}
	return result;
}

BirthsOnDate dates[MAX_N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> dates[i].date.year >> dates[i].date.month >> dates[i].date.day;
	}

	sort(dates, dates + n, compareTwoBirthsOnDate); // arrays inplicitly converts to the pointer, pointing the first element of the array, dates + n represents the pointer pointing after the last elements place in memory.
	for (int i = 0; i < n; ++i)
	{
		int j = i;
		while (j < n && withinOneYear(dates[i].date, dates[j].date))
		{
			++dates[i].bithsCount;
			++j;
		}
	}
	BirthsOnDate max = dates[0];
	for (int i = 1; i < n; ++i)
	{
		if (dates[i].bithsCount > max.bithsCount)
		{
			max = dates[i];
		}
	}

	std::cout << max.date.year << " " << max.date.month << " " << max.date.day << endl;

	return 0;
}