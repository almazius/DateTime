#include <iostream>

using namespace std;

class DateTime
{
public:
#pragma region Constr
	/// <summary>
	/// Конструктор оп умолчанию
	/// </summary>
	DateTime()
	{
		_day = 0;
		_mont = 0;
		_year = 0;
		_hours = 0;
		_min = 0;
		_sec = 0;
	};
	/// <summary>
	/// Полный коснструктор
	/// </summary>
	/// <param name="day">День</param>
	/// <param name="mont">Месяц</param>
	/// <param name="year">Год</param>
	/// <param name="hours">Час</param>
	/// <param name="min">Минута</param>
	/// <param name="sec">Секунда</param>
	DateTime(int day, int mont, int year, int hours, int min, int sec)
	{
		if (correctly(day, mont, year, hours, min, sec))
		{
			_day = day;
			_mont = mont;
			_year = year;
			_hours = hours;
			_min = min;
			_sec = sec;
		}
		else
		{
			cout << "Date uncorrectly!";
		}
	};
#pragma endregion
#pragma region Metods
	bool correctly()
	{
		if (_day > 31 || _day < 1 || _mont>12 || _mont < 1 || _year < 0)
		{
			return false;
		}
		if ((_mont == 2 && _year % 4 == 0) && _day > 29)
		{
			return false;
		}
		else if (_mont == 2 && _day > 28)
		{
			return false;
		}
		if ((_mont == 4 || _mont == 6 || _mont == 9 || _mont == 11) && _day > 30)
		{
			return false;
		}
		if (_hours > 23 || _hours < 0)
		{
			return false;
		}
		if (_min > 59 || _min < 0)
		{
			return false;
		}
		if (_sec > 59 || _sec < 0)
		{
			return 0;
		}
		return true;
	}

	bool correctly(int day, int mont, int year, int hours, int min, int sec)
	{
		if (day > 31 || day < 1 || mont>12 || mont < 1 || year < 0)
		{
			return false;
		}
		if ((mont == 2 && year % 4 == 0) && day > 29)
		{
			return false;
		}
		else if (mont == 2 && day > 28)
		{
			return false;
		}
		if ((mont == 4 || mont == 6 || mont == 9 || mont == 11) && day > 30)
		{
			return false;
		}
		if (hours > 23 || hours < 0)
		{
			return false;
		}
		if (min > 59 || min < 0)
		{
			return false;
		}
		if (sec > 59 || sec < 0)
		{
			return 0;
		}
		return true;
	}
	
	/// <summary>
	/// sum date with new date
	/// </summary>
	/// <param name="firstValue">new date</param>
	void sum(DateTime firstValue)
	{
		if ((firstValue._sec + _sec) >= 60)
		{
			_sec = (firstValue._sec + _sec) - 60;
			_min++;
		}
		else
		{
			_sec = (firstValue._sec + _sec);
		}
		if ((firstValue._min + _min) >= 60)
		{
			_min = (firstValue._min + _min) - 60;
			_hours++;
		}
		else
		{
			_min = (firstValue._min + _min);
		}

		if ((firstValue._hours + _hours) >= 24)
		{
			_hours = (firstValue._hours + _hours) - 24;
			_day++;
		}
		else
		{
			_hours = (firstValue._hours + _hours);
		}
		_year = firstValue._year + _year;
		if (firstValue._mont + _mont > 12)
		{
			_mont = firstValue._mont + _mont - 12;
			_year++;
		}
		// Работа с месяцами...
		if (_mont == 0)
		{
			_mont++;
		}
		if (_mont == 2 && _year % 4 == 0)
		{
			if (firstValue._day + _day >= 29)
			{
				_day = firstValue._day + _day - 29;
				_mont++;
				if (_mont > 12)
				{
					_year++; _mont -= 11;
				}
			}
			else
			{
				_day = firstValue._day + _day;
			}
		}
		else if (_mont == 2)
		{
			if (firstValue._day + _day >= 28)
			{
				_day = firstValue._day + _day - 28;
				_mont++;
				if (_mont > 12)
				{
					_year++; _mont -= 11;
				}
			}
			else
			{
				_day = firstValue._day + _day;
			}
		}
		else if (_mont == 1 || _mont == 3 || _mont == 5 || _mont == 7 || _mont == 8 || _mont == 10 || _mont == 12)
		{
			if (firstValue._day + _day >= 31)
			{
				_day = firstValue._day + _day - 31;
				_mont++;
				if (_mont > 12)
				{
					_year++; _mont -= 11;
				}
			}
			else
			{
				_day = firstValue._day + _day;
			}
		}
		else
		{
			if (firstValue._day + _day >= 30)
			{
				_day = firstValue._day + _day - 30;
				_mont++;
				if (_mont > 12)
				{
					_year++; _mont -= 11;
				}
			}
			else
			{
				_day = firstValue._day + _day;
			}
		}
	}

	void print()
	{
		cout << _day << '.' << _mont << '.' << _year << " " << _hours << ':' << _min << ':' << _sec;
	}
	
#pragma region GET&SET
	//GET
	int Day()
	{
		return _day;
	}
	int Mont()
	{
		return _mont;
	}
	int Year()
	{
		return _year;
	}
	int Hours()
	{
		return _hours;
	}
	int Min()
	{
		return _min;
	}
	int Sec()
	{
		return _sec;
	}

	// SET

	void sDay(int day)
	{
		_day = day;
	}
	void sMont(int mont)
	{
		_mont = mont;
	}
	void sYear(int year)
	{
		_year = year;
	}
	void sHours(int hours)
	{
		_hours = hours;
	}
	void sMin(int min)
	{
		_min = min;
	}
	void sSec(int sec)
	{
		_sec = sec;
	}
#pragma endregion
	
#pragma endregion

	
private:
	int _day, _mont, _year, _hours, _min, _sec;
};

void print(DateTime date)
{
	cout << date.Day() << '.' << date.Mont() << '.' << date.Year() << " " << date.Hours() << ':' << date.Min() << ':' << date.Sec();
}

/// <summary>
	/// Sum first date and second date
	/// </summary>
	/// <param name="firstValue">fist date</param>
	/// <param name="secondValue">second date</param>
	/// <returns>new date</returns>
DateTime sum(DateTime firstValue, DateTime secondValue)
{
	DateTime answ;
	if ((firstValue.Sec() + secondValue.Sec()) >= 60)
	{
		answ.sSec((firstValue.Sec() + secondValue.Sec()) - 60);
		answ.sMin(answ.Min()+1);
	}
	else
	{
		answ.sSec(firstValue.Sec() + secondValue.Sec());
	}
	if ((firstValue.Min() + secondValue.Min()) >= 60)
	{
		answ.sMin(firstValue.Min() + secondValue.Min() - 60);
		answ.sHours(answ.Hours()+1);
	}
	else
	{
		answ.sMin(firstValue.Min() + secondValue.Min());
	}

	if ((firstValue.Hours() + secondValue.Hours()) >= 24)
	{
		answ.sHours(firstValue.Hours() + secondValue.Hours() - 24);
		answ.sDay(answ.Day()+1);
	}
	else
	{
		answ.sHours(firstValue.Hours() + secondValue.Hours());
	}
	answ.sYear(firstValue.Year() + secondValue.Year());
	if (firstValue.Mont() + secondValue.Mont()> 12)
	{
		answ.sMont(firstValue.Mont()+ secondValue.Mont()- 12);
		answ.sYear(answ.Year()+1);
	}
	// Работа с месяцами...
	if (answ.Mont() == 0)
	{
		answ.sMont(answ.Mont()+1);
	}
	if (answ.Mont() == 2 && answ.Year()% 4 == 0)
	{
		if (firstValue.Day() + secondValue.Day() >= 29)
		{
			answ.sDay(firstValue.Day() + secondValue.Day()- 29);
			answ.sMont(answ.Mont()+1);
			if (answ.Mont() > 12)
			{
				answ.sYear(answ.Year()+1); answ.sMont(answ.Mont() - 11);
			}
		}
		else
		{
			answ.sDay(firstValue.Day()+ secondValue.Day());
		}
	}
	else if (answ.Mont()== 2)
	{
		if (firstValue.Day() + secondValue.Day()>= 28)
		{
			answ.sDay(firstValue.Day() + secondValue.Day()- 28);
			answ.sMont(answ.Mont()+1);
			if (answ.Mont() > 12)
			{
				answ.sYear(answ.Year()+1); answ.sMont(answ.Mont()- 11);
			}
		}
		else
		{
			answ.sDay( firstValue.Day()+ secondValue.Day());
		}
	}
	else if (answ.Mont() == 1 || answ.Mont() == 3 || answ.Mont()== 5 || answ.Mont() == 7 || answ.Mont() == 8 || answ.Mont() == 10 || answ.Mont() == 12)
	{
		if (firstValue.Day() + secondValue.Day() >= 31)
		{
			answ.sDay( firstValue.Day()+ secondValue.Day()- 31);
			answ.sMont(answ.Mont()+1);
			if (answ.Mont() > 12)
			{
				answ.sYear(answ.Year()+1); answ.sMont(answ.Mont()- 11);
			}
		}
		else
		{
			answ.sDay(firstValue.Day()+ secondValue.Day());
		}
	}
	else
	{
		if (firstValue.Day() + secondValue.Day()>= 30)
		{
			answ.sDay(firstValue.Day()+ secondValue.Day()- 30);
			answ.sMont(answ.Mont()+10);
			if (answ.Mont() > 12)
			{
				answ.sYear(answ.Year()+1); answ.sMont(answ.Mont() - 11);
			}
		}
		else
		{
			answ.sDay(firstValue.Day()+ secondValue.Day());
		}
	}
	return answ;
}
int main()
{
	DateTime _1 = DateTime(19, 8, 2001, 19,41,59);
	DateTime _2 = DateTime(28, 4, 4, 18, 58, 00);
	sum(_1, _2);
	_1.print();
	cout<<"\n" << "+" << endl;
	_2.print();
	cout << endl;
	cout << '=' << endl;
	print(sum(_1, _2));

}