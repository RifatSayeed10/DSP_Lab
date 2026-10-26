
#include <iostream>
using namespace std;

int main() {
    int y_size, h_size;

    cout << "Enter size of y: ";
    cin >> y_size;

    cout << "Enter size of h: ";
    cin >> h_size;

    double y[100] = {0};
    double h[100] = {0};
    double x[100] = {0};

    cout << "Enter y values: ";
    for (int i = 0; i < y_size; i++) {
        cin >> y[i];
    }

    cout << "Enter h values: ";
    for (int i = 0; i < h_size; i++) {
        cin >> h[i];
    }

    if (y_size < h_size || h_size <= 0 || y_size > 100 || h[0] == 0) {
        cout << "Invalid input";
        return 0;
    }

    int x_size = y_size - h_size + 1;

    for (int i = 0; i < x_size; i++) {
        double sum = 0;

        for (int j = 0; j < i; j++) {
            sum += x[j] * h[i-j];
        }

        x[i] = (y[i] - sum) / h[0];
    }

    cout << "Deconvolution result: ";
    for (int i = 0; i < x_size; i++) {
        cout << x[i] << " ";
    }

    return 0;
}
