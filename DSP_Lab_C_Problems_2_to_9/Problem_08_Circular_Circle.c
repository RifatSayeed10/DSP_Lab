/* Problem 08: Circular convolution using Circle Method.
 * Logic: y[i] = sum_j x1[j] * x2[(i-j) mod N] with wraparound.
 */
#include <stdio.h>
#define MAX 100

int main(void) {
    int x1_size, x2_size, y_size, i, j, temp;
    int x1[MAX] = {0}, x2[MAX] = {0}, y[MAX] = {0};

    printf("Enter number of first signal samples: ");
    if (scanf("%d", &x1_size) != 1 || x1_size < 1 || x1_size > MAX) return 1;
    printf("Enter number of second signal samples: ");
    if (scanf("%d", &x2_size) != 1 || x2_size < 1 || x2_size > MAX) return 1;
    y_size = (x1_size > x2_size) ? x1_size : x2_size;

    printf("Enter first signal sequences:\n");
    for (i = 0; i < x1_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &x1[i]) != 1) return 1;
    }
    printf("Enter second signal sequences:\n");
    for (i = 0; i < x2_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &x2[i]) != 1) return 1;
    }

    for (i = 0; i < y_size; i++) {
        temp = i;
        for (j = 0; j < y_size; j++) {
            y[i] += x1[j] * x2[temp];
            temp--;
            if (temp < 0) temp = y_size - 1;
        }
    }

    printf("\nCircular convolution result: ");
    for (i = 0; i < y_size; i++) printf("%d ", y[i]);
    printf("\n");
    return 0;
}
