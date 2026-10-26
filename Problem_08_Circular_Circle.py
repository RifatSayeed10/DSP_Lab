# Problem 08: Circular convolution (Circle Method)
# Same wrap-around nested-loop logic as GitHub's 7_Circle_circular_convolution.c.

x1_size = int(input("Enter number of first signal samples: "))
x2_size = int(input("Enter number of second signal samples: "))
if x1_size <= 0 or x2_size <= 0:
    raise ValueError("Number of samples must be positive.")

y_size = max(x1_size, x2_size)
x1 = [0] * y_size
x2 = [0] * y_size
y = [0] * y_size

print("Enter first signal sequences:")
for i in range(x1_size):
    x1[i] = int(input("Enter sample: "))

print("Enter second signal sequences:")
for i in range(x2_size):
    x2[i] = int(input("Enter sample: "))

for i in range(y_size):
    temp = i
    total = 0
    for j in range(y_size):
        total = total + x1[j] * x2[temp]
        temp -= 1
        if temp < 0:
            temp = y_size - 1
    y[i] = total

print("\nCircular convolution result:", *y)
