// Problem 06: Linear convolution.
// Same logic as C: zero-padding and y[i] += x[j] * h[i-j].
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MAX = 100;
    int x_size, h_size, y_size, x_o, h_o, y_o;

    cout << "Enter number of samples of x(n): ";
    if (!(cin >> x_size) || x_size < 1 || x_size > MAX) return 1;
    cout << "Enter number of samples of h(n): ";
    if (!(cin >> h_size) || h_size < 1 || h_size > MAX) return 1;

    y_size = x_size + h_size - 1;
    vector<int> x(y_size, 0), h(y_size, 0), y(y_size, 0);
    cout << "Enter sample values of x(n):\n";
    for (int i = 0; i < x_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> x[i])) return 1;
    }
    cout << "Enter sample values of h(n):\n";
    for (int i = 0; i < h_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> h[i])) return 1;
    }
    cout << "Enter starting index of x(n) [n value of 1st sample]: ";
    if (!(cin >> x_o)) return 1;
    cout << "Enter starting index of h(n) [n value of 1st sample]: ";
    if (!(cin >> h_o)) return 1;
    y_o = x_o + h_o;

    for (int i = 0; i < y_size; i++) {
        y[i] = 0;
        for (int j = 0; j <= i; j++) {
            y[i] += x[j] * h[i - j];
        }
    }

    cout << "\nSample values of output: ";
    for (int i = 0; i < y_size; i++) cout << y[i] << " ";
    cout << "\nStarting index of output: " << y_o << "\n";
    return 0;
}
