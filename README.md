# SMALL INTERPRETER (C++)

## 🔹 Project Introduction

Small Interpreter is a custom Mini Language Interpreter developed in C++ for Compiler Construction concepts.
The interpreter executes instructions line by line without compilation, simulating the behavior of real programming language interpreters.

The system supports variables, arithmetic expressions, logical conditions, loops, increment/decrement operations, and expression evaluation using stacks and parsing techniques.

The project demonstrates core concepts of:

* Parsing
* Expression Evaluation
* Operator Precedence
* Logical Processing
* Control Flow Handling
* Runtime Execution

---

# 🔹 Screenshots

## 🏠 Interpreter Console



## ➕ Expression Evaluation

Expression_Result

## 🔁 While Loop Execution

While_Loop_Result

## 🔄 For Loop Execution

For_Loop_Result

---

# ✨ Features

✅ Variable Handling using `map`
✅ Arithmetic Expressions (+, -, *, /)
✅ Operator Precedence (BODMAS)
✅ Expression Evaluation using Stacks
✅ While Loop Support
✅ For Loop Support
✅ Increment / Decrement Operations
✅ Logical Operators (&&, ||, !)
✅ Conditional Evaluation
✅ Print Command
✅ Show Variables Command
✅ Division by Zero Error Handling
✅ Undefined Variable Detection
✅ Custom Mini Language Execution

---

# ⚙️ How It Works

Small Interpreter follows a multi-stage execution process.

```txt
User Input
     │
     ▼
┌──────────────────────┐
│ 1. INPUT PROCESSING  │
│ Read line            │
│ Trim spaces          │
│ Tokenization         │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ 2. PARSING           │
│ Detect statement     │
│ Variables / loops    │
│ Conditions           │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ 3. EXPRESSION ENGINE │
│ Operator precedence  │
│ Stack evaluation     │
│ Arithmetic handling  │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ 4. LOGICAL ENGINE    │
│ AND / OR / NOT       │
│ Condition evaluation │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ 5. LOOP EXECUTION    │
│ While loops          │
│ For loops            │
│ Block execution      │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ 6. OUTPUT            │
│ Print results        │
│ Show variables       │
└──────────────────────┘
```

---

# 🧠 Core Components

## 1. Variable Storage

The interpreter uses:

```cpp id="var1"
map<string, int> var;
```

### Purpose:

* Stores variables and values
* Simulates memory handling

Example:

```txt id="ex1"
a = 5
```

Stored as:

```txt id="ex2"
var["a"] = 5
```

---

# ✂️ Trim Function

The trim function removes extra spaces from input strings.

### Purpose:

* Clean parsing
* Proper keyword recognition
* Prevents syntax issues

---

# 🔢 Number Detection

```cpp id="num1"
bool isNumber(string s)
```

### Purpose:

* Detects whether token is:

  * number
  * variable

Examples:

```txt id="num2"
isNumber("5")  → true
isNumber("x")  → false
```

---

# ➗ Operator Precedence

```txt id="pre1"
* and / → High Priority
+ and - → Low Priority
```

### Purpose:

Ensures correct mathematical order during expression evaluation.

Example:

```txt id="pre2"
5 + 2 * 3 = 11
```

---

# ⚙️ Expression Evaluation Engine

The interpreter evaluates arithmetic expressions using:

* Value Stack
* Operator Stack

### Supported:

✅ Addition
✅ Subtraction
✅ Multiplication
✅ Division
✅ Parentheses

### Features:

* Operator precedence handling
* Stack-based evaluation
* Error handling

---

# 🔗 Logical Engine

The logical engine evaluates conditions using:

* AND (&&)
* OR (||)
* NOT (!)

Example:

```txt id="log1"
x > 5 && y < 10
```

### Purpose:

* Used in loops
* Handles multiple conditions
* Produces true/false results

---

# 🔁 While Loop Support

Example:

```txt id="w1"
while ( x < 5 )
{
print x
x++
}
```

### Working:

* Evaluates condition
* Executes block repeatedly
* Stops when condition becomes false

---

# 🔄 For Loop Support

Example:

```txt id="f1"
for ( i = 0 ; i < 5 ; i++ )
{
print i
}
```

### Structure:

* Initialization
* Condition
* Increment / Decrement

---

# 📦 Block Execution

The interpreter executes all lines inside `{ }` blocks.

### Supported:

* print
* assignment
* increment/decrement

---

# 🖨️ Print Command

Example:

```txt id="p1"
print x
```

### Purpose:

Displays variable values.

---

# 📋 Show Variables

Example:

```txt id="s1"
show
```

### Purpose:

Displays all stored variables with their values.

---

# ❌ Error Handling

The interpreter handles:

✅ Division by Zero
✅ Undefined Variables
✅ Invalid Statements

Example:

```txt id="err1"
Error: Division by zero
```

---

# 💻 Technologies Used

## Programming Language

* C++

## Concepts Used

* STL
* Stack-Based Evaluation
* Parsing
* Tokenization
* Expression Trees Logic
* Compiler Construction Concepts

## STL Components

* map
* vector
* stringstream
* algorithms

---

# 🚀 Setup Instructions

## 1️⃣ Clone Repository

```bash
git clone https://github.com/yourusername/Small-Interpreter.git
cd Small-Interpreter
```

---

## 2️⃣ Compile Program

```bash
g++ main.cpp -o interpreter
```

---

## 3️⃣ Run Interpreter

```bash
./interpreter
```

---

# 🎯 Sample Input

```txt id="sample1"
a = 10
b = 5

c = a + b * 2
print c

while ( a > 5 )
{
print a
a--
}

show
exit
```

---

# 🎯 Target Audience

Small Interpreter is designed for:

* Compiler Construction Students
* Programming Beginners
* Academic Demonstrations
* Programming Language Learning
* Data Structure & Parsing Practice

---

# 👥 Team Information

## Compiler Construction Project

Presented By:

| Name           | Roll Number |
| -------------- | ----------- |
| Zainab Shaheen | 8583        |

---

# 🛡 Small Interpreter

### “Executing Logic, One Line at a Time.”

Built with ❤️ for Compiler Construction & Programming Concepts
