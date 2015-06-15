#ifndef DATE_H
#define DATE_H

#include <iostream> // istream, ostream
#include <string>
#include <vector>

class Date {
public:
	enum Format {
		DDMMYYYY,
		MMDDYYYY,
		YYYYMMDD,
		DMMMMYYYY,
		DDMMMYYYY,
		DAYDMMMMYYYY,
		COUNT
	};

	enum Days {
		Sunday,
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday
	};

private:
	int day;
	int month;
	int year;

	static Format format;
	static bool calcWorkdays;
	static bool calcClosestWorkday;
	static int searchDirection;

	static std::vector<Date> daysOff;
	static std::vector<Date> worksOff;

	static const int daysInMonths[12];
	static const char days[7][10];
	static const char shortMonths[12][4];
	static const char months[12][10];
	static const char numbers[6][7];
	static const int holidaysCount;
	static const Date holidays[11];

	/* date validation */
	bool isYearLeap() const;
	bool isValid() const;

	/* return the last day of month */
	int endOfMonth() const;

	/* convert date to days counted from date 0/0/0 */
	unsigned long getDaysFromZero() const;

	/* convert days to date */
	void setDateFromDays(unsigned long days);

	/* get the distance in days to other date */
	unsigned long distInDays(const Date& other) const;

	/* date format validation */
	static bool isFormatValid(int format);

	/* enable/disable workday modes */
	static bool disableWorkdayCalc();
	static bool disableClosestWorkdayCalc();
	static bool enableWorkdayCalc();
	static bool enableClosestWorkdayCalc();

	void swap(Date& date1, Date& date2) const;

	/* parse strings */
	static int parseNumber(const std::string& number);
	static int parseWeekday(const std::string& weekday);
	static int parseMonth(const std::string& month);

	Date getDateOfFirstWeekday(int weekday) const;
	Date getDateOfLastWeekday(int weekday) const;

public:
	Date(int day = 1, int month = 2, int year = 1582);
	Date(const std::string& desc);

	/* getters */
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	int getWeekday() const;
	bool isSaturday() const;
	bool isSunday() const;
	bool isWeekend() const;
	bool isEasterHoliday() const;
	bool isHoliday() const;
	bool isDayOff() const;
	bool isWorkOff() const;
	bool isWorkday() const;
	Date calculateEaster() const;

	/* find the closest workday to current date
	** searching in direction:
	** direction < 0 -- backward
	** direction > 0 -- forward
	** direction = 0 -- doesn't matter */
	Date closestWorkday(int direction) const;

	/* setters */
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	static void setFormat(int format);

	/* change behavior of +, -, +=, -=
	** to calculate with workdays instead of calendar days */
	static void setCalcWorkdays(bool calcWorkdays);

	/* change behavior of all arithmetic operations
	** to calculate dates to closest workday */
	static void setCalcClosestWorkday(bool calcClosestWorkday);

	/* default searchDirection = 0 (direction doesn't matter)
	** searchDirection < 0 -- backward search
	** searchDirection > 0 -- forward search
	** searchDirection = 0 -- direction doesn't matter */
	static void setSearchDirection(int searchDirection);

	static void addDaysOff(int count);

	static Date calculate();

	/* dates calculations */
	Date operator+(int days) const; // add days
	Date operator-(int days) const; // subtract days
	Date& operator+=(int days); // add days to date
	Date& operator-=(int days); // subtract days from date
	Date& operator++(); // add 1 day and return updated date
	Date& operator--(); // subtract 1 day and return updated date
	Date operator++(int); // add 1 day and return old date
	Date operator--(int); // subtract 1 day and return old date
	Date operator*(int months) const; // add months
	Date operator/(int months) const; // subtract months
	Date& operator*=(int months); // add months to date
	Date& operator/=(int months); // subtract months from date
	Date operator&(int years) const; // add years
	Date operator|(int years) const; // subtract years
	Date& operator&=(int years); // add years to date
	Date& operator|=(int years); // subtract years from date
	Date operator^(int weeks) const; // add weeks
	Date operator%(int weeks) const; // subtract weeks
	Date& operator^=(int weeks); // add weeks to date
	Date& operator%=(int weeks); // subtract weeks from date
	int operator-(const Date& other) const; // distance in days
	int operator/(const Date& other) const; // distance in months
	int operator|(const Date& other) const; // distance in years
	int operator%(const Date& other) const; // distance in weeks

	/* compare dates */
	bool operator==(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator>(const Date& other) const;

	/* date input/output operations */
	friend std::istream& operator>>(std::istream& is, Date& date);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif
