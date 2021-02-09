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

string Database::Last(const Date& d) const
{
	auto it = upper_bound(events.begin(), events.end(), d);
	if (it == events.begin())
		return "No entries";
	else
	{
		it = prev(it);
		stringstream res;
		res << it->first << " " << it->second.order[it->second.order.size() - 1];
		return res.str();
	}
}