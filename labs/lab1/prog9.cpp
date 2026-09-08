#include <iostream>

using namespace std; // использование стандартного пространства имен (чтобы убрать std::)

int main() {
    double c; // инициализация дробной переменной

    cout << "Enter celsius temperature: " << endl;
    cout << "t: ";
    cin >> c; // ввод значения

    cout << "F = " << c * 9 / 5 + 32 << endl; // вывод результата
    return 0;
}
