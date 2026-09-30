#include <clocale>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double x, y, z, a, b, c, h;

    setlocale(0, "");
    cout << "Введите X: "; cin >> x;
    cout << "Введите Y: "; cin >> y;
    cout << "Введите Z: "; cin >> z;

    a = pow(x, 2*y)+exp(y-1);
    b = 1+x*fabs(y-tan(z));
    c = 10*pow(x, 1/3.)-log(z);

    cout << "Ответ: " << (a/b+c) << endl;
    return 0;
}
