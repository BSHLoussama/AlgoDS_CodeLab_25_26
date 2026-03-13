# L1 Section 5 — Computer Science (USTHB) 
## TP5 & TP6 — Functions and Structures in C (2025/2026)

This repository is for my first-year students (Licence 1, Section 5) for the academic year 2025/2026.

It contains the code explained during our practical sessions for:
- **TP5** — Functions in C (Library Version)
- **TP6** — Structures in C

This repo serves as a reference for you to review and understand the implementations discussed in class.

⚠️ **Important Note:**  
The theoretical explanations (function delegation, DRY principle, struct memory layout, etc.) are detailed in your assignment reports and class notes. Here, you will find the implementations with practical guidance.

---

# Repository Structure

```
TP5-functions/
├── solve_quadratic.c   → Old version: Final integrated solution
├── my_pow.c            → Old version: my_pow() with test main
├── my_discr.c          → Old version: compute_discr() with test main
├── my_sqrt.c           → Old version: my_sqrt() with test main
└── lib_version/
    ├── main.c          → New version: Entry point (single main)
    ├── my_math.c       → New version: All implementations
    └── my_math.h       → New version: Function declarations

TP6_structures/
├── students.c          → Complete student management program
└── test.c              → Memory layout demonstration (padding vs packing)
```

### 🗺️ Quick Navigation Guide

| What do you want to learn? | Where to go? |
|----------------------------|--------------|
| How to write individual functions | `TP5-functions/` (old version) |
| How to test functions separately | `TP5-functions/my_*.c` files |
| How to organize a C project | `TP5-functions/lib_version/` |
| How to use header files | `TP5-functions/lib_version/my_math.h` |
| How to work with structures | `TP6_structures/students.c` |
| How memory alignment works | `TP6_structures/test.c` |

---

# TP5 — Two Versions, Two Approaches

## Why Two Versions?

TP5 contains **two different implementations** of the same solution:

### 🔴 **Old Version** (Root directory)
- Each function in its own `.c` file
- Each file has its own `main()` for independent testing
- Files: `solve_quadratic.c`, `my_pow.c`, `my_discr.c`, `my_sqrt.c`
- **Purpose:** Learning to write and test functions independently

### 🟢 **Lib Version** (lib_version/ directory)
- Professional library structure
- Single `main()` in `main.c`
- All implementations in `my_math.c`
- Declarations in `my_math.h`
- **Purpose:** Learning proper C project organization

## Which Version Should You Study?

**Both!** They teach different concepts:

| Old Version | Lib Version |
|-------------|-------------|
| ✓ Independent testing | ✓ Professional structure |
| ✓ One function = one file | ✓ Separation of interface/implementation |
| ✓ Easy debugging | ✓ Reusable library |
| ✓ Beginner-friendly | ✓ Industry standard |

**Recommended Learning Path:**
1. Start with the **old version** to understand each function
2. Move to **lib version** to see professional organization
3. Understand why the lib version is better for real projects

### 💡 Key Takeaway

The **old version** teaches you how to **write functions**.  
The **lib version** teaches you how to **organize a project**.

Both are essential skills!

---

# TP5 — Old Version (Original Approach)

## Overview

The old version demonstrates the **learning phase** approach:
- Each function is isolated in its own file
- Every file has a `main()` function for testing
- Easy to test and debug individual functions
- Good for understanding function responsibilities

---

## Files in Old Version

### `solve_quadratic.c`
The final integrated solution that:
- Calls `compute_discr()`
- Uses `sqrt()` from `<math.h>` or `my_sqrt()`
- Determines number of real roots
- Returns results using pointers

**Compilation:**
```bash
gcc solve_quadratic.c -o solve -lm
```

### `my_pow.c`
Standalone implementation of power function:
- Contains `double my_pow(double base, int exp)`
- Has its own `main()` with tests
- Can be compiled and tested independently

**Compilation:**
```bash
gcc my_pow.c -o pow_test
```

### `my_discr.c`
Discriminant calculation:
- Contains `double compute_discr(double a, double b, double c)`
- Uses `my_pow()` (must be included)
- Has its own test `main()`

**Compilation:**
```bash
gcc my_discr.c -o discr_test
```

### `my_sqrt.c`
Square root using Newton's method:
- Contains `double my_sqrt(double S)`
- Has its own test comparing with standard `sqrt()`
- Independent testing and validation

**Compilation:**
```bash
gcc my_sqrt.c -o sqrt_test -lm
```

---

## Advantages of Old Version

✅ **Easy to learn:** One concept per file  
✅ **Independent testing:** Test each function separately  
✅ **Easy debugging:** Isolate problems quickly  
✅ **Clear focus:** Each file has one responsibility  

## Disadvantages of Old Version

❌ **Not scalable:** Too many files for larger projects  
❌ **Code duplication:** Each file might redefine helpers  
❌ **Not professional:** Not how real projects are organized  
❌ **Multiple mains:** Can't combine files easily  

### 📝 Real-World Note

While the old version is primarily for learning, the pattern of "one file with test main" is actually used professionally for:
- **Unit testing:** Each module has its own test file
- **Algorithm prototyping:** Quick experimentation
- **Code interviews:** Self-contained solutions
- **Documentation examples:** Runnable code snippets

The difference is that in real projects, you'd separate test files from implementation files (e.g., `my_sqrt.c` + `test_my_sqrt.c`).

---

# TP5 — Lib Version (Professional Approach)

## Overview

This version demonstrates **proper C library structure** with:
- Separation of interface (`.h`) and implementation (`.c`)
- Single `main()` function in `main.c`
- All function implementations in `my_math.c`
- Function declarations in `my_math.h`

This is the **professional approach** to organizing C code.

---

## Files Explanation

### `my_math.h` — The Interface

This header file contains:
- Function **declarations** (prototypes)
- Include guards (`#ifndef`, `#define`, `#endif`)
- No implementations, only signatures

**Purpose:** Tells other files what functions are available.

```c
#ifndef MY_MATH_H
#define MY_MATH_H

double my_pow(double base, int exp);
double my_fabs(double nbr);
double my_sqrt(double S);
double compute_discr(double a, double b, double c);
void solve_quadratic(double a, double b, double c,
                     double *x1, double *x2, int *num_roots);

#endif
```

### `my_math.c` — The Implementation

Contains the actual code for all functions:

1. **`my_pow()`** — Power calculation without using `pow()`
   - Uses a loop to multiply base by itself exp times
   - Handles edge cases (negative exponents, 0^0)

2. **`my_fabs()`** — Absolute value
   - Simple ternary operator implementation
   - Used by `my_sqrt()` for precision checking

3. **`my_sqrt()`** — Square root using Newton's method
   - Iterative approximation method
   - Stops when precision (epsilon) is reached

4. **`compute_discr()`** — Discriminant calculation
   - Uses `my_pow()` instead of rewriting `b*b`
   - **Demonstrates function delegation**

5. **`solve_quadratic()`** — Complete quadratic equation solver
   - Uses `compute_discr()` and `my_sqrt()`
   - Returns multiple values using **pointers**

### `main.c` — The Entry Point

- Contains **only** the `main()` function
- Calls `solve_quadratic()`
- Displays results
- **Clean separation of concerns**

---

## Compilation

### Method 1: Specify all files
```bash
gcc main.c my_math.c -o my_program -lm
```

### Method 2: Use wildcard (compile all .c files)
```bash
gcc *.c -o my_program -lm
```

### Why `-lm`?
Even though we implemented our own `my_sqrt()`, the program might still need the math library for other operations. It's safe to always include it.

---

## Key Concepts You Must Understand

### 1. **Header Files (.h)**
- Declare functions (tell the compiler they exist)
- Allow different `.c` files to use the same functions
- Prevent "implicit declaration" errors

### 2. **Implementation Files (.c)**
- Contain the actual function code
- Include the corresponding `.h` file
- Multiple `.c` files can be compiled together

### 3. **Include Guards**
```c
#ifndef MY_MATH_H
#define MY_MATH_H
// ... declarations ...
#endif
```
- Prevent multiple inclusions of the same header
- Avoid "redefinition" errors

### 4. **Function Delegation**
```c
double compute_discr(double a, double b, double c) {
    return my_pow(b, 2) - 4 * a * c;  // Calls my_pow() instead of b*b
}
```
- Don't Repeat Yourself (DRY principle)
- Each function has one clear responsibility

### 5. **Pointers for Multiple Return Values**
```c
void solve_quadratic(double a, double b, double c,
                     double *x1, double *x2, int *num_roots)
```
- A function can only `return` one value
- Use pointers to "return" multiple values
- The function modifies the variables through pointers

---

## Testing Your Understanding

Try to answer these questions:

1. Why do we put declarations in `.h` and implementations in `.c`?
2. What happens if you forget to include `my_math.h` in `main.c`?
3. Why does `compute_discr()` call `my_pow()` instead of using `b * b`?
4. How does `solve_quadratic()` return 3 values (x1, x2, num_roots)?
5. What would happen if you compiled only `main.c` without `my_math.c`?

---

# TP6 — Structures in C

## Overview

This TP introduces **structures (struct)** in C:
- Grouping related data together
- Arrays of structures
- Memory layout (padding vs packing)
- Real-world data modeling

---

## Files Explanation

### `students.c` — Student Management System

**Purpose:** Demonstrate practical use of structures.

#### What it does:
1. Defines a `Student` structure with 4 fields:
   ```c
   struct Student {
       int id;          // 4 bytes
       char name[50];   // 50 bytes
       int age;         // 4 bytes
       float grade;     // 4 bytes
   };
   ```

2. Creates an **array of structures**:
   ```c
   struct Student students[50];
   ```

3. Reads student information from user input

4. Displays all students

5. Calculates average grade

#### Key Concepts:

**Accessing struct fields:**
```c
students[i].id      // Access id of student i
students[i].name    // Access name of student i
students[i].grade   // Access grade of student i
```

**The dot operator (.):**
- Used to access members of a structure
- Syntax: `structure_variable.field_name`

**Why use structures?**
- Logically group related data
- Easier to manage than separate arrays
- Represents real-world entities clearly

---

### `test.c` — Memory Layout Demonstration

**Purpose:** Understand how structures are stored in memory.

#### The Mystery: Memory Padding

```c
#pragma pack(0)  // Default padding (optimized for speed)
struct abc {
    char a;   // 1 byte
    int c;    // 4 bytes
    char b;   // 1 byte
};
```

**Question:** How much memory does this struct use?
- **Expected:** 1 + 4 + 1 = 6 bytes
- **Actual:** 12 bytes! Why?

#### Answer: CPU Architecture

**32-bit CPUs read memory in 4-byte chunks (words)**

##### With Padding (Default):
```
Memory layout:
[a][   ][   ][   ]  — 4 bytes (a + 3 padding bytes)
[c][c][c][c]        — 4 bytes (int c)
[b][   ][   ][   ]  — 4 bytes (b + 3 padding bytes)
Total: 12 bytes
CPU cycles: 3 (one per word) ✓ FAST
```

##### With Packing (`#pragma pack(1)`):
```
Memory layout:
[a][c][c][c]        — 4 bytes
[c][b][   ][   ]    — 4 bytes
Total: 6 bytes
CPU cycles: More than 3 ✗ SLOWER
```

**Why?** The CPU must perform extra operations to extract the `int c` that spans across two memory words.

#### The Trade-off:

| Padding (Default) | Packing          |
|-------------------|------------------|
| More memory (12B) | Less memory (6B) |
| Faster access     | Slower access    |
| Aligned to word   | Not aligned      |

**In practice:** Let the compiler handle it (use padding). Memory is cheap, speed matters.

---

## Key Concepts for TP6

### 1. **Structure Definition**
```c
struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};
```
- Groups related variables together
- Creates a new data type

### 2. **Structure Declaration**
```c
struct Student student1;           // Single student
struct Student students[50];       // Array of students
```

### 3. **Accessing Members**
```c
student1.id = 12345;
printf("%s", students[0].name);
```

### 4. **Initialization**
```c
struct Student s1 = {101, "Ahmed", 20, 15.5};
```

### 5. **Memory Alignment**
- CPU reads memory in word-sized chunks
- Padding ensures efficient access
- Use `sizeof()` to check actual size

---

## How to Use This Repository

### For TP5 - Old Version (Learning Phase):
1. Navigate to `TP5-functions/` (root)
2. Start with `my_pow.c` - understand the simplest function
3. Move to `my_sqrt.c` - see Newton's method
4. Study `my_discr.c` - see function delegation
5. Finally read `solve_quadratic.c` - the complete solution
6. **Compile each file independently:**
   ```bash
   gcc my_pow.c -o pow_test
   gcc my_sqrt.c -o sqrt_test -lm
   gcc solve_quadratic.c -o solve -lm
   ```
7. **Test each function separately to understand it**

### For TP5 - Lib Version (Professional Structure):
1. Navigate to `TP5-functions/lib_version/`
2. Read `my_math.h` to understand available functions
3. Read `my_math.c` to see implementations
4. Study `main.c` to see how everything connects
5. Compile and test: `gcc *.c -o program -lm`
6. **Experiment:** Try adding a new function to the library
7. **Compare:** Notice how this is cleaner than having separate files

### For TP6:
1. Navigate to `TP6_structures/`
2. Compile `students.c`: `gcc students.c -o students`
3. Run and test with different inputs
4. Compile `test.c`: `gcc test.c -o test`
5. Observe the `sizeof()` output
6. **Experiment:** Try `#pragma pack(1)` and see the difference

---

## Important Reminders

### Don't Just Copy Code
Make sure you understand:
- Why each function exists
- What its responsibility is
- How structures organize data
- How memory is laid out

### Practice These Skills
1. Writing your own header files
2. Splitting code into multiple files
3. Using structures for real problems
4. Understanding memory trade-offs

### Common Mistakes to Avoid
❌ Forgetting to include the header file  
❌ Forgetting `-lm` when compiling  
❌ Not using `&` when passing pointers  
❌ Confusing `.` (struct) with `->` (pointer to struct)  
❌ Not initializing structure variables  

---

## Questions to Test Yourself

### TP5 Questions (General):
1. What's the difference between `my_math.h` and `my_math.c`?
2. Why does `compute_discr()` call `my_pow()` instead of using `b * b`?
3. How does `solve_quadratic()` return 3 values (x1, x2, num_roots)?
4. What's the difference between Newton's method and using the standard `sqrt()`?

### TP5 Questions (Comparing Versions):
1. Why can the old version have multiple `main()` functions but lib version can't?
2. What are the advantages of having each function in a separate file (old version)?
3. What are the advantages of the library structure (lib version)?
4. When would you use the old version approach in real programming?
5. How does the compiler handle multiple `.c` files in the lib version?
6. What happens if you try to compile all old version files together?

### TP6 Questions:
1. What's the size of `struct Student`? (Hint: Use `sizeof()`)
2. How do you access the grade of the 3rd student in an array?
3. Why is padding used in structures?
4. What does `#pragma pack(1)` do?
5. Why is padding faster even though it uses more memory?

---

## Compilation Quick Reference

```bash
# TP5 - Old Version (Individual Testing)
cd TP5-functions/
gcc my_pow.c -o pow_test
./pow_test

gcc my_sqrt.c -o sqrt_test -lm
./sqrt_test

gcc solve_quadratic.c -o solve -lm
./solve

# TP5 - Library Version (Professional Structure)
cd TP5-functions/lib_version/
gcc *.c -o quadratic -lm
./quadratic

# Alternative: Specify files explicitly
gcc main.c my_math.c -o quadratic -lm
./quadratic

# TP6 - Students
cd TP6_structures/
gcc students.c -o students
./students

# TP6 - Memory Test
gcc test.c -o test
./test
```

---

## Final Advice

This repository is a **learning resource**, not just a solution.

Your goal is to:
✓ Write clean, modular code  
✓ Understand function organization  
✓ Master structures and memory concepts  
✓ Build good programming habits  

If something is unclear:
1. Review your class notes
2. Test the code yourself
3. Experiment with modifications
4. Ask specific questions during TP sessions

---

## Good Luck! 🚀

Remember: **Understanding > Copying**

Programming is learned by doing. Compile, run, modify, break things, fix them, and learn from the process.