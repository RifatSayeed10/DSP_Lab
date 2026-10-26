# Problem 09: Circular convolution (Matrix Method)
# Same circulant matrix + matrix-vector multiplication as the GitHub C code.

x1_size = int(input("Enter number of first signal samples: "))
x2_size = int(input("Enter number of second signal samples: "))
if x1_size <= 0 or x2_size <= 0:
    raise ValueError("Number of samples must be positive.")

y_size = max(x1_size, x2_size)
x1 = [0] * y_size
x2 = [0] * y_size
y = [0] * y_size
matrix = [[0] * y_size for _ in range(y_size)]

print("Enter first signal sequences:")
for i in range(x1_size):
    x1[i] = int(input("Enter sample: "))

print("Enter second signal sequences:")
for i in range(x2_size):
    x2[i] = int(input("Enter sample: "))

for i in range(y_size):
    for j in range(y_size):
        matrix[i][j] = x2[(i - j + y_size) % y_size]

print("\nCirculant Matrix (from second signal):")
for i in range(y_size):
    for j in range(y_size):
        print(matrix[i][j], end="\t")
    print()

for i in range(y_size):
    for j in range(y_size):
        y[i] += matrix[i][j] * x1[j]

print("\nResult of Circular Convolution:", *y)
