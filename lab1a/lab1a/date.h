#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <exception>

class Date {
public:
    //Date() {};

    Date(int new_year, int new_month, int new_day) : year(new_year), month(new_month), day(new_day) {};

    void operator=(const Date& d)
    {
        year = (d.GetYear());
        month = (d.GetMonth());
        day = (d.GetDay());
    }

    int GetYear() const
    {
        return year;
    }

    int GetMonth() const
    {
        return month;
    }

    int GetDay() const
    {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
    if ((lhs.GetYear() < rhs.GetYear()) || (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) ||
        (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay()))
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& s, const Date& date)
{
    if (date.GetYear() < 0)
    {
        s << '-';
        s << std::setw(4) << std::setfill('0') << date.GetYear() * (-1) << '-' <<
            std::setw(2) << std::setfill('0') << date.GetMonth() << '-' <<
            std::setw(2) << std::setfill('0') << date.GetDay();
    }
    else
    {
        s << std::setw(4) << std::setfill('0') << date.GetYear() << '-' <<
            std::setw(2) << std::setfill('0') << date.GetMonth() << '-' <<
            std::setw(2) << std::setfill('0') << date.GetDay();
    }
    return s;
}

Date ParseDate(std::istream& s)
{
    std::string l;
    s >> l;
    std::stringstream s1(l);
    int y, m, d;
    char def1, def2;
    std::string rest, ref;
    s1 >> y >> def1 >> m >> def2 >> ref;
    if (def1 != '-' || def2 != '-')
        throw std::runtime_error("Wrong date format: " + l);
    if (ref[0] != '-' && ref[0] != '+' && (ref[0] < '0' || ref[0] > '9'))
        throw std::runtime_error("Wrong date format: " + l);
    std::stringstream s2(ref);
    s2 >> d >> rest;
    if (rest.size())
        throw std::runtime_error("Wrong date format: " + l);
    if (m < 1 || m > 12)
        throw std::runtime_error("Month value is invalid: " + std::to_string(m));
    if (d < 1 || d > 31)
        throw std::runtime_error("Day value is invalid: " + std::to_string(d));
    Date new_date(y, m, d);
    return Date(y, m, d);
}
