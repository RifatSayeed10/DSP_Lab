// Problem 02: Addition of two discrete-time signals.
// Same logic as C: zero-pad shorter signal and add sample by sample.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MAX = 100;
    int x_size, y_size, z_size;

    cout << "Enter number of samples of first signal: ";
    if (!(cin >> x_size) || x_size < 1 || x_size > MAX) return 1;
    cout << "Enter number of samples of second signal: ";
    if (!(cin >> y_size) || y_size < 1 || y_size > MAX) return 1;

    if (x_size > y_size) z_size = x_size;
    else z_size = y_size;

    vector<int> x(z_size, 0), y(z_size, 0), z(z_size, 0);

    cout << "Enter the samples of first signal:\n";
    for (int i = 0; i < x_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> x[i])) return 1;
    }
    cout << "Enter the samples of second signal:\n";
    for (int i = 0; i < y_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> y[i])) return 1;
    }

    for (int i = 0; i < z_size; i++) z[i] = x[i] + y[i];

    cout << "\nFirst signal samples: ";
    for (int i = 0; i < x_size; i++) cout << x[i] << " ";
    cout << "\nSecond signal samples: ";
    for (int i = 0; i < y_size; i++) cout << y[i] << " ";
    cout << "\nResultant signal samples: ";
    for (int i = 0; i < z_size; i++) cout << z[i] << " ";
    cout << "\n";
    return 0;
}
