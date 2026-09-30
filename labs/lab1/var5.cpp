#include <math.h>
#include <iostream>

using namespace std;

int main() {
    double x, y, z;
    double a, b, c;

    cout << "X:"; cin >> x;
    cout << "Y:"; cin >> y;
    cout << "Z:"; cin >> z;

    a = pow(y, -sqrt(fabs(x)));
    b = x - (y/2);
    c = pow(sin(atan(z)), 2);

    cout << "Result: " << (log(a)*b+c) << endl;
    return 0;
}
