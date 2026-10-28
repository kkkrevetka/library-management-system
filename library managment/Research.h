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
#ifndef RESEARCHPAPER_H
#define RESEARCHPAPER_H


using namespace std;

class Research: public Library {
private:
    string journal;
    string doi;
public:
    Research(
        int id, const string& title, const string& author, int year,const string& journal, const string& doi, bool ch = true
    );
    string get_type() const override;
    void display() const override;
    double calculate(int meow) const override;
    void save(ofstream& out) const override;
};
#endif
