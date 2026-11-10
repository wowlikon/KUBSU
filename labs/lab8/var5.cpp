#include <clocale>
#include <cmath>
#include <iostream>
#include <iomanip>

using std::asin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;

typedef double (*uf)(double, double, int&);

void tabl(double a, double b, double h, double eps, uf fun);
double y(double x, double eps, int &k);
double s(double x, double eps, int &k);

int main() {
    setlocale(LC_ALL, "Russian");

    double a = -1.0, b = 1.0;
    double h = (b - a) / 10.0;
    double eps = 1e-3;

    cout << "Function table" << endl;
    cout << setw(15) << "x" << setw(15) << "Y(x)" << setw(10) << "k" << endl;
    tabl(a, b, h, eps, y); cout << endl;
    tabl(a, b, h, eps, s); cout << endl;

    return 0;
}

void tabl(double a, double b, double h, double eps, uf fun) {
    int k = 0; double res;
    for (double x = a; x <= b + h / 2.0; x += h) {
        res = fun(x, eps, k);
        cout << res << setprecision(4) << setw(15) << x
             << setw(15) << res << setw(10) << k << endl;
    }
}

double y(double x, double eps, int &k) {
    k = 0; return asin(x) - x;
}


double s(double x, double eps, int &k) {
    double u = pow(x, 3) / 6.0;
    double sum = 0.0; k = 0;

    while (fabs(u) > eps && k < 100000) {
        sum += u; k++;
        u *= (x*x)-pow(2.0+(k + 1)-1.0, 2) / (2.0 * (k + 1) * (2.0 * (k + 1) + 1.0));
    }

    if (k==0 && fabs(u) <= eps) {
        sum = u; k = 1;
    }

    return sum;
}
