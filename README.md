# CPP Modules (00-04)

A comprehensive C++ learning project series covering fundamental to advanced object-oriented programming concepts. This repository contains implementations of 42 School's C++ modules, demonstrating mastery of C++98 standard features, memory management, polymorphism, and design patterns.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Technical Details](#technical-details)
- [Module Breakdown](#module-breakdown)
- [Limitations & Notes](#limitations--notes)
- [License](#license)

## Overview

This project series provides a structured introduction to C++ programming, starting from basic syntax and progressing through advanced object-oriented concepts. Each module builds upon previous knowledge, introducing new concepts incrementally while reinforcing best practices in memory management, encapsulation, and code organization.

The modules are designed to transition programmers from C to C++, emphasizing the differences in paradigms and introducing modern programming concepts such as classes, inheritance, polymorphism, operator overloading, and abstract interfaces.

## Features

### Module 00 - Basics & Namespaces
- String manipulation and output streams
- Class design with encapsulation
- Static members and methods
- Member function implementation
- Const correctness

### Module 01 - Memory & References
- Stack vs heap allocation
- Pointers and references
- Memory lifecycle management
- File I/O operations
- String replacement algorithms

### Module 02 - Operator Overloading
- Fixed-point arithmetic implementation
- Canonical form (Orthodox Canonical Class Form)
- Arithmetic operator overloading
- Comparison operators
- Increment/decrement operators
- Binary Space Partitioning (BSP) algorithm

### Module 03 - Inheritance
- Single inheritance
- Multiple inheritance
- Virtual inheritance (diamond problem)
- Constructor/destructor chaining
- Member visibility (public, private, protected)

### Module 04 - Polymorphism
- Abstract classes and interfaces
- Pure virtual functions
- Deep copy semantics
- Virtual destructors
- Runtime polymorphism
- Interface-based design patterns

## Project Structure

```
cpp/
├── cpp00/          # Introduction to C++ - Basics
│   ├── ex00/       # Megaphone - String manipulation
│   ├── ex01/       # PhoneBook - Class design
│   └── ex02/       # Account - Static members
│
├── cpp01/          # Memory, Pointers, References
│   ├── ex00/       # Zombie - Heap vs Stack
│   ├── ex01/       # ZombieHorde - Array allocation
│   ├── ex02/       # Brain - References demonstration
│   ├── ex03/       # Weapon - Reference semantics
│   ├── ex04/       # Sed - File I/O and string replacement
│   ├── ex05/       # Harl - Member function pointers
│   └── ex06/       # HarlFilter - Switch alternatives
│
├── cpp02/          # Ad-hoc Polymorphism & Operators
│   ├── ex00/       # Fixed - Orthodox Canonical Form
│   ├── ex01/       # Fixed - Type conversions
│   ├── ex02/       # Fixed - Operators
│   └── ex03/       # BSP - Geometric algorithms
│
├── cpp03/          # Inheritance
│   ├── ex00/       # ClapTrap - Base class
│   ├── ex01/       # ScavTrap - Single inheritance
│   ├── ex02/       # FragTrap - Multiple inheritance
│   └── ex03/       # DiamondTrap - Virtual inheritance
│
└── cpp04/          # Subtype Polymorphism
    ├── ex00/       # Animal - Virtual functions
    ├── ex01/       # Brain - Deep copy
    ├── ex02/       # Abstract - Pure virtual
    └── ex03/       # Materia - Interface design
```

## Installation

### Prerequisites

- **Compiler**: `g++` or `clang++` with C++98 support
- **Build System**: GNU Make
- **OS**: Linux, macOS, or WSL on Windows

### Building the Projects

Each exercise contains its own Makefile. Navigate to the desired exercise directory and compile:

```bash
# Clone the repository
git clone <repository-url>
cd cpp

# Build a specific exercise
cd cpp00/ex00
make

# Run the compiled program
./megaphone "hello world"
```

### Makefile Targets

Each Makefile supports standard targets:
- `make` or `make all` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Rebuild from scratch

## Usage

### CPP00 - Examples

**ex00: Megaphone**
```bash
./megaphone "shhhhh... I think the students are asleep..."
# Output: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

**ex01: PhoneBook**
```bash
./phonebook
# Interactive menu:
# ADD - Add a new contact
# SEARCH - Search and display contacts
# EXIT - Quit the program
```

### CPP01 - Examples

**ex00: Zombie**
```bash
./zombie
# Demonstrates heap vs stack allocation
# Shows constructor/destructor order
```

**ex04: Sed replacement**
```bash
./replace filename "old_string" "new_string"
# Creates filename.replace with replacements
```

### CPP02 - Examples

**ex02: Fixed-point arithmetic**
```bash
./fixed
# Demonstrates operator overloading
# Fixed-point number operations
```

**ex03: BSP (Binary Space Partitioning)**
```bash
./bsp
# Tests if a point is inside a triangle
# Uses fixed-point arithmetic for precision
```

### CPP03 - Examples

**ex03: DiamondTrap**
```bash
./diamondtrap
# Demonstrates virtual inheritance
# Resolves diamond problem
```

### CPP04 - Examples

**ex03: Materia**
```bash
./materia
# Interface-based design pattern
# Demonstrates abstract classes
# Deep copy with polymorphic objects
```

## Technical Details

### Compilation Flags

All projects compile with strict standards:
```makefile
CFLAGS = -Wall -Wextra -Werror -std=c++98
```

These flags ensure:
- **-Wall**: Enable all warning messages
- **-Wextra**: Enable extra warning messages
- **-Werror**: Treat warnings as errors
- **-std=c++98**: Enforce C++98 standard compliance

### Memory Management

All projects follow strict memory management principles:
- **No memory leaks**: Every allocation is properly freed
- **RAII** (Resource Acquisition Is Initialization): Resources tied to object lifetime
- **Rule of Three**: Copy constructor, assignment operator, and destructor implemented together
- **Deep copy semantics**: When appropriate, objects own their resources

### Design Patterns & Concepts

#### Orthodox Canonical Form (CPP02)
```cpp
class MyClass {
public:
    MyClass();                              // Default constructor
    MyClass(const MyClass& other);          // Copy constructor
    MyClass& operator=(const MyClass& rhs); // Assignment operator
    ~MyClass();                             // Destructor
};
```

#### Virtual Inheritance (CPP03)
Solves the diamond problem in multiple inheritance:
```cpp
class Base { /* ... */ };
class Derived1 : virtual public Base { /* ... */ };
class Derived2 : virtual public Base { /* ... */ };
class Diamond : public Derived1, public Derived2 { /* ... */ };
```

#### Abstract Classes & Interfaces (CPP04)
```cpp
class IInterface {
public:
    virtual ~IInterface() {}
    virtual void method() = 0;  // Pure virtual
};
```

### Key Algorithms

**Fixed-Point Arithmetic** (CPP02)
- Represents fractional numbers using integers
- 8-bit fractional precision
- Implements full operator suite
- Useful in systems without floating-point hardware

**BSP Algorithm** (CPP02 ex03)
- Determines if a point is inside a triangle
- Uses cross product and area comparison
- All calculations in fixed-point arithmetic

**Deep Copy with Polymorphism** (CPP04)
- Clone pattern for polymorphic objects
- Virtual copy constructors
- Proper memory management in inheritance hierarchies

## Module Breakdown

### CPP00: Introduction to C++

**Learning Objectives:**
- Namespaces and scope resolution
- Classes and member functions
- Initialization lists
- Static vs instance members
- Const correctness
- I/O streams

**Key Exercises:**
- **ex00**: Simple string manipulation
- **ex01**: Contact management system with classes
- **ex02**: Bank account simulation with static members

### CPP01: Memory Allocation & References

**Learning Objectives:**
- Stack vs heap allocation
- New and delete operators
- Pointers vs references
- Reference semantics
- File stream operations
- String manipulation

**Key Exercises:**
- **ex00-01**: Zombie allocation patterns
- **ex02**: Pointer and reference comparison
- **ex03**: Reference as class members
- **ex04**: File processing and string replacement
- **ex05-06**: Function pointers and switch alternatives

### CPP02: Ad-hoc Polymorphism

**Learning Objectives:**
- Operator overloading
- Canonical form
- Fixed-point arithmetic
- Type conversions
- Copy semantics
- Const member functions

**Key Exercises:**
- **ex00-02**: Progressive implementation of Fixed class
- **ex03**: Geometric algorithm using Fixed-point

### CPP03: Inheritance

**Learning Objectives:**
- Single inheritance
- Multiple inheritance
- Virtual inheritance
- Constructor/destructor chaining
- Protected members
- Diamond problem resolution

**Key Exercises:**
- **ex00**: Base ClapTrap class
- **ex01-02**: Derived ScavTrap and FragTrap
- **ex03**: DiamondTrap with virtual inheritance

### CPP04: Subtype Polymorphism

**Learning Objectives:**
- Virtual functions
- Abstract classes
- Interfaces (pure virtual)
- Dynamic polymorphism
- Deep copy in inheritance
- Virtual destructors
- RTTI basics

**Key Exercises:**
- **ex00**: Virtual function introduction
- **ex01**: Deep copy with Brain class
- **ex02**: Abstract Animal class
- **ex03**: Materia system with interfaces

## Limitations & Notes

### C++98 Standard Constraints

This project strictly adheres to C++98 standard, which means:
- **No C++11 features**: No auto, nullptr, range-based for loops, smart pointers
- **Manual memory management**: No std::unique_ptr or std::shared_ptr
- **Limited STL usage**: Containers used sparingly per module requirements
- **No move semantics**: Only copy constructors and assignment operators

### Known Limitations

- **PhoneBook (CPP00 ex01)**: Limited to 8 contacts with circular buffer
- **Fixed-point (CPP02)**: Limited precision (8 fractional bits)
- **No exception handling**: Projects focus on C++98 basics, not advanced error handling
- **No templates**: Template programming covered in separate advanced modules

### Design Decisions

- **Verbose output**: Many exercises include detailed output for educational purposes
- **Simple algorithms**: Focus on C++ concepts rather than algorithmic complexity
- **Separation of concerns**: Each exercise isolated to prevent dependency issues
- **Test cases**: Main functions demonstrate usage but are not exhaustive test suites

## Best Practices Demonstrated

### Code Organization
- Header guards in all `.hpp` files
- Separation of declaration (`.hpp`) and implementation (`.cpp`)
- One class per file (with exceptions)
- Consistent naming conventions

### Memory Safety
- No naked pointers where avoidable
- Proper cleanup in destructors
- Copy constructors for classes managing resources
- Assignment operator with self-assignment check

### Object-Oriented Design
- Encapsulation with private/protected members
- Single Responsibility Principle
- Interface Segregation (CPP04)
- Liskov Substitution Principle (inheritance modules)

## License

This project is for educational purposes as part of the 42 School curriculum. The code is provided as-is for learning and reference.

---

**Note**: This project demonstrates foundational C++ concepts required for system programming and software engineering roles. The strict adherence to C++98 and memory management principles makes this particularly relevant for embedded systems, game development, and high-performance computing positions.
