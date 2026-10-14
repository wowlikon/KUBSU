#include <clocale>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;

constexpr uint rand_min = 0;
constexpr uint rand_max = 10;

void show_data_matrix(int** data_matrix, int m, int n) {
    // ┌    ┐
    // │    │
    // └    ┘
    cout << "┌" << string(4*n + 2, ' ') << "┐" << endl;
    for (int i = 0; i < m; i++) {
        cout << "│ ";
        for (int j = 0; j < n; j++) {
            cout << setw(4) << data_matrix[j][i];
        }
        cout << " │" << endl;
    }
    cout << "└" << string(4*n + 2, ' ') << "┘" << endl;
}

int main() {
    setlocale(0, "Russian");
    cout << endl;
    int m, n;

    do { cout << "\033[A\033[2K\rРазмер матрицы: "; cin >> m;
    } while (m <= 0);

    do { cout << "\033[A\033[2K\rРазмер матрицы: " << m << "x"; cin >> n;
    } while (n <= 0);

    int **data_matrix;
    uint special_count = 0;
    data_matrix = new int*[n];
    for(int i=0; i<n; i++) data_matrix[i] = new int[m];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            data_matrix[j][i] = rand()
                % (rand_max - rand_min + 1) + rand_min;
        }
    }

    show_data_matrix(data_matrix, m, n);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            bool is_special = true;

            for (int l = 0; l < i; l++) {
                if (data_matrix[l][j] >= data_matrix[i][j]) {
                    is_special = false; break;
                }
            }

            for (int l = i + 1; l < n; l++) {
                if (data_matrix[l][j] <= data_matrix[i][j]) {
                    is_special = false; break;
                }
            }

            if (is_special) ++special_count;
        }
    }

    cout << "Магических чисел: "
         << special_count << endl;

    for(int i=0; i<n; i++) delete []data_matrix[i];
    delete []data_matrix;
    data_matrix=nullptr;
    return 0;
}
