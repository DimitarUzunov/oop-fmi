#include <iostream>
#include <string>
#include "date.h"

void testCalcWorkdays() {
	Date::setFormat(Date::DAYDMMMMYYYY);
	Date date(15, 4, 2015);
	std::cout << date << " + 4 days = " << date + 4 << '\n';
	Date::setCalcWorkdays(true);
	std::cout << date << " + 4 workdays = " << date + 4 << '\n';
	Date::setCalcWorkdays(false);
}

void testCalcClosestWorkday() {
	Date::setFormat(Date::DAYDMMMMYYYY);
	Date date(15, 4, 2015);
	std::cout << date << " + 4 months = " << date * 4 << '\n';
	Date::setCalcClosestWorkday(true);
	Date::setSearchDirection(0);
	std::cout << date << " + 4 months (closest workday) = " << date * 4 << '\n';
	Date::setCalcClosestWorkday(false);
}

void testDateDistance() {
	Date date1(29, 5, 2015);
	Date date2(28, 9, 2015);
	std::cout << date1 << " - " << date2 << " (in days) = " << (date1 - date2) << '\n';
	std::cout << date1 << " - " << date2 << " (in months) = " << (date2 / date1) << '\n';
	std::cout << date1 << " - " << date2 << " (in years) = " << (date1 | date2) << '\n';
	std::cout << date1 << " - " << date2 << " (in weeks) = " << (date1 % date2) << '\n';
}

void testConstructByDesc() {
	Date::setFormat(Date::DAYDMMMMYYYY);
	std::cout << "Insert date description: ";
	std::string desc;
	std::getline(std::cin, desc);
	Date date(desc);
	std::cout << date << '\n';
}

void testDaysOff() {
	Date::addDaysOff(2);
	testCalcWorkdays();
	testCalcClosestWorkday();
}

void testCalculate() {
	std::cout << "Insert dates expression: ";
	Date date = Date::calculate();
	std::cout << date << '\n';
}

int main() {
	// testCalcWorkdays();
	// testCalcClosestWorkday();
	// testDateDistance();
	// testConstructByDesc();
	// testDaysOff();
	// testCalculate();

	return 0;
}
