/* Problem 07: Linear deconvolution.
 * Logic: recursive division using the first impulse-response sample.
 * Extra check: reconvolve and warn if supplied y is inconsistent.
 */
#include <stdio.h>
#include <math.h>
#define MAX 100
#define OUT_MAX (2 * MAX - 1)

int main(void) {
    int y_size, h_size, x_size, i, j, temp, y_o, h_o, x_o;
    int y[OUT_MAX] = {0}, h[OUT_MAX] = {0};
    double x[OUT_MAX] = {0};
    int verified = 1;

    printf("Enter number of output samples: ");
    if (scanf("%d", &y_size) != 1 || y_size < 1 || y_size > OUT_MAX) return 1;
    printf("Enter number of impulses: ");
    if (scanf("%d", &h_size) != 1 || h_size < 1 || h_size > MAX) return 1;
    x_size = y_size - h_size + 1;
    if (x_size < 1 || x_size > MAX) {
        printf("Invalid sequence lengths.\n");
        return 1;
    }

    printf("Enter output sequences:\n");
    for (i = 0; i < y_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &y[i]) != 1) return 1;
    }
    printf("Enter impulse sequences:\n");
    for (i = 0; i < h_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &h[i]) != 1) return 1;
    }
    if (h[0] == 0) {
        printf("Deconvolution not possible: h[0] is zero.\n");
        return 1;
    }
    printf("Enter starting index of y(n): ");
    if (scanf("%d", &y_o) != 1) return 1;
    printf("Enter starting index of h(n): ");
    if (scanf("%d", &h_o) != 1) return 1;
    x_o = y_o - h_o;

    for (i = 0; i < x_size; i++) {
        double total = 0.0;
        temp = i;
        for (j = 0; j < i; j++) {
            total += x[j] * h[temp];
            temp--;
        }
        x[i] = (y[i] - total) / h[0];
    }

    printf("\nSample values of input: ");
    for (i = 0; i < x_size; i++) printf("%.2f ", x[i]);
    printf("\nStarting index of input: %d\n", x_o);

    for (i = 0; i < y_size; i++) {
        double computed = 0.0;
        for (j = 0; j < x_size; j++) {
            int k = i - j;
            if (k >= 0 && k < h_size) computed += x[j] * h[k];
        }
        if (fabs(computed - y[i]) > 1e-6) { verified = 0; break; }
    }
    if (!verified) printf("Warning: y(n) and h(n) do not match exact linear convolution.\n");
    return 0;
}
