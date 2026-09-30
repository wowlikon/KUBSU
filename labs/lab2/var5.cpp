#include <math.h>
#include <iostream>

using namespace std;

double f(double x, int func) {
    switch (func) {
        case 1:
            return sinh(x);
        case 2:
            return pow(x, 2);
        case 3:
            return exp(x);
        default:
            return 0.0;
    }
}

int main() {
    uint f;
    double x, y, z;
    double a, b, c;

    cout << "Functions:";
    cout << "1. f(x) = sh(x)" << endl;
    cout << "2. f(x) = x^2" << endl;
    cout << "3. f(x) = e^x" << endl;
    cout << "Select function:"; cin >> f;

    cout << "X:"; cin >> x;
    cout << "Y:"; cin >> y;

    a = pow(y, -sqrt(fabs(x)));
    b = x - (y/2);
    c = pow(sin(atan(z)), 2);

    cout << "Result: " << (log(a)*b+c) << endl;
    return 0;
}
