# 🧮 Arbitrary Precision Calculator (APC)

An **Arbitrary Precision Calculator (APC)** implemented in **C** using **Doubly Linked Lists** to perform arithmetic operations on integers of virtually unlimited size. Unlike built-in C data types (`int`, `long`, `long long`), this calculator can handle numbers containing hundreds or even thousands of digits without overflow.

---

## 📖 Project Overview

The Arbitrary Precision Calculator is designed to overcome the storage limitations of primitive integer data types. Large integers are represented as **Doubly Linked Lists**, where each node stores a single digit. Arithmetic operations are performed digit by digit, similar to manual calculations.

This project demonstrates the implementation of fundamental data structures and algorithms for handling large integer arithmetic.

---

## ✨ Features

- Addition of large integers
- Subtraction of large integers
- Multiplication of large integers
- Division of large integers
- Modulo operation
- Power operation
- Handles numbers of arbitrary length
- Supports positive and negative operands
- Command-line execution
- Dynamic memory allocation using Doubly Linked Lists

---

## 🛠 Technologies Used

- C Programming
- Doubly Linked Lists
- Dynamic Memory Allocation
- Command Line Arguments (CLA)
- String Manipulation
- Modular Programming

---

## 📂 Project Structure

```
.
├── apc.c              # Utility functions
├── apc.h              # Structure definitions and function prototypes
├── add.c              # Addition implementation
├── subtraction.c      # Subtraction implementation
├── multiplication.c   # Multiplication implementation
├── division.c         # Division implementation
├── modulo.c           # Modulo implementation
├── power.c            # Power implementation
├── main.c             # Driver program
├── Makefile           # Build file
└── README.md
```

---

## 📚 Data Structure

The project uses a **Doubly Linked List** to store large integers.

Each node stores a single decimal digit.

```
Head
 │
 ▼
+---+---+---+---+---+
| 1 | 2 | 3 | 4 | 5 |
+---+---+---+---+---+
 ▲                   ▲
 │                   │
Head               Tail
```

Example:

```
12345678901234567890
```

is stored as

```
1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6 ⇄ 7 ⇄ 8 ⇄ 9 ⇄ 0 ⇄ 1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6 ⇄ 7 ⇄ 8 ⇄ 9 ⇄ 0
```

Each node contains:

- Previous pointer
- Digit
- Next pointer

---

## ⚙️ Working

### 1. Command Line Validation

The program accepts three command-line arguments:

```
./apc.out operand1 operator operand2
```

Example:

```
./apc.out 98765432109876543210 + 12345678901234567890
```

The program validates:

- Operand 1
- Operator
- Operand 2

Supported operators:

| Operator | Operation |
|----------|-----------|
| + | Addition |
| - | Subtraction |
| * x X | Multiplication |
| / | Division |
| % | Modulo |
| ^ | Power |

---

### 2. Operand Conversion

Each operand is converted into a Doubly Linked List.

Example:

```
12345
```

becomes

```
1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5
```

---

### 3. Arithmetic Operations

The calculator performs arithmetic operations by traversing the linked lists.

- Addition is performed from the least significant digit using carry.
- Subtraction uses borrow logic.
- Multiplication follows the traditional long multiplication algorithm.
- Division repeatedly subtracts the divisor to obtain the quotient.
- Modulo computes the remainder after division.
- Power repeatedly multiplies the base according to the exponent.

The result is stored in another Doubly Linked List.

---

### 4. Result Display

The linked list representing the result is traversed from head to tail and printed as the final output.

---

## 🚀 Compilation

Using Makefile

```bash
make
```

Or compile manually

```bash
gcc *.c -o apc.out
```

---

## ▶️ Execution

Addition

```bash
./apc.out 12345678901234567890 + 98765432109876543210
```

Subtraction

```bash
./apc.out 99999999999999999999 - 11111111111111111111
```

Multiplication

```bash
./apc.out 123456789 * 987654321
```

Division

```bash
./apc.out 987654321 / 12345
```

Modulo

```bash
./apc.out 1000000000 % 97
```

Power

```bash
./apc.out 25 ^ 5
```

---

## 📋 Algorithm

1. Read command-line arguments.
2. Validate operands and operator.
3. Convert operands into Doubly Linked Lists.
4. Select the requested arithmetic operation.
5. Perform digit-by-digit computation.
6. Store the result in a new linked list.
7. Remove leading zeros if present.
8. Display the final result.

---

## 📈 Time Complexity

| Operation | Complexity |
|-----------|------------|
| Addition | O(n) |
| Subtraction | O(n) |
| Multiplication | O(n × m) |
| Division | Depends on implementation |
| Modulo | Depends on implementation |
| Power | Depends on exponent |

where **n** and **m** represent the number of digits in the operands.

---

## ✅ Advantages

- Supports integers of unlimited length.
- Eliminates integer overflow.
- Efficient memory usage through dynamic allocation.
- Demonstrates linked list manipulation.
- Modular and easy-to-maintain code structure.
- Suitable for very large numerical computations.

---

## 🌍 Applications

- Cryptography
- Scientific Computing
- Financial Calculations
- Mathematical Software
- Computer Algebra Systems
- High-Precision Numerical Computation

---

## 📚 Learning Outcomes

Through this project, I gained practical experience in:

- Doubly Linked Lists
- Dynamic Memory Allocation
- Pointer Manipulation
- Command Line Argument Processing
- Large Integer Arithmetic
- Algorithm Design
- Modular Programming in C

---

## 🚀 Future Enhancements

- Decimal number support
- Expression evaluation using parentheses
- Floating-point arbitrary precision
- Graphical User Interface (GUI)
- Support for hexadecimal and binary arithmetic
- Performance optimization for multiplication and division

---

## 👨‍💻 Author

**Chandeesh K M**


---

## 📄 License

This project is developed for educational purposes.