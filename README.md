# L1 Section 5 — Computer Science (USTHB) 
## TP5 — Functions in C (2025/2026)

This repository is for my first-year students (Licence 1, Section 5) for the academic year 2025/2026.

It contains the code that was explained during our practical session for TP5 — Functions in C.  
This repo serves as a reference for you to review and understand the implementation discussed in class.

⚠️ The theoretical explanation (Phase 3 — Function Chains, delegation, DRY principle, etc.) is detailed in the assignment report.  
Here, you will only find the implementation.

---

# Repository Structure

solve_quadratic.c   → Final integrated version (complete solution)  
my_pow.c            → Implementation of my_pow()  
my_discr.c          → Implementation of compute_discr()  
my_sqrt.c           → Implementation of my_sqrt()  

---

# How You Should Use This Repository

As my students, you should:

- First read `solve_quadratic.c` carefully.
- Understand how `compute_discr()` is called instead of rewriting the formula.
- Observe how pointers are used to return multiple values.
- Review the helper files to understand each function independently.
- Compile and test each file on your own machine.

Do not just copy the code.  
Make sure you understand:

- Why each function exists
- What its responsibility is
- How functions call each other
- Why delegation is important

---

# Main File

## solve_quadratic.c

This is the final version of the phase 3 of the assignment.

It:

- Calls `compute_discr()`
- Uses either `sqrt()` from `<math.h>` or `my_sqrt()`
- Determines the number of real roots
- Stores results using pointer parameters

You should clearly understand how:

- The discriminant controls the logic
- The number of roots is stored in `*num_roots`
- The roots are returned using `*x1` and `*x2`

---

# Helper Files

Each helper file contains:

- The function implementation
- A `main()` function
- Independent tests

This allows you to:

- Test functions separately
- Debug more easily
- Focus on one responsibility at a time

---

## my_pow.c

Implements:

double my_pow(double base, int exp);

- Uses a loop (no `pow()` allowed)
- Handles only non-negative exponents
- Returns `-1` in case of error

---

## my_discr.c

Implements:

double compute_discr(double a, double b, double c);

Computes:

Δ = b² - 4ac

It uses `my_pow()` instead of duplicating the power logic.

---

## my_sqrt.c

Implements:

double my_sqrt(double S);

- Uses Newton’s method
- Handles negative inputs
- Compares results with standard `sqrt()`

---

# Compilation Notes

If you use `sqrt()` from `<math.h>`, you must link the math library:

gcc program.c -o program -lm

Without `-lm`, compilation will fail.

---

# Final Advice

This repository is a learning resource.

Your goal is not only to make the program work, but to:

- Write clean functions
- Avoid code duplication
- Respect function responsibilities
- Structure your code clearly

If something is unclear, review your TP report and your class notes before asking.
