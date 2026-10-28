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

using namespace std;

Library::Library(
    int id, int year, const string& title, const string& creator, bool ch
)
{
    this->id = id;
    this->title = title;
    this->creator = creator;
    this->year = year;
    this->ch = ch;
}
Library::~Library() {}
int Library::get_id() const {
    return id;
}
string Library::get_title() const {
    return title;
}
string Library::get_creator() const {
    return creator;
}
int Library::get_year() const {
    return year;
}
bool Library::check() const {
    return ch;
}
void Library::set(bool status) {
    ch = status;
}
void Library::borrow(const string& b) {
    if (!ch) {
        throw runtime_error("already borrowed");
    }
    ch = false;
    name = b;
}
double Library::returnn(int meow) {
    if (ch) {
        throw runtime_error("isn't borrowed");
    }
    ch = true;
    return calculate(meow);
}
bool Library::operator<(const Library& other) const {
    return year < other.year;
}
bool Library::operator==(const Library& other) const {
    return id == other.id;
}
ostream& operator<<(ostream& out, const Library& item) {
    out << item.get_type() << " | " << item.id << " | " << item.title;
    return out;
}
