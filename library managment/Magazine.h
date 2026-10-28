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
#include "Library.h"

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#ifndef MAGAZINE_H
#define MAGAZINE_H

using namespace std;

class Magazine : public Library {
private:
    int issue;
    string month;
public:
    Magazine(
        int id, const string& title, const string& publisher, int year, int issue, const string& month, bool ch = true
    );
    string get_type() const override;
    void display() const override;
    double calculate(int overdueDays) const override;
    void save(ofstream& out) const override;
};
#endif
