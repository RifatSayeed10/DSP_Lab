
#include <iostream>
using namespace std;

int main()
{
    int i, j, x1_size, x2_size, y_size;

    cout << "Enter number of first signal samples: ";
    cin >> x1_size;

    cout << "Enter number of second signal samples: ";
    cin >> x2_size;

    if(x1_size > x2_size)
    {
        y_size = x1_size;
    }
    else
    {
        y_size = x2_size;
    }

    int x1[100], x2[100], y[100];
    int matrix[100][100];

    for(i = 0; i < y_size; i++)
    {
        x1[i] = 0;
        x2[i] = 0;
        y[i] = 0;
    }

    cout << "Enter first signal sequences: ";
    for(i = 0; i < x1_size; i++)
    {
        cin >> x1[i];
    }

    cout << "Enter second signal sequences: ";
    for(i = 0; i < x2_size; i++)
    {
        cin >> x2[i];
    }

    // Construct Circulant Matrix
    for(i = 0; i < y_size; i++)
    {
        for(j = 0; j < y_size; j++)
        {
            matrix[i][j] = x2[(i - j + y_size) % y_size];
        }
    }

    cout << "\nCirculant Matrix:\n";

    for(i = 0; i < y_size; i++)
    {
        for(j = 0; j < y_size; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    // Matrix Multiplication
    for(i = 0; i < y_size; i++)
    {
        for(j = 0; j < y_size; j++)
        {
            y[i] += matrix[i][j] * x1[j];
        }
    }

    cout << "\nResult of Circular Convolution:\n";

    for(i = 0; i < y_size; i++)
    {
        cout << y[i] << "  ";
    }

    cout << "\n";

    return 0;
}
