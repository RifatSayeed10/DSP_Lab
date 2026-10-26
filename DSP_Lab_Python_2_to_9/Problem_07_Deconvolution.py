# Problem 07: Deconvolution
# Same recursive calculation as GitHub's 6_deconvolution.c.
# Adds verification for whether the full supplied output was reconstructed.

y_size = int(input("Enter number of output samples: "))
h_size = int(input("Enter number of impulses: "))
if y_size <= 0 or h_size <= 0:
    raise ValueError("Number of samples must be positive.")

x_size = y_size - h_size + 1
if x_size < 1:
    raise ValueError("Invalid: impulse response longer than output.")

n = max(h_size, x_size)
y = [0] * y_size
h = [0] * n
x = [0.0] * x_size

print("Enter output sequences:")
for i in range(y_size):
    y[i] = int(input("Enter sample: "))

print("Enter impulse sequences:")
for i in range(h_size):
    h[i] = int(input("Enter sample: "))

if h[0] == 0:
    raise ValueError("Deconvolution not possible: h[0] is zero.")

y_o = int(input("Enter starting index of y(n): "))
h_o = int(input("Enter starting index of h(n): "))
x_o = y_o - h_o

for i in range(x_size):
    temp = i
    total = 0.0
    for j in range(i):
        total = total + x[j] * h[temp]
        temp -= 1
    x[i] = (y[i] - total) / h[0]

print("\nSample values of input:", *(f"{value:.2f}" for value in x))
print("Starting index of input:", x_o)

# Extra check: all output samples must equal convolution(x, h).
verified = True
for i in range(y_size):
    computed = 0.0
    for j in range(x_size):
        k = i - j
        if 0 <= k < h_size:
            computed += x[j] * h[k]
    if abs(computed - y[i]) > 1e-6:
        verified = False
        break

if not verified:
    print("Warning: The given y(n) and h(n) do not match exact linear convolution.")
