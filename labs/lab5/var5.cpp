#include <algorithm>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::vector;

int main() {
    int min, max, k;
    setlocale(0, "Russian");

    cout << "Диапазон: "; cin >> min;
    do {
        cout << "\033[A\033[2K\rДиапазон: "
            << min << " - "; cin >> max;
    } while (min > max);

    do {
        cout << "\033[A\033[2K\rВведите k:"; cin >> k;
    } while (k <= 0);

    vector<int> array, unique;

    for (int i=0; i < k; i++) {
        int value = rand() % (max - min + 1) + min;

        if (find(array.begin(), array.end(), value) == array.end())
            unique.push_back(value);

        array.push_back(value);

    }

    cout << "A[ "; for (int n : array ) cout << n << " "; cout << "]" << endl;
    cout << "U[ "; for (int n : unique) cout << n << " "; cout << "]" << endl;

    return 0;
}
