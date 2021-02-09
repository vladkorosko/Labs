#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <exception>

class Date {
public:
    Date();

    Date(int new_year, int new_month, int new_day);

    void operator=(const Date& d);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& s, const Date& date);

Date ParseDate(std::istream& s);
