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
#include "Research.h"

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

Research::Research(
    int id, const string& title, const string& author, int year, const string& journal, const string& doi, bool ch
)
: Library(
    id, year, title, author, ch
)
{
    this->journal = journal;
    this->doi = doi;
}

string Research::get_type() const {
    return "research";
}
void Research::display() const {
    cout << "Research" << endl << "id: " << id << endl << "title: " << title << endl << "author: " << creator << endl << "year: " << year << endl << "journal: " << journal << endl << "DOI: " << doi << endl << "status: " << (ch ? "available" : "borrowed") << endl;
}
double Research::calculate(int meow) const {
    return meow * 0.2;
}
void Research::save(ofstream& out) const {
    out << "research|" << id << "|" << title << "|" << creator << "|" << year << "|" << ch << "|" << journal << "|" << doi << endl;
}
