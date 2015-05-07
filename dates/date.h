#ifndef DATE_H
#define DATE_H

#include <iostream>

// helper arrays
const char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday",
													"Thursday", "Friday", "Saturday"};
const char shortMonths[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
																"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const char months[12][10] = {"January", "February", "March", "April",
														"May", "June", "July", "August", "September",
														"October", "November", "December"};
const int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char numbers[6][7] = {"last", "first", "second",
														"third", "fourth", "fifth"};

class Date {
private:
	int day;
	int month;
	int year;
	int format;

	bool isYearLeap() const;
	bool isValid() const;
	bool isFormatValid() const;
	int getFormat() const;
	int endOfMonth() const;
	unsigned long getDaysFromZero() const;
	void setDateFromDays(unsigned long days);
	unsigned long distInDays(const Date& other) const;

public:
	Date(int day = 1, int month = 2, int year = 1582);
	Date(const char *desc);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	int getWeekday() const;

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setFormat(int format);

	const Date operator+(int days) const;
	const Date operator-(int days) const;
	Date& operator+=(int days);
	Date& operator-=(int days);
	Date& operator++();
	Date& operator--();
	Date operator++(int);
	Date operator--(int);
	const Date operator*(int months) const;
	const Date operator/(int months) const;
	Date& operator*=(int months);
	Date& operator/=(int months);
	const Date operator&(int years) const;
	const Date operator|(int years) const;
	Date& operator&=(int years);
	Date& operator|=(int years);
	const Date operator^(int weeks) const;
	const Date operator%(int weeks) const;
	Date& operator^=(int weeks);
	Date& operator%=(int weeks);
	const int operator-(const Date& other) const; // distance in days
	const int operator/(const Date& other) const; // distance in months
	const int operator|(const Date& other) const; // distance in years
	const int operator%(const Date& other) const; // distance in weeks

	friend std::istream& operator>>(std::istream& is, Date& date);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif
