#include <iostream> // istream, ostream
#include <cstdlib> // abs, labs
#include <algorithm> // min
#include "date.h"

bool isYearLeap() const {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isValid() const {
	if (year < 0) return false;

	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day >= 1 && day <= 31) return true;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day >= 1 && day <= 30) return true;
			break;
		case 2:
			if (isYearLeap()) {
				if (day >= 1 && day <= 29) return true;
			} else if (day >= 1 && day <= 28) return true;
	}

	return false;
}

int getFormat() const {
	return format;
}

int endOfMonth() const {
	return (month == 2 && isYearLeap(year)) ? 29 : daysInMonths[month - 1];
}

unsigned long getDaysFromZero() const {
	int d = day;
	int m = month;
	int y = year;

	// base date: March 1st, year 0 (reference year)
	m = (m + 9) % 12;
	y -= m / 10; // Reduce year if month is January or February
	return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

void setDateFromDays(unsigned long days) {
	int y = (10000 * days + 14780) / 3652425;
	int daysDiff = days - (365 * y + y / 4 - y / 100 + y / 400);
	if (daysDiff < 0) {
		y--;
		daysDiff = days - (365 * y + y / 4 - y / 100 + y / 400);
	}
	int monthIndex = (100 * daysDiff + 52) / 3060; // index 0 for March
	int m = (monthIndex + 2) % 12 + 1; // convert to normal month
	y += (monthIndex + 2) / 12; // convert to normal year
	int d = daysDiff - (monthIndex * 306 + 5) / 10 + 1; // get the day in month

	day = d;
	month = m;
	year = y;
}

unsigned long distInDays(const Date& other) const {
	return std::labs(other.daysFromZero() - daysFromZero())	;
}

Date(int day, int month, int year)
: day(day), month(month), year(year) {
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->day = 1;
		this->month = 2;
		this->year = 1582;
	}
}

Date(const char *desc) {}

int getDay() const {
	return day;
}

int getMonth() const {
	return month;
}

int getYear() const {
	return year;
}

int getWeekday() const {
	int d = day;
	int m = month;
	int y = year;

	// Offset from January 1st to every other month's first day of the week
	// Subtracted 1 from all values after February for non-leap years
	static int offset[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	// Reduce year if month is January or February (year starts from March 1st)
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + offset[m - 1] + d) % 7;
}

void setDay(int day) {
	int oldDay = this->day;
	this->day = day;
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->day = oldDay;
	}
}

void setMonth(int month) {
	int oldMonth = this->month;
	this->month = month;
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->month = oldMonth;
	}
}

void setYear(int year) {
	int oldYear = this->year;
	this->year = year;
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->year = oldYear;
	}
}

void setFormat(int format) {
	int oldFormat = this->format;
	this->format = format;
	if (!isFormatValid()) {
		std::cout << "The format is not valid.\n";
		this->format = oldFormat;
	}
}

const Date operator+(int days) const {
	return Date(*this) += days;
}

const Date operator-(int days) const {
	return Date(*this) -= days;
}

Date& operator+=(int days) {
	setDateFromDays(getDaysFromZero() + days);
	return *this;
}

Date& operator-=(int days) {
	return (*this) += -days;
}

Date& operator++() {
	return *this += 1;
}

Date& operator--() {
	return *this -= 1;
}

Date operator++(int) {
	Date result = *this;
	++(*this);
	return result;
}

Date operator--(int) {
	Date result = *this;
	--(*this);
	return result;
}

const Date operator*(int months) const {
	return Date(*this) *= months;
}

const Date operator/(int months) const {
	return Date(*this) /= months;
}

Date& operator*=(int months) {
	int dateAsMonths = (year * 12 + month) + months;

	year = (dateAsMonths - 1) / 12;
	month = ((dateAsMonths - 1) % 12) + 1;
	day = std::min(day, endOfMonth());

	return *this;
}

Date& operator/=(int months) {
	return (*this) *= -months;
}

const Date operator&(int years) const {
	return Date(*this) &= years;
}

const Date operator|(int years) const {
	return Date(*this) |= years;
}

Date& operator&=(int years) {
	year += years;
	if (month == 2 && day == 29 && !isYearLeap(year)) day = 28;
	return *this;
}

Date& operator|=(int years) {
	return (*this) &= -years;
}

const Date operator^(int weeks) const {
	return Date(*this) ^= weeks;
}

const Date operator%(int weeks) const {
	return Date(*this) %= weeks;
}

Date& operator^=(int weeks) {
	setDateFromDays(getDaysFromZero() + (weeks * 7));
	return *this;
}

Date& operator%=(int weeks) {
	return (*this) ^= -weeks;
}

const int operator-(const Date& other) const {
	return distInDays(other);
}

const int operator/(const Date& other) const {
	int monthsCount = (other.year - year) * 12 + other.month - month;
	if (other.day - day < 0) monthsCount--;
	return monthsCount;
}

const int operator|(const Date& other) const {
	return std::abs(other.year - year);
}

const int operator%(const Date& other) const {
	return ((*this) - other) / 7;
}

std::istream& operator>>(std::istream& is, Date& date) {
	int day = 0;
	int month = 0;
	int year = 0;
	do {
		is >> day >> month >> year;
		date.day = day;
		date.month = month;
		date.year = year;
	} while (date.isValid());
	return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	// TODO: use date format
	return os << date.day << " / " << date.month << " / " << date.year;
}
