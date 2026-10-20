#include <clocale>
#include <cmath>
#include <math.h>
#include <iostream>
#include <iomanip>

using std::exp;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main() {
    int n, i;
    double a, b, h, x, y, p, s;

    setlocale(LC_ALL, "Russian");
    cout << "Диапазон: "; cin >> a;
    do {
        cout << "\033[A\033[2K\rДиапазон: " << a << " - ";
        cin >> b;
    } while (a > b);
    cout << "\033[A\033[2K\rДиапазон: " << a << " - " << b << endl;
    cout << "N: "; cin >> n;

    x = a;
    h = (b-a) / 10;
    cout << setw(15) << "x" << setw(15) << "y(x)" << setw(15) << "s(x)" << endl;
    do {
        p = s = 1;
        for (i = 1; i <= n; i++) {
            p *= pow(x, 2) / i;
            s += (2 * i + 1) * p;
        }

        y = (1 + 2 * pow(x, 2))*exp(pow(x, 2));
        cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
        x += h;
    } while (x <= b+h/2);
    return 0;
}
