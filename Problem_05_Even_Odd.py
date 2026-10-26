# Problem 05: Even and odd components of a discrete-time signal
# Same logic as GitHub's 4_even_odd_component.c: origin and x(n), x(-n).

def xval(x, ns, ne, n):
    if n < ns or n > ne:
        return 0
    return x[n - ns]


x_size = int(input("Enter number of samples of signal: "))
if x_size <= 0:
    raise ValueError("Number of samples must be positive.")

x = [0] * x_size
print("Enter the samples of signal:")
for i in range(x_size):
    x[i] = int(input("Enter sample: "))

org = int(input(f"Enter the sample no. which is the origin (1 to {x_size}): "))
if not 1 <= org <= x_size:
    raise ValueError("Origin must be between 1 and the signal length.")

ns = -(org - 1)
ne = ns + x_size - 1

a = abs(ns)
b = abs(ne)
L = max(a, b)

xe = [0.0] * (2 * L + 1)
xo = [0.0] * (2 * L + 1)

for n in range(-L, L + 1):
    xe[n + L] = (xval(x, ns, ne, n) + xval(x, ns, ne, -n)) / 2.0
    xo[n + L] = (xval(x, ns, ne, n) - xval(x, ns, ne, -n)) / 2.0

print("\nOriginal signal:")
for i in range(x_size):
    print(f"x[{ns + i}] = {x[i]}")

print("\nEven component:")
for n in range(-L, L + 1):
    print(f"xe[{n}] = {xe[n + L]:.1f}")

print("\nOdd component:")
for n in range(-L, L + 1):
    print(f"xo[{n}] = {xo[n + L]:.1f}")

print("\nVerification (xe + xo = x):")
for n in range(-L, L + 1):
    print(f"n={n} : {xe[n + L]:.1f} + {xo[n + L]:.1f} = {xe[n + L] + xo[n + L]:.1f}")
