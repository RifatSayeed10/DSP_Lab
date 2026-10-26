
#include <iostream>
using namespace std;

int main() {
    int size, start;

    double x[201] = {0};
    double even[401] = {0};
    double odd[401] = {0};

    cout << "Enter signal size: ";
    cin >> size;

    cout << "Enter starting index: ";
    cin >> start;

    if (size < 1 || size > 100) {
        cout << "Invalid size";
        return 0;
    }

    cout << "Enter signal values: ";
    for (int i = 0; i < size; i++) {
        cin >> x[i];
    }

    int end = start + size - 1;

    int new_start = min(start, -end);
    int new_end = max(end, -start);

    cout << "\nn\tEven\tOdd\n";

    for (int n = new_start; n <= new_end; n++) {
        double xn = 0, xneg = 0;

        if (n >= start && n <= end) {
            xn = x[n - start];
        }

        if (-n >= start && -n <= end) {
            xneg = x[-n - start];
        }

        double even = (xn + xneg) / 2.0;
        double odd = (xn - xneg) / 2.0;

        cout << n << "\t" << even
             << "\t" << odd << endl;
    }

    return 0;
}
