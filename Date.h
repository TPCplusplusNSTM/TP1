#ifndef DATE_H
#define DATE_H
#include <string>

namespace date {
	class Date {
	private:
		int _year;
		int _month;
		int _day;
	public:
		Date(int year, int month, int day);
		Date() = default;
		~Date();
		int year() const;
		int month() const;
		int day() const;
		bool checkDate(int year, int month, int day);
		bool checkDate();
		void setYear(int year);
		void setMonth(int month);
		void setDay(int day);
		void nextDay();
		std::string toString() const;
	};

	bool operator == (const Date& d1, const Date& d2); // comparison operators
	bool operator != (const Date& d1, const Date& d2);
	bool operator < (const Date& d1, const Date& d2);
	bool operator > (const Date& d1, const Date& d2);
	bool operator <= (const Date& d1, const Date& d2);
	bool operator >= (const Date& d1, const Date& d2);

}
#endif // DATE_H