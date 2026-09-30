#include <iostream>

using namespace std;

int main() {
    int a, b;

    cout << "Enter two integers: " << endl;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;

    cout << "A+B = " << a + b << endl;
    cout << "A-B = " << a - b << endl;
    cout << "A*B = " << a * b << endl;
    cout << "A/B = " << a / b << endl; // деление int возвращает целую часть
    return 0;
}
