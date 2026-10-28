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
#include <memory>
#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include "DVD.h"
#include "Research.h"

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

using namespace std;

class Manager {
private:
    vector<unique_ptr<Library>> items;
public:
    void add(unique_ptr<Library> item);
    void display_all() const;
    Library* find(int id);
    void deletee(int id);
    void borrow(int id, const string& b);
    void returnn(int id, int meow);
    void report() const;
    void sort_year();
    void sort_title();
    void save(const string& name) const;
    void load(const string& name);
    void search_id(int id) const;
    void search_title(const string& title) const;
    void search_type(const string& type) const;
};
#endif
