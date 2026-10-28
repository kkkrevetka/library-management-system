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
#include <limits>
#include "Manager.h"

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

signed main() {
    ifstream file("library_management_test_data.txt");
    if (!file.is_open()) {
        cout << "Warning: Could not open library_management_test_data.txt" << endl << "Check the working directory in Xcode." << endl;
    } else {
        cout << "===== TEST DATA =====" << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        cout << "===== END OF TEST DATA =====" << endl;
    }
    Manager manager;
    try {
        manager.load("library_management_test_data.txt");
    } catch (const exception& e) {
        cout << "loading error: " << e.what() << endl;
    }
    int com = -1;
    while (com != 0) {
        cout << "===== LIBRARY SYSTEM =====" << endl << "1. display all items" << endl << "2. dearch by id" << endl << "3. search by title" << endl << "4. search by type" << endl << "5. sort by year" << endl << "6. sort by title" << endl << "7. report" << endl << "8. save" << endl << "9. load" << endl << "0. exit" << endl << "choice: ";
        if (!(cin >> com)) {
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), endl);
            continue;
        }
        if (com == 1) {
            manager.display_all();
        } else if (com == 2) {
            int id;
            cout << "enter id: ";
            if (cin >> id) {
                manager.search_id(id);
            } else {
                cout << "invalid id" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), endl);
            }
        } else if (com == 3) {
            string title;
            cin.ignore(numeric_limits<streamsize>::max(), endl);
            cout << "enter title: ";
            getline(cin, title);
            manager.search_title(title);
        } else if (com == 4) {
            string type;
            cin.ignore(numeric_limits<streamsize>::max(), endl);
            cout << "enter type: ";
            getline(cin, type);
            manager.search_type(type);
        } else if (com == 5) {
            manager.sort_year();
            cout << "sorted by year" << endl;
        } else if (com == 6) {
            manager.sort_title();
            cout << "sorted by title" << endl;
        } else if (com == 7) {
            manager.report();
        } else if (com == 8) {
            manager.save("library_management_test_data.txt");
            cout << "save operation requested" << endl;
        } else if (com == 9) {
            manager.load("library_management_test_data.txt");
            cout << "load operation requested" << endl;
        } else if (com == 0) {
            cout << "exiting library system..." << endl;
        } else {
            cout << "unknown command" << endl;
        }
    }
    return 0;
}
