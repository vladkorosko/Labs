#pragma once
#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include "matrix.h"

const std::string red = "\u001B[31m";
const std::string green = "\u001B[32m";
const std::string yellow = "\u001B[33m";
const std::string blue = "\u001B[34m";
const std::string white = "\u001B[37m";

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u,
    const std::string& hint)
{
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u
            << " hint: " << hint;
        throw std::runtime_error(os.str());
    }
}

inline void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();
            std::cerr << green << test_name << " OK" << std::endl;
        }
        catch (std::runtime_error& e) {
            ++fail_count;
            std::cerr << red << test_name << " fail: " << e.what() << std::endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cerr << red << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};