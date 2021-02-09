#include "date.h"

using namespace std;

Date::Date() {};

Date::Date(int new_year, int new_month, int new_day) : year(new_year), month(new_month), day(new_day) {};

void Date::operator=(const Date& d)
{
    year = (d.GetYear());
    month = (d.GetMonth());
    day = (d.GetDay());
}

int Date::GetYear() const
{
    return year;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetDay() const
{
    return day;
}


bool operator<(const Date& lhs, const Date& rhs)
{
    if ((lhs.GetYear() < rhs.GetYear()) || (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) ||
        (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay()))
        return true;
    return false;
}

bool operator>(const Date& lhs, const Date& rhs)
{
    if ((lhs.GetYear() > rhs.GetYear()) || (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() > rhs.GetMonth()) ||
        (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() > rhs.GetDay()))
        return true;
    return false;
}

bool operator==(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay())
        return true;
    return false;
}

bool operator<=(const Date& lhs, const Date& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const Date& lhs, const Date& rhs)
{
    return !(lhs < rhs);
}

bool operator!=(const Date& lhs, const Date& rhs)
{
    return !(lhs == rhs);
}

ostream& operator<<(ostream& s, const Date& date)
{
    if (date.GetYear() < 0)
    {
        s << '-';
        s << setw(4) << setfill('0') << date.GetYear() * (-1) << '-' <<
            setw(2) << setfill('0') << date.GetMonth() << '-' <<
            setw(2) << setfill('0') << date.GetDay();
    }
    else
    {
        s << setw(4) << setfill('0') << date.GetYear() << '-' <<
            setw(2) << setfill('0') << date.GetMonth() << '-' <<
            setw(2) << setfill('0') << date.GetDay();
    }
    return s;
}

Date ParseDate(istream& s)
{
    string l;
    s >> l;
    stringstream s1(l);
    int y, m, d;
    char def1, def2;
    string rest, ref;
    s1 >> y >> def1 >> m >> def2 >> ref;
    if (def1 != '-' || def2 != '-')
        throw runtime_error("Wrong date format: " + l);
    if (ref[0] != '-' && ref[0] != '+' && (ref[0] < '0' || ref[0] > '9'))
        throw runtime_error("Wrong date format: " + l);
    stringstream s2(ref);
    s2 >> d >> rest;
    if (rest.size())
        throw ("Wrong date format: " + l);
    if (m < 1 || m > 12)
        throw runtime_error("Month value is invalid: " + to_string(m));
    if (d < 1 || d > 31)
        throw runtime_error("Day value is invalid: " + to_string(d));
    return Date(y, m, d);
}
