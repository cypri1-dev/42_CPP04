<h1><img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/covers/cover-cpp-bonus.png"></h1>

## Description
This project introduces polymorphism and interfaces in C++ through an `Animal` class hierarchy, where `Dog` and `Cat` inherit from `Animal`, showcasing polymorphic behavior with the `makeSound()` method. The exercises build on this by adding abstract classes, deep copying, memory management, and interfaces for managing unique attributes and behaviors.

## Exercise 00
Objectives 🚀:
- Implement a basic `Animal` class and derive `Dog` and `Cat` classes.

Requirements:
- Define `Animal` with protected attribute `type`.
- `Dog` and `Cat` initialize `type` as "Dog" or "Cat".
- Create `makeSound()` for each class to produce specific sounds.

## Exercise 01
Objectives 🚀:
- Extend `Dog` and `Cat` with unique `Brain` objects.

Requirements:
- Add a `Brain` class with 100 `std::string` ideas.
- `Dog` and `Cat` have private `Brain*` attributes, allocated with `new` and deleted on destruction.
- Ensure deep copying of `Dog` and `Cat` objects.

## Exercise 02
Objectives 🚀:
- Make `Animal` an abstract class.

Requirements:
- Convert `Animal` into an abstract base class, making it non-instantiable.
- Derived classes like `Dog` and `Cat` remain functional.

## Exercise 03
Objectives 🚀:
- Implement interfaces using abstract classes.

Requirements:
- Create `AMateria` with `clone()` and `use()` as pure virtual methods.
- Implement `Ice` and `Cure` classes with specific `use` actions.
- Develop `Character` and `MateriaSource` classes with inventory and item management features.
