from sympy import symbols, cos, Eq, fsolve

# Define the variable
x = symbols('x')

# Define the functions
f1 = cos(x) - 1.3 * x
f2 = x * cos(x) - 2 * x**2 + 3 * x - 1
f3 = 2 * x * cos(2 * x) - (x + 1)**2

# Solve for roots using fsolve
root_f1 = fsolve(f1, 0)  # Starting from x=0
root_f2 = fsolve(f2, 0)  # Starting from x=0
root_f3 = fsolve(f3, 0)  # Starting from x=0

# Display the roots
print("Root of f1(x):", root_f1)
print("Root of f2(x):", root_f2)
print("Root of f3(x):", root_f3)