
#include <iostream>
using namespace std;

int main() {
    int n;
    float x[100], y[100], a;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter scaling factor: ";
    cin >> a;

    for (int i = 0; i < n; i++) {
        y[i] = a * x[i];
    }

    cout << "Scaled Signal: ";
    for (int i = 0; i < n; i++) {
        cout << y[i] << " ";
    }

    return 0;
}
