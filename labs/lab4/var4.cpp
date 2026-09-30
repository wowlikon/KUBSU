#include <clocale>
#include <cmath>
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main() {
    int n, i;
    double a, b, h, x, y, s, p;

    setlocale(LC_ALL, "Russian");
    cout << "Диапазон: "; cin >> a;
    do {
        cout << "\033[A\033[2K\rДиапазон: " << a << " - ";
        cin >> b;
    } while (a > b);
    cout << "\033[A\033[2K\rДиапазон: " << a << " - " << b << endl;
    cout << "N: "; cin >> n;

    x = a;
    h = (b - a) / 10;
    cout << setw(15) << "x" << setw(15) << "y(x)" << setw(15) << "s(x)" << endl;
    do {
        s = p = 1;
        for (i = 1; i <= n; i++) {
            // a_k = a_{k-1} * (-x^2) / ((2k-1)*(2k))
            p *= -x * x / ((2.0 * i - 1) * (2.0 * i));
            s += p;
        }

        y = cos(x);
        cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
        x += h;
    } while (x <= b + h / 2);
    return 0;
}
