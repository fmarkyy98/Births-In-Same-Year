#include <iostream>

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

bool within1Year(Date date1, Date date2)
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

BirthsOnDate dates[MAX_N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> dates[i].date.year >> dates[i].date.month >> dates[i].date.day;
	}



	std::cout << "Hello World!\n";

	return 0;
}
