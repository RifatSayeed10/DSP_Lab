// Problem 09: Circular convolution using the Matrix Method.
// Same logic as C: construct circulant matrix from x2, then multiply by x1.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MAX = 100;
    int x1_size, x2_size, y_size;

    cout << "Enter number of first signal samples: ";
    if (!(cin >> x1_size) || x1_size < 1 || x1_size > MAX) return 1;
    cout << "Enter number of second signal samples: ";
    if (!(cin >> x2_size) || x2_size < 1 || x2_size > MAX) return 1;
    y_size = (x1_size > x2_size) ? x1_size : x2_size;

    vector<int> x1(y_size, 0), x2(y_size, 0), y(y_size, 0);
    vector<vector<int>> matrix(y_size, vector<int>(y_size, 0));
    cout << "Enter first signal sequences:\n";
    for (int i = 0; i < x1_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> x1[i])) return 1;
    }
    cout << "Enter second signal sequences:\n";
    for (int i = 0; i < x2_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> x2[i])) return 1;
    }

    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < y_size; j++) {
            matrix[i][j] = x2[(i - j + y_size) % y_size];
        }
    }

    cout << "\nCirculant Matrix (from second signal):\n";
    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < y_size; j++) cout << matrix[i][j] << "\t";
        cout << "\n";
    }

    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < y_size; j++) {
            y[i] += matrix[i][j] * x1[j];
        }
    }
    cout << "\nResult of Circular Convolution: ";
    for (int i = 0; i < y_size; i++) cout << y[i] << " ";
    cout << "\n";
    return 0;
}
