
#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter size of x: ";
    cin >> n;

    cout << "Enter size of h: ";
    cin >> m;

    int x[100] = {0};
    int h[100] = {0};
    int y[200] = {0};

    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter h values: ";
    for (int i = 0; i < m; i++) {
        cin >> h[i];
    }

    int y_size = n + m - 1;

    for (int i = 0; i < y_size; i++) {
        y[i] = 0;

        for (int j = 0; j <= i; j++) {
            y[i] = y[i] + x[j] * h[i-j];
        }
    }

    cout << "Convolution result: ";
    for (int i = 0; i < y_size; i++) {
        cout << y[i] << " ";
    }

    return 0;
}
