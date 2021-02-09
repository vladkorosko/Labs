#include "node.h"

using namespace std;

bool EmptyNode::Evaluate(const Date & date, const string & event) 
{
    return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date)
    : cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) 
{
    Date d;
    stringstream s, s1;
    s << date;
    s1 << d;
    if (s.str() == s1.str()) 
        return false;
    return Compare(cmp_, date, date_);
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event)
    : cmp_(cmp), event_(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) 
{
    if (event.empty())
        return false;
    return Compare(cmp_, event, event_);
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation lo,
    shared_ptr<Node> left,
    shared_ptr<Node> right)
    : operation_(lo), left_(move(left)), right_(move(right)) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) 
{
    if (operation_ == LogicalOperation::And)
        return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    else if (operation_ == LogicalOperation::Or)
        return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    return false;
}