// Problem 05: Even and odd components.
// Same logic as C: xe[n] = (x[n]+x[-n])/2; xo[n] = (x[n]-x[-n])/2.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int sample_at(const vector<int>& x, int ns, int ne, int n) {
    if (n < ns || n > ne) return 0;
    return x[n - ns];
}

int main() {
    const int MAX = 100;
    int x_size, org, ns, ne, L;
    cout << "Enter number of samples of signal: ";
    if (!(cin >> x_size) || x_size < 1 || x_size > MAX) return 1;

    vector<int> x(x_size);
    cout << "Enter the samples of signal:\n";
    for (int i = 0; i < x_size; i++) {
        cout << "Enter sample: ";
        if (!(cin >> x[i])) return 1;
    }
    cout << "Enter the sample no. which is the origin (1 to " << x_size << "): ";
    if (!(cin >> org) || org < 1 || org > x_size) return 1;

    ns = -(org - 1);
    ne = ns + x_size - 1;
    L = (-ns > ne) ? -ns : ne;
    vector<double> xe(2 * L + 1, 0.0), xo(2 * L + 1, 0.0);

    for (int n = -L; n <= L; n++) {
        xe[n + L] = (sample_at(x, ns, ne, n) + sample_at(x, ns, ne, -n)) / 2.0;
        xo[n + L] = (sample_at(x, ns, ne, n) - sample_at(x, ns, ne, -n)) / 2.0;
    }

    cout << "\nOriginal signal:\n";
    for (int i = 0; i < x_size; i++) cout << "x[" << ns + i << "] = " << x[i] << "\n";
    cout << fixed << setprecision(1);
    cout << "\nEven component:\n";
    for (int n = -L; n <= L; n++) cout << "xe[" << n << "] = " << xe[n + L] << "\n";
    cout << "\nOdd component:\n";
    for (int n = -L; n <= L; n++) cout << "xo[" << n << "] = " << xo[n + L] << "\n";
    cout << "\nVerification (xe + xo = x):\n";
    for (int n = -L; n <= L; n++) {
        cout << "n=" << n << " : " << xe[n + L] << " + " << xo[n + L]
             << " = " << xe[n + L] + xo[n + L] << "\n";
    }
    return 0;
}
