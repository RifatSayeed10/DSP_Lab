# Problem 06: Linear convolution
# Same nested-loop logic as GitHub's 5_linear_convolution.c.

x_size = int(input("Enter number of samples of x(n): "))
h_size = int(input("Enter number of samples of h(n): "))
if x_size <= 0 or h_size <= 0:
    raise ValueError("Number of samples must be positive.")

y_size = x_size + h_size - 1
x = [0] * y_size
h = [0] * y_size
y = [0] * y_size

print("Enter sample values of x(n):")
for i in range(x_size):
    x[i] = int(input("Enter sample: "))

print("Enter sample values of h(n):")
for i in range(h_size):
    h[i] = int(input("Enter sample: "))

x_o = int(input("Enter starting index of x(n) [n value of 1st sample]: "))
h_o = int(input("Enter starting index of h(n) [n value of 1st sample]: "))
y_o = x_o + h_o

for i in range(y_size):
    y[i] = 0
    for j in range(i + 1):
        y[i] = y[i] + x[j] * h[i - j]

print("\nSample values of output:", *y)
print("Starting index of output:", y_o)
