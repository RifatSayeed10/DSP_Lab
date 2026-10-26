// Problem 04: Amplitude scaling. Same logic as C: y[i] = x[i] * factor.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    const int MAX = 100;
    int x_size;
    float factor;

    cout << "Enter number of samples of signal: ";
    if (!(cin >> x_size) || x_size < 1 || x_size > MAX) return 1;

    vector<float> x(x_size), y(x_size);
    cout << "Enter the samples of signal:\n";
    for (int i = 0; i < x_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> x[i])) return 1;
    }
    cout << "Enter the amplitude factor: ";
    if (!(cin >> factor)) return 1;

    for (int i = 0; i < x_size; i++) y[i] = x[i] * factor;

    cout << fixed << setprecision(2);
    cout << "\nOriginal signal samples: ";
    for (int i = 0; i < x_size; i++) cout << x[i] << " ";
    cout << "\nResultant signal samples after amplitude scaling: ";
    for (int i = 0; i < x_size; i++) cout << y[i] << " ";
    cout << "\n";
    return 0;
}
