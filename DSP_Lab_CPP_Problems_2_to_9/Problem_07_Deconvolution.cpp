// Problem 07: Linear deconvolution.
// Same logic as C: recursive division by h[0] and final reconvolution check.
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    const int MAX = 100;
    const int OUT_MAX = 2 * MAX - 1;
    int y_size, h_size, x_size, y_o, h_o, x_o;

    cout << "Enter number of output samples: ";
    if (!(cin >> y_size) || y_size < 1 || y_size > OUT_MAX) return 1;
    cout << "Enter number of impulses: ";
    if (!(cin >> h_size) || h_size < 1 || h_size > MAX) return 1;
    x_size = y_size - h_size + 1;
    if (x_size < 1 || x_size > MAX) {
        cout << "Invalid sequence lengths.\n";
        return 1;
    }

    vector<int> y(y_size, 0), h(y_size, 0);
    vector<double> x(x_size, 0.0);
    cout << "Enter output sequences:\n";
    for (int i = 0; i < y_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> y[i])) return 1;
    }
    cout << "Enter impulse sequences:\n";
    for (int i = 0; i < h_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> h[i])) return 1;
    }
    if (h[0] == 0) {
        cout << "Deconvolution not possible: h[0] is zero.\n";
        return 1;
    }
    cout << "Enter starting index of y(n): ";
    if (!(cin >> y_o)) return 1;
    cout << "Enter starting index of h(n): ";
    if (!(cin >> h_o)) return 1;
    x_o = y_o - h_o;

    for (int i = 0; i < x_size; i++) {
        double total = 0.0;
        int temp = i;
        for (int j = 0; j < i; j++) {
            total += x[j] * h[temp];
            temp--;
        }
        x[i] = (y[i] - total) / h[0];
    }

    cout << fixed << setprecision(2);
    cout << "\nSample values of input: ";
    for (int i = 0; i < x_size; i++) cout << x[i] << " ";
    cout << "\nStarting index of input: " << x_o << "\n";

    bool verified = true;
    for (int i = 0; i < y_size; i++) {
        double computed = 0.0;
        for (int j = 0; j < x_size; j++) {
            int k = i - j;
            if (k >= 0 && k < h_size) computed += x[j] * h[k];
        }
        if (fabs(computed - y[i]) > 1e-6) {
            verified = false;
            break;
        }
    }
    if (!verified) cout << "Warning: y(n) and h(n) do not match exact linear convolution.\n";
    return 0;
}
