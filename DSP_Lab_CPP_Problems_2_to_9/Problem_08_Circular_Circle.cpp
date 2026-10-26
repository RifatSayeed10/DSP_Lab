// Problem 08: Circular convolution using the Circle Method.
// Same logic as C: traverse samples with wraparound (no built-in convolution).
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
        int temp = i;
        for (int j = 0; j < y_size; j++) {
            y[i] += x1[j] * x2[temp];
            temp--;
            if (temp < 0) temp = y_size - 1;
        }
    }

    cout << "\nCircular convolution result: ";
    for (int i = 0; i < y_size; i++) cout << y[i] << " ";
    cout << "\n";
    return 0;
}
