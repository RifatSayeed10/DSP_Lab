
#include <iostream>
using namespace std;

int main() {
    int n, m;
    int x[100] = {0}, h[100] = {0};
    int y[200] = {0};

    cout << "Enter size of x: ";
    cin >> n;

    cout << "Enter size of h: ";
    cin >> m;

    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter h values: ";
    for (int i = 0; i < m; i++) {
        cin >> h[i];
    }

    int size = (n > m) ? n : m;

    for (int i = 0; i < size; i++) {
        y[i] = x[i] + h[i];
    }

    cout << "Addition Result: ";
    for (int i = 0; i < size; i++) {
        cout << y[i] << " ";
    }

    return 0;
}
