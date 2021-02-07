#include "database.h"

using namespace std;

void Database::Add(const Date& date, const std::string& event)
{
	auto res = events[date].elements.insert(event);
	if (res.second)
		events[date].order.push_back(event);
}

void Database::Print(ostream& os) const
{
	for (auto i : events)
		for (auto j : i.second.order)
			os << i.first << " " << j;
}