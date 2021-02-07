#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include "date.h"
#include <algorithm>
#include <memory>

class Database 
{
public:
    void Add(const Date& date, const string& event);

    void Print(std::ostream& os) const;

private:
    struct DayEvents
    {
        std::set<std::string> elements;
        std::vector<std::string> order;
    };

    std::map<Date, DayEvents> events;
};