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
#include "Book.h"

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

Book::Book(
    int id, const string& title, const string& author, int year, int pages, const string& genre, bool ch
)
: Library(
    id, year, title, author, ch
)
{
    this->pages = pages;
    this->genre = genre;
}
string Book::get_type() const {
    return "book";
}
void Book::display() const {
    cout << "book" << endl << "id: " << id << endl << "title: " << title << endl << "author: " << creator << endl << "year: " << year << endl << "pages: " << pages << endl << "genre: " << genre << endl << "status: " << (ch ? "avalible" : "borrowed") << endl;
}

double Book::calculate(int meow) const {
    return meow * 0.5;
}
void Book::save(ofstream& out) const {
    out << "book|" << id << "|" << title << "|" << creator << "|" << year << "|" << ch << "|" << pages << "|" << genre << endl;
}
