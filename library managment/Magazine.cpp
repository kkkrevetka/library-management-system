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
#include "Magazine.h"

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

Magazine::Magazine(
    int id, const string& title, const string& autor, int year, int issue, const string& month, bool ch
)
: Library(
    id, year, title, autor, ch
)
{
    this->issue = issue;
    this->month = month;
}
string Magazine::get_type() const {
    return "magazine";
}
void Magazine::display() const {
    cout << "magazine" << endl << "id: " << id << endl << "title: " << title << endl << "autor: " << creator << endl << "year: " << year << endl << "issue: " << issue << endl << "month: " << month << endl << "status: " << (ch ? "available" : "borrowed") << endl;
}
double Magazine::calculate(int meow) const {
    return meow * 0.3;
}
void Magazine::save(ofstream& out) const {
    out << "magazine|" << id << "|" << title << "|" << creator << "|" << year << "|" << ch << "|" << issue << "|" << month << endl;
}
