#include <cmath>
#include <math.h>
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::sqrt;
using std::runtime_error;

double func(uint func_type, double value) {
    switch (func_type) {
        case 1: return sinh(value);
        case 2: return pow(value, 2);
        case 3: return exp(value);
        default: throw runtime_error("Incorrect func type!");
    }
}

int main() {
    double x, y, v, result;

    {
        uint f;

        cout << "Functions:" << endl;
        cout << "1. f(x) = sh(x)" << endl;
        cout << "2. f(x) = x^2" << endl;
        cout << "3. f(x) = e^x" << endl;
        cout << "Select function:"; cin >> f;
        cout << endl; func(f, 1);

        cout << "X:"; cin >> x;
        cout << "Y:"; cin >> y;
        cout << endl; v = func(f, x);
    }

    if (x > y) result = y * sqrt(v) + 3 * sin(x);
    else if (x < y) result = sqrt(fabs(v));
    else result = pow(fabs(v), 1/3) + pow(x, 3) / y;

    cout << "Result: " << result << endl; return 0;
}
