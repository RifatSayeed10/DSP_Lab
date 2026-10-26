/* Problem 04: Amplitude scaling.
 * Logic: y[i] = x[i] * factor. Uses correct float format specifier.
 */
#include <stdio.h>
#define MAX 100

int main(void) {
    int x_size, i;
    float x[MAX], y[MAX], factor;

    printf("Enter number of samples of signal: ");
    if (scanf("%d", &x_size) != 1 || x_size < 1 || x_size > MAX) return 1;

    printf("Enter the samples of signal:\n");
    for (i = 0; i < x_size; i++) {
        printf("Enter sample: ");
        if (scanf("%f", &x[i]) != 1) return 1;
    }
    printf("Enter the amplitude factor: ");
    if (scanf("%f", &factor) != 1) return 1;

    for (i = 0; i < x_size; i++) y[i] = x[i] * factor;

    printf("\nOriginal signal samples: ");
    for (i = 0; i < x_size; i++) printf("%.2f ", x[i]);
    printf("\nResultant signal samples after amplitude scaling: ");
    for (i = 0; i < x_size; i++) printf("%.2f ", y[i]);
    printf("\n");
    return 0;
}
