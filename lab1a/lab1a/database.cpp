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
			os << i.first << " " << j << endl;
}

std::string Database::Last(const Date& date) const {
	auto last = events.upper_bound(date);
	if (last == events.begin()) {
		return "No entries";
	}
	else 
	{
		last = prev(last);
		stringstream s;
		s << last->first << " " << last->second.order.back();
		return s.str();
	}
}