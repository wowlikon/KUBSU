#include <algorithm>
#include <clocale>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::count;
using std::string;
using std::vector;

vector<string> src;

int main() {
    setlocale(0, "Russian");
    cerr << "Для выхода введите 'q'" << endl;

    string last = "";
    while (cin >> last) {
        if (last == "q") break;
        if (last.length() % 2 == 1) src.push_back(last);
    }

    for (auto item : src)
        cout << item << " - " << count(item.begin(), item.end(), '1') << endl;

    return 0;
}
