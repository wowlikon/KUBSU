#include <iostream>
#include <string>
#include <clocale>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int rgcd(int n, int m);
int igcd(int n, int m);

int main() {
    int n, m;
    setlocale(0, "Russian");

    do { cout << "\033[A\033[2K\rN: ";
    cin >> n;} while (n <= 0);

    cout << "N: " << n << endl;

    do { cout << "\033[A\033[2K\rM: ";
    cin >> m;} while (m <= 0);

    cout << "НОД(" << n << ", " << m << ") = " << rgcd(n, m) << endl;
    cout << "НОД(" << n << ", " << m << ") = " << igcd(n, m) << endl;
    return 0;
}

int rgcd(int n, int m) { // Recursive Greatest Common Divisor
         if (m%n == 0) return n;
    else if (n%m == 0) return m;
    else return rgcd(m%n, n);
}

int igcd(int n, int m) { // Iterative Greatest Common Divisor
    while (m != 0) {
        int temp = m;
        m = n%m; n = temp;
    }
    return n;
}
