#pragma once
#include <iostream>
#include <sstream>
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
    void Add(const Date& date, const std::string& event);

    void Print(std::ostream& os) const;

    std::string Last(const Date& d) const;

    template <typename Predicate>
    int RemoveIf(Predicate predicate) 
    {
        int count = 0;
        for (auto date = events.begin(); date != events.end(); ) 
        {
            if (predicate(date->first, "")) 
            {
                count += date->second.order.size();
                date = events.erase(date);
            }
            else 
            {
                auto new_predicate = [date, predicate](const std::string& event) 
                { 
                    return !predicate(date->first, event);
                };
                auto start = std::stable_partition(date->second.order.begin(), date->second.order.end(), new_predicate);
                if (start == date->second.order.begin()) 
                {
                    count += date->second.order.size();
                    date = events.erase(date);
                }
                else if (start != date->second.order.end()) 
                {
                    for (auto curr = --date->second.order.end(); curr != prev(start); curr--) 
                    {
                        date->second.order.pop_back();
                        date->second.elements.erase(*curr);
                        count++;
                    }
                    if (date->second.order.empty()) 
                        date = events.erase(date);
                    else ++date;
                }
                else 
                {
                    ++date;
                }
            }
        }
        return count;
    }

private:
    struct DayEvents
    {
        std::set<std::string> elements;
        std::vector<std::string> order;
    };

    std::map<Date, DayEvents> events;
};