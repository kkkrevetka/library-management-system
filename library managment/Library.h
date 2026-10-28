//#pragma optimize GCC("03")
//#pragma optimize GCC("0fast")

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <string>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <random>
#include <fstream>
#include <stdexcept>

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

using namespace std;

const int INF = 2e9 + 333, inf = 3e4;

class Library {
protected:
    int id, year;
    string title, creator, name;
    bool ch;
public:
    Library(
        int id, int year, const string& title, const string& creator, bool ch = true
    );
    virtual ~Library();
    int get_id() const;
    string get_title() const;
    string get_creator() const;
    int get_year() const;
    bool check() const;
    void set(bool status);
    virtual string get_type() const = 0;
    virtual void display() const = 0;
    virtual double calculate(int overdueDays) const = 0;
    virtual void save(ofstream& out) const = 0;
    void borrow(const string& borrower);
    double returnn(int overdueDays);
    bool operator<(const Library& other) const;
    bool operator==(const Library& other) const;
    friend ostream& operator<<(ostream& out, const Library& item);
};
#endif
