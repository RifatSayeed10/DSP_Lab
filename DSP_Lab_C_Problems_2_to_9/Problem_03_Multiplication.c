/* Problem 03: Multiplication of two discrete-time signals.
 * Logic: pad shorter signal with zeros, then multiply sample-by-sample.
 */
#include <stdio.h>
#define MAX 100

int main(void) {
    int x_size, y_size, z_size, i;
    int x[MAX] = {0}, y[MAX] = {0}, z[MAX] = {0};

    printf("Enter number of samples of first signal: ");
    if (scanf("%d", &x_size) != 1 || x_size < 1 || x_size > MAX) return 1;
    printf("Enter number of samples of second signal: ");
    if (scanf("%d", &y_size) != 1 || y_size < 1 || y_size > MAX) return 1;

    if (x_size > y_size) z_size = x_size;
    else z_size = y_size;

    printf("Enter the samples of first signal:\n");
    for (i = 0; i < x_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &x[i]) != 1) return 1;
    }
    printf("Enter the samples of second signal:\n");
    for (i = 0; i < y_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &y[i]) != 1) return 1;
    }

    for (i = 0; i < z_size; i++) z[i] = x[i] * y[i];

    printf("\nFirst signal samples: ");
    for (i = 0; i < x_size; i++) printf("%d ", x[i]);
    printf("\nSecond signal samples: ");
    for (i = 0; i < y_size; i++) printf("%d ", y[i]);
    printf("\nResultant signal samples after multiplication: ");
    for (i = 0; i < z_size; i++) printf("%d ", z[i]);
    printf("\n");
    return 0;
}
