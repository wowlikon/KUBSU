#include <iostream>

using namespace std;

int main() {
    double c;

    cout << "Enter celsius temperature: " << endl;
    cout << "t: ";
    cin >> c;

    cout << "F = " << c * 9 / 5 + 32 << endl;
    return 0;
}
