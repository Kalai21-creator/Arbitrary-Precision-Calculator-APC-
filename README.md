# Arbitrary-Precision Calculator Project in C

## Overview
This project implements an **Arbitrary-Precision Calculator** in C, capable of performing arithmetic operations on extremely large numbers using a **Linked List Abstract Data Type (ADT)**. Unlike traditional fixed-precision arithmetic found in most hardware, this calculator handles numbers limited only by the memory of the host system.

---

## Objective
The primary objectives of this project are to:
- Perform mathematical operations on large numbers efficiently.
- Use a linked list to store and manipulate big numbers.
- Ensure accurate handling of integer and decimal operations.
- Optimize performance for corner cases like zero inputs.

---

## Key Features
### Supported Operations
- **Addition (+)**: Compute the sum of two large numbers.
- **Subtraction (-)**: Calculate the difference between two large numbers.
- **Multiplication (*)**: Multiply two large numbers.
- **Division (/)**: Perform division between two large numbers.
- **Modulus (%):** Compute the remainder of division.
- **Power (^)**: Calculate the power of a large number.

### Data Structure
- **Linked List:**
  - Numbers are sliced and stored across different nodes of the linked list.
  - Result lists are created for each operation, efficiently handling carry-forward and precision.

### Optimization Techniques
- Efficient handling of zero inputs:
  - If `Num1 = 0`, directly return `Num2`.
  - If `Num2 = 0`, directly return `Num1`.
  - If both numbers are zero, return `0`.
- Portable slicing based on the size of `int` for compatibility across different systems.

---

## Usage Instructions
### 1. **Compile the Program:**
   ```bash
   gcc -o apc calculator.c
   ```
### 2. **Run the Application:**
   ```bash
   ./apc
   ```
### 3. **Enter User Input:**
   - Input format: `<big_number><operator><big_number>`
   - Example:
     ```plaintext
     1234567890121234518775261672673+718625634152778367635544816
     ```
### 4. **View the Result:**
   ```plaintext
   1235286515755387297142897217489
   ```
### 5. **User Interaction:**
   ```plaintext
   Want to continue? Press [yY | nN]
   ```
   - Press `y` or `Y` to perform another operation.
   - Press `n` or `N` to terminate the application.

---

## Example Operations
1. **Addition Example:**
   ```plaintext
   Input: 123456789+987654321
   Output: 1111111110
   ```
2. **Multiplication Example:**
   ```plaintext
   Input: 123456789*2
   Output: 246913578
   ```
3. **Division Example:**
   ```plaintext
   Input: 987654321/3
   Output: 329218107
   ```

---

## Future Enhancements
- **Floating-Point Arithmetic:** Extend operations to fully support decimal precision.
- **User-Defined Precision Levels:** Allow users to specify precision constraints.
- **Error Handling:** Improved detection and reporting for invalid inputs.
- **Graphical User Interface (GUI):** Build a user-friendly interface for easier operation.

---

## Conclusion
This Arbitrary-Precision Calculator project showcases the power of linked lists and efficient algorithms for handling large numbers. By supporting essential arithmetic operations and optimizing for special cases, it serves as a robust tool for exploring the world of big-num arithmetic in C.

