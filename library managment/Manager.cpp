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
#include <fstream>
#include <sstream>
#include "Manager.h"

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

void Manager::add(unique_ptr<Library> item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_id() == item->get_id()) {
            throw runtime_error("duplicate id");
        }
    }
    items.push_back(move(item));
}
void Manager::display_all() const {
    if (items.empty()) {
        cout << "library is empty" << endl;
        return;
    }
    for (int i = 0; i < items.size(); i++) {
        items[i]->display();
        cout << endl;
    }
}
Library* Manager::find(int id) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_id() == id) {
            return items[i].get();
        }
    }
    return nullptr;
}
void Manager::deletee(int id) {
    auto meow = remove_if(items.begin(), items.end(), [id](const unique_ptr<Library>& item) {
            return item->get_id() == id;
        }
    );
    if (meow == items.end()) {
        throw runtime_error("Item not found.");
    }
    items.erase(meow, items.end());
}
void Manager::borrow(int id, const string& b) {
    Library* item = find(id);
    if (!item) {
        throw runtime_error("item not found");
    }
    item->borrow(b);
    cout << "borrow successful" << endl;
}
void Manager::returnn(int id, int meow) {
    Library* item = find(id);
    if (!item) {
        throw runtime_error("item not found");
    }
    cout << "late fee: " << item->returnn(meow) << " gel" << endl;
}
void Manager::report() const {
    int available_count = 0, borrowed_count = 0, books = 0, magazines = 0, dvds = 0, papers = 0;
    for (int i = 0; i < items.size(); i++) {
        (items[i]->check()) ? available_count++ : borrowed_count++;
        if (items[i]->get_type() == "book") {
            books++;
        } else if (items[i]->get_type() == "magazine") {
            magazines++;
        } else if (items[i]->get_type() == "dvd") {
            dvds++;
        } else if (items[i]->get_type() == "research") {
            papers++;
        }
    }
    cout << "REPORT" << endl << "total items: " << items.size() << endl << "available: " << available_count << endl << "borrowed: " << borrowed_count << endl << "books: " << books << endl << "magazines: " << magazines << endl << "dvds: " << dvds << endl << "research: " << papers << endl;
}
void Manager::sort_year() {
    sort(items.begin(), items.end(), [](const unique_ptr<Library>& a, const unique_ptr<Library>& b) {
            return a->get_year() < b->get_year();
        });
}
void Manager::sort_title() {
    sort(items.begin(), items.end(), [](const unique_ptr<Library>& a, const unique_ptr<Library>& b) {
            return a->get_title() < b->get_title();
        });
}
void Manager::save(const string& name) const {
    ofstream out(name);
    if (!out) {
        throw runtime_error("can't open file");
    }
    for (int i = 0; i < items.size(); i++) {
        items[i]->save(out);
    }
    cout << "data saved" << endl;
}
void Manager::load(const string& name) {
    ifstream in(name);
    if (!in) {
        throw runtime_error("can't open file");
    }
    items.clear();
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        vector <string> fields;
        string meow;
        while (getline(ss, meow, '|')) {
            fields.push_back(meow);
        }
        string t = fields[0];
        if (t == "book") {
            int id = stoi(fields[1]), year = stoi(fields[4]), pages = stoi(fields[6]);
            string title = fields[2], author = fields[3], genre = fields[7];
            bool ch = stoi(fields[5]);
            items.push_back(make_unique<Book>(id, title, author, year, pages, genre, ch));
        } else if (t == "magazine") {
            int id = stoi(fields[1]), year = stoi(fields[4]), issue = stoi(fields[6]);
            string title = fields[2], publisher = fields[3], month = fields[7];
            bool ch = stoi(fields[5]);
            items.push_back(make_unique<Magazine>(id, title, publisher, year, issue, month, ch));
        } else if (t == "dvd") {
            int id = stoi(fields[1]), year = stoi(fields[4]), duration = stoi(fields[6]);
            string title = fields[2], director = fields[3], rating = fields[7];
            bool ch = stoi(fields[5]);
            items.push_back(make_unique<DVD>(id, title, director, year, duration,rating, ch));
        } else if (t == "research") {
            int id = stoi(fields[1]), year = stoi(fields[4]);
            string title = fields[2], author = fields[3], journal = fields[6], doi = fields[7];
            bool ch = stoi(fields[5]);
            items.push_back(make_unique<Research>(id, title, author, year, journal, doi, ch));
        }
    }
    cout << "data loaded" << endl;
}
void Manager::search_id(int id) const {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_id() == id) {
            items[i]->display();
            return;
        }
    }
    cout << "item not found" << endl;
}
void Manager::search_title(const string& title) const {
    bool found = false;
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_title().find(title) != string::npos) {
            items[i]->display();
            found = true;
        }
    }
    if (!found) {
        cout << "no matches found" << endl;
    }
}
void Manager::search_type(const string& type) const {
    bool found = false;
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_type() == type) {
            items[i]->display();
            found = true;
        }
    }
    if (!found) {
        cout << "no matches found" << endl;
    }
}
