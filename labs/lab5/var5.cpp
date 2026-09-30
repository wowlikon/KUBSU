#include <clocale>
#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
    setlocale(0, "Russian");

    double a,b,h,x,y,s,p;
    int n,i;

    std::cout << "Введите a,b,h,n" << std::endl;
    std::cin >> a >> b >> h >> n;
    x=a;

    do
    {
        p = s = 1;
        for (i=1; i<=n; i++) {
            p *= log(9)*x/i;
            s += p;
        }
        y=pow(9,x);
        std::cout << std::setw(15) << x << std::setw(15) << y << std::setw(15) << s << std::endl;
        x += h;
    } while (x <= b+h/2);

    std::cout << std::endl;
    return 0;
}
