#include<iostream>
#include<string>
#include<map>
#include<set>
#include<iomanip>
#include<vector>
#include<sstream>

using namespace std;

class Date {
public:
    Date() {};
    Date(int new_year, int new_month, int new_day)
    {
        year = new_year;
        month = new_month;
        day = new_day;
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

istream& operator>>(istream& s, Date& date)
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
        throw runtime_error("Wrong date format: " + l);
    if (m < 1 || m > 12)
        throw runtime_error("Month value is invalid: " + to_string(m));
    if (d < 1 || d > 31)
        throw runtime_error("Day value is invalid: " + to_string(d));
    Date new_date(y, m, d);
    date = new_date;
    return s;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event)
    {
        events[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
        return events[date].erase(event);
    }
    int DeleteDate(const Date& date)
    {
        int n = events[date].size();
        events.erase(date);
        return n;
    }

    void Find(const Date& date) const
    {
        if (events.count(date) > 0)
        {
            set<string> value;
            value = events.at(date);
            for (const string& i : value)
                cout << i << endl;
        }
    }

    void Print() const
    {
        for (const auto& i : events)
            for (const auto& j : i.second)
                cout << i.first << ' ' << j << endl;
    }
private:
    map<Date, set<string>> events;
};

int main() {
    Database db;
    string command;
    string s1;
    while (getline(cin, s1))
    {
        if (s1.size())
        {
            istringstream s(s1);
            s >> command;
            try
            {
                if (command == "Print")
                    db.Print();
                else if (command == "Add" || command == "Find" || command == "Del")
                {
                    Date date;
                    s >> date;
                    if (command == "Find")
                        db.Find(date);
                    else if (command == "Add")
                    {
                        string event;
                        s >> event;
                        db.AddEvent(date, event);
                    }
                    else
                    {
                        if (!s.eof())
                        {
                            string event;
                            s >> event;
                            if (db.DeleteEvent(date, event))
                                cout << "Deleted successfully" << endl;
                            else cout << "Event not found" << endl;
                        }
                        else cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                    }
                }
                else cout << "Unknown command: " + command << endl;
            }
            catch (runtime_error& e)
            {
                cout << e.what() << endl;
            }
        }
    }

    return 0;
}