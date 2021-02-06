#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include "date.h"

class Database 
{
public:
    void AddEvent(const Date& date, const std::string& event)
    {
        events[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const std::string& event)
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
            std::set<std::string> value;
            value = events.at(date);
            for (const std::string& i : value)
                std::cout << i << std::endl;
        }
    }

    void Print() const
    {
        for (const auto& i : events)
            for (const auto& j : i.second)
                std::cout << i.first << ' ' << j << std::endl;
    }
private:
    std::map<Date, std::set<std::string>> events;
};