# Problem 04: Amplitude scaling
# Same logic as GitHub's 2_amplitude_scaling.c, with fixed original-signal output.

x_size = int(input("Enter number of samples of signal: "))
if x_size <= 0:
    raise ValueError("Number of samples must be positive.")

x = [0.0] * x_size
y = [0.0] * x_size

print("Enter the samples of signal:")
for i in range(x_size):
    x[i] = float(input("Enter sample: "))

factor = float(input("Enter the amplitude factor: "))

for i in range(x_size):
    y[i] = x[i] * factor

print("\nOriginal signal samples:", *(f"{value:.2f}" for value in x))
print("Resultant signal samples after amplitude scaling:", *(f"{value:.2f}" for value in y))
