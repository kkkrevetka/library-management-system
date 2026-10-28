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
#include "DVD.h"

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

DVD::DVD(
    int id, const string& title, const string& director, int year, int duration, const string& age, bool ch
)
: Library(
    id, year, title, director, ch
)
{
    this->duration = duration;
    this->age = age;
}
string DVD::get_type() const {
    return "dvd";
}
void DVD::display() const {
    cout << "dvd" << endl << "id: " << id << endl << "title: " << title << endl << "director: " << creator << endl << "year: " << year << endl << "duration: " << duration << endl << "age rating: " << age << endl << "status: " << (ch ? "available" : "borrowed") << endl;
}
double DVD::calculate(int meow) const {
    return meow * 1.0;
}
void DVD::save(ofstream& out) const {
    out << "dvd|" << id << "|" << title << "|" << creator << "|" << year << "|" << ch << "|" << duration << "|" << age << endl;
}
