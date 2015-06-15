#include <cstdlib> // abs
#include <algorithm> // min
#include <sstream> // istringstream
#include <limits> // numeric_limits
#include <cstdlib> // atoi
#include "date.h"

/* static members */
Date::Format Date::format = DDMMYYYY;

bool Date::calcWorkdays = false;

bool Date::calcClosestWorkday = false;

int Date::searchDirection = 0;

std::vector<Date> Date::daysOff;

std::vector<Date> Date::worksOff;

const int Date::daysInMonths[] = {31, 28, 31, 30, 31, 30,
																	31, 31, 30, 31, 30, 31};

const char Date::days[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday",
																"Thursday", "Friday", "Saturday"};

const char Date::shortMonths[][4] = {"Jan", "Feb", "Mar",
																			"Apr", "May", "Jun",
																			"Jul", "Aug", "Sep",
																			"Oct", "Nov", "Dec"};

const char Date::months[][10] = {"January", "February", "March", "April",
																	"May", "June", "July", "August", "September",
																	"October", "November", "December"};

const char Date::numbers[][7] = {"last", "first", "second",
																	"third", "fourth", "fifth"};

const int Date::holidaysCount = 11;

const Date Date::holidays[] = {Date(1, 1), Date(3, 3), Date(1, 5),
															Date(6, 5), Date(24, 5), Date(6, 9),
															Date(22, 9), Date(1, 11), Date(24, 12),
															Date(25, 12), Date(26, 12)};

/* private methods */
bool Date::isYearLeap() const {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool Date::isValid() const {
	if (year < 0) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > endOfMonth()) return false;
	return true;
}

int Date::endOfMonth() const {
	return (month == 2 && isYearLeap()) ? 29 : daysInMonths[month - 1];
}

unsigned long Date::getDaysFromZero() const {
	int d = day;
	int m = month;
	int y = year;

	// base date: March 1st, year 0 (reference year)
	m = (m + 9) % 12;
	y -= m / 10; // Reduce year if month is January or February
	return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

void Date::setDateFromDays(unsigned long days) {
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

unsigned long Date::distInDays(const Date& other) const {
	unsigned long days = getDaysFromZero();
	unsigned long otherDays = other.getDaysFromZero();
	return days < otherDays ? (otherDays - days) : (days - otherDays);
}

bool Date::isFormatValid(int format) {
	return format >= 0 && format < COUNT;
}

bool Date::disableWorkdayCalc() {
	if (Date::calcWorkdays) {
		Date::calcWorkdays = false;
		return true;
	}
	return false;
}

bool Date::disableClosestWorkdayCalc() {
	if (Date::calcClosestWorkday) {
		Date::calcClosestWorkday = false;
		return true;
	}
	return false;
}

bool Date::enableWorkdayCalc() {
	if (!Date::calcWorkdays) {
		Date::calcWorkdays = true;
		return true;
	}
	return false;
}

bool Date::enableClosestWorkdayCalc() {
	if (!Date::calcClosestWorkday) {
		Date::calcClosestWorkday = true;
		return true;
	}
	return false;
}

void Date::swap(Date& date1, Date& date2) const {
	Date temp = date1;
	date1 = date2;
	date2 = temp;
}

int Date::parseNumber(const std::string& number) {
	for (int i = 0; i < 6; i++) {
		if (number == numbers[i]) return i;
	}
	return -1;
}

int Date::parseWeekday(const std::string& weekday) {
	for (int i = 0; i < 7; i++) {
		if (weekday == days[i]) return i;
	}
	return -1;
}

int Date::parseMonth(const std::string& month) {
	for (int i = 0; i < 12; i++) {
		if (month == months[i]) return i + 1;
	}
	return -1;
}

Date Date::getDateOfFirstWeekday(int weekday) const {
	Date result(1, month, year);

	// get the first weekday of the month
	int firstWeekdayOfMonth = result.getWeekday();

	int day = weekday - firstWeekdayOfMonth;
	if (day < 0) day += 7;
	day += 1;

	result.day = day;
	return result;
}

Date Date::getDateOfLastWeekday(int weekday) const {
	Date result(1, month, year);
	result *= 1; // go to the next month

	// get the date of the first weekday of next month
	result = result.getDateOfFirstWeekday(weekday);

	result -= 7; // subtract 7 days
	return result;
}

/* public methods */
Date::Date(int day, int month, int year): day(day), month(month), year(year) {
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->day = 1;
		this->month = 2;
		this->year = 1582;
	}
}

Date::Date(const std::string& desc) {
	// parse date
	std::istringstream iss(desc);

	std::string number; iss >> number;
	int numberIndex = parseNumber(number);

	std::string weekday; iss >> weekday;
	int weekdayIndex = parseWeekday(weekday);

	iss.ignore(); // ignore space
	// ignore 'of'
	iss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');

	std::string month; iss >> month;
	this->month = parseMonth(month);

	std::string year; iss >> year;
	this->year = std::atoi(year.c_str());

	switch (numberIndex) {
		case 0: // last weekday
			*this = getDateOfLastWeekday(weekdayIndex);
			break;
		case 1:
			*this = getDateOfFirstWeekday(weekdayIndex);
			break;
		case 2:
			*this = getDateOfFirstWeekday(weekdayIndex);
			*this += 7;
			break;
		case 3:
			*this = getDateOfFirstWeekday(weekdayIndex);
			*this += 14;
			break;
		case 4:
			*this = getDateOfFirstWeekday(weekdayIndex);
			*this += 21;
			break;
		case 5:
			*this = getDateOfFirstWeekday(weekdayIndex);
			*this += 28;
			break;
	}
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

int Date::getWeekday() const {
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

bool Date::isSaturday() const {
	return getWeekday() == Saturday;
}

bool Date::isSunday() const {
	return getWeekday() == Sunday;
}

bool Date::isWeekend() const {
	return isSaturday() || isSunday();
}

bool Date::isEasterHoliday() const {
	Date easter = calculateEaster();
	return *this == easter || *this == easter - 1 || *this == easter - 2;
}

bool Date::isHoliday() const {
	for (int i = 0; i < holidaysCount; i++) {
		if (*this == holidays[i]) return true;
	}
	return isEasterHoliday();
}

bool Date::isDayOff() const {
	for (int i = 0, len = daysOff.size(); i < len; i++) {
		if (*this == daysOff[i]) return true;
	}
	return false;
}

bool Date::isWorkOff() const {
	for (int i = 0, len = worksOff.size(); i < len; i++) {
		if (*this == worksOff[i]) return true;
	}
	return false;
}

bool Date::isWorkday() const {
	// disable calculations with workdays
	bool disWorkday = disableWorkdayCalc();
	bool disClosestWorkday = disableClosestWorkdayCalc();

	bool result = false;
	if (isWorkOff()) result = true;
	else if (isDayOff()) result = false;
	else result = !(isWeekend() || isHoliday());

	// enable calculations with workdays
	if (disWorkday) enableWorkdayCalc();
	if (disClosestWorkday) enableClosestWorkdayCalc();

	return result;
}

Date Date::calculateEaster() const {
	int a = year % 19;
	int b = year % 4;
	int c = year % 7;
	int k = year / 100;
	int p = (13 + 8 * k) / 25;
	int q = k / 4;
	int M = (15 - p + k - q) % 30;
	int N = (4 + k - q) % 7;
	int d = (19 * a + M) % 30;
	int e = (2 * b + 4 * c + 6 * d + N) % 7;

	if (d == 29 && e == 6) {
		return Date(19, 4, year);
	}
	if (d == 28 && e == 6 && (11 * M + 11) % 30 < 19) {
		return Date(18, 4, year);
	}
	if (d + e > 9) {
		return Date(d + e - 9, 4, year);
	}
	return Date(d + e + 22, 3, year);
}

Date Date::closestWorkday(int direction) const {
	// disable calculations with workdays
	bool disWorkday = disableWorkdayCalc();
	bool disClosestWorkday = disableClosestWorkdayCalc();

	if (direction == 0) { // direction doesn't matter
		Date backward = closestWorkday(-1);
		Date forward = closestWorkday(1);
		if (forward - *this <= *this - backward) return forward;
		return backward;
	}

	Date result = *this;
	int sign = (direction > 0 ? 1 : -1);

	while (!result.isWorkday()) {
		result += sign;
	}

	// enable calculations with workdays
	if (disWorkday) enableWorkdayCalc();
	if (disClosestWorkday) enableClosestWorkdayCalc();

	return result;
}

void Date::setDay(int day) {
	int oldDay = this->day;
	this->day = day;
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->day = oldDay;
	}
}

void Date::setMonth(int month) {
	int oldMonth = this->month;
	this->month = month;
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->month = oldMonth;
	}
}

void Date::setYear(int year) {
	int oldYear = this->year;
	this->year = year;
	if (!isValid()) {
		std::cout << "The date is not valid.\n";
		this->year = oldYear;
	}
}

void Date::setFormat(int format) {
	Format oldFormat = Date::format;
	Date::format = Format(format);
	if (!isFormatValid(format)) {
		std::cout << "The format is not valid.\n";
		Date::format = oldFormat;
	}
}

void Date::setCalcWorkdays(bool calcWorkdays) {
	Date::calcWorkdays = calcWorkdays;
}

void Date::setCalcClosestWorkday(bool calcClosestWorkday) {
	Date::calcClosestWorkday = calcClosestWorkday;
}

void Date::setSearchDirection(int searchDirection) {
	Date::searchDirection = searchDirection;
}

void Date::addDaysOff(int count) {
	for (int i = 0; i < count; i++) {
		std::cout << "Insert the date of the day off: ";
		Date dayOff; std::cin >> dayOff;
		daysOff.push_back(dayOff);
		std::cout << "Insert the work off date: ";
		Date workOff; std::cin >> workOff;
		worksOff.push_back(workOff);
	}
}

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

bool isDay(const std::string& str) {
	int len = str.length();
	return len == 1 || len == 2;
}

Date Date::calculate() {
	std::string word; std::cin >> word;
	if (isDigit(word[0]) && isDay(word)) { // construct date
		std::string month; std::cin >> month;
		std::string year; std::cin >> year;
		return Date(std::atoi(word.c_str()),
								parseMonth(month),
								std::atoi(year.c_str()));
	}
	else if (word == "(") { // binary operation
		Date left = calculate();
		char operation; std::cin >> operation;
		if (operation == ')') std::cin >> operation;
		std::string amount; std::cin >> amount;
		std::string right; std::cin >> right;
		std::string kind;

		bool enWorkdayCalc = false;
		bool disWorkdayCalc = false;
		if (right == "work") {
			enWorkdayCalc = enableWorkdayCalc();
			std::cin >> kind;
		} else {
			disWorkdayCalc = disableWorkdayCalc();
			kind = right;
		}

		Date result;
		switch (operation) {
			case '+':
				if (kind == "days" || kind == "day") {
					result = left + std::atoi(amount.c_str());
				}
				else if (kind == "weeks" || kind == "week") {
					result = left ^ std::atoi(amount.c_str());
				}
				else if (kind == "months" || kind == "month") {
					result = left * std::atoi(amount.c_str());
				}
				else if (kind == "years" || kind == "year") {
					result = left & std::atoi(amount.c_str());
				}
				if (enWorkdayCalc) disableWorkdayCalc();
				else if (disWorkdayCalc) enableWorkdayCalc();
				return result;
				break;
			case '-':
				if (kind == "days" || kind == "day") {
					result = left - std::atoi(amount.c_str());
				}
				else if (kind == "weeks" || kind == "week") {
					result = left % std::atoi(amount.c_str());
				}
				else if (kind == "months" || kind == "month") {
					result = left / std::atoi(amount.c_str());
				}
				else if (kind == "years" || kind == "years") {
					result = left | std::atoi(amount.c_str());
				}
				if (enWorkdayCalc) disableWorkdayCalc();
				else if (disWorkdayCalc) enableWorkdayCalc();
				return result;
				break;
		}
	}
	return Date();
}

Date Date::operator+(int days) const {
	return Date(*this) += days;
}

Date Date::operator-(int days) const {
	return Date(*this) -= days;
}

Date& Date::operator+=(int days) {
	if (!calcWorkdays) { // calculate with calendar days
		setDateFromDays(getDaysFromZero() + days);

		// calculate date to closest workday
		if (calcClosestWorkday) *this = closestWorkday(searchDirection);
		return *this;
	}
	// calculate with workdays
	int direction = (days > 0 ? 1 : -1);
	int daysCount = std::abs(days);
	while (daysCount) {
		setDateFromDays(getDaysFromZero() + direction);
		if (isWorkday()) daysCount--; // skip holidays
	}
	return *this;
}

Date& Date::operator-=(int days) {
	return *this += -days;
}

Date& Date::operator++() {
	return *this += 1;
}

Date& Date::operator--() {
	return *this -= 1;
}

Date Date::operator++(int) {
	Date result = *this;
	++(*this);
	return result;
}

Date Date::operator--(int) {
	Date result = *this;
	--(*this);
	return result;
}

Date Date::operator*(int months) const {
	return Date(*this) *= months;
}

Date Date::operator/(int months) const {
	return Date(*this) /= months;
}

Date& Date::operator*=(int months) {
	int dateAsMonths = (year * 12 + month) + months;

	year = (dateAsMonths - 1) / 12;
	month = ((dateAsMonths - 1) % 12) + 1;
	day = std::min(day, endOfMonth());

	// calculate date to closest workday
	if (calcClosestWorkday) *this = closestWorkday(searchDirection);
	return *this;
}

Date& Date::operator/=(int months) {
	return *this *= -months;
}

Date Date::operator&(int years) const {
	return Date(*this) &= years;
}

Date Date::operator|(int years) const {
	return Date(*this) |= years;
}

Date& Date::operator&=(int years) {
	year += years;
	if (month == 2 && day == 29 && !isYearLeap()) day = 28;

	// calculate date to closest workday
	if (calcClosestWorkday) *this = closestWorkday(searchDirection);
	return *this;
}

Date& Date::operator|=(int years) {
	return *this &= -years;
}

Date Date::operator^(int weeks) const {
	return Date(*this) ^= weeks;
}

Date Date::operator%(int weeks) const {
	return Date(*this) %= weeks;
}

Date& Date::operator^=(int weeks) {
	setDateFromDays(getDaysFromZero() + (weeks * 7));

	// calculate date to closest workday
	if (calcClosestWorkday) *this = closestWorkday(searchDirection);
	return *this;
}

Date& Date::operator%=(int weeks) {
	return *this ^= -weeks;
}

int Date::operator-(const Date& other) const {
	return distInDays(other);
}

int Date::operator/(const Date& other) const {
	Date date1 = *this;
	Date date2 = other;
	if (date1 > date2) swap(date1, date2);
	int monthsCount = (date2 | date1) * 12 + std::abs(date2.month - date1.month);
	if (date2.day < date1.day) monthsCount--;
	return monthsCount;
}

int Date::operator|(const Date& other) const {
	return std::abs(other.year - year);
}

int Date::operator%(const Date& other) const {
	return (*this - other) / 7;
}

bool Date::operator==(const Date& other) const {
	return day == other.day && month == other.month && year == other.year;
}

bool Date::operator<=(const Date& other) const {
	return *this < other || *this == other;
}

bool Date::operator>=(const Date& other) const {
	return *this > other || *this == other;
}

bool Date::operator<(const Date& other) const {
	if (year < other.year) return true;
	if (year > other.year) return false;
	if (year == other.year) {
		if (month < other.month) return true;
		if (month > other.month) return false;
		if (month == other.month) return day < other.day;
	}
	return false;
}

bool Date::operator>(const Date& other) const {
	return !(*this <= other);
}

/* friends */
std::istream& operator>>(std::istream& is, Date& date) {
	int day = 0;
	int month = 0;
	int year = 0;
	do {
		is >> day >> month >> year;
		date.day = day;
		date.month = month;
		date.year = year;
	} while (!date.isValid());
	return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	switch (Date::format) {
		case Date::DDMMYYYY:
			if (date.day < 10) os << '0';
			os << date.day << '.';
			if (date.month < 10) os << '0';
			os << date.month << '.' << date.year;
			break;
		case Date::MMDDYYYY:
			if (date.month < 10) os << '0';
			os << date.month << '-';
			if (date.day < 10) os << '0';
			os << date.day << '-' << date.year;
			break;
		case Date::YYYYMMDD:
			os << date.year << '-';
			if (date.month < 10) os << '0';
			os << date.month << '-';
			if (date.day < 10) os << '0';
			os << date.day;
			break;
		case Date::DMMMMYYYY:
			os << date.day << ' ' <<
						Date::months[date.month - 1] << ' ' << date.year;
			break;
		case Date::DDMMMYYYY:
			if (date.day < 10) os << '0';
			os << date.day << '/' <<
						Date::shortMonths[date.month - 1] << '/' << date.year;
			break;
		case Date::DAYDMMMMYYYY:
			os << Date::days[date.getWeekday()] << ", " << date.day << ' ' <<
						Date::months[date.month - 1] << ' ' << date.year;
			break;
		default:
			break;
	}
	return os;
}
