# Problem 03: Multiplication of two discrete-time signals
# Same logic as GitHub's 3_multiplcation.c: zero padding + sample-wise multiplication.

x_size = int(input("Enter number of samples of first signal: "))
y_size = int(input("Enter number of samples of second signal: "))

if x_size <= 0 or y_size <= 0:
    raise ValueError("Number of samples must be positive.")

if x_size > y_size:
    z_size = x_size
else:
    z_size = y_size

x = [0] * z_size
y = [0] * z_size
z = [0] * z_size

print("Enter the samples of first signal:")
for i in range(x_size):
    x[i] = int(input("Enter sample: "))

print("Enter the samples of second signal:")
for i in range(y_size):
    y[i] = int(input("Enter sample: "))

for i in range(z_size):
    z[i] = x[i] * y[i]

print("\nFirst signal samples:", *x[:x_size])
print("Second signal samples:", *y[:y_size])
print("Resultant signal samples after multiplication:", *z)
