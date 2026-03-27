# CPP Module 05 - Repetition and Exceptions

42 school C++ module focused on exception handling, orthodox canonical form,
and polymorphism through a bureaucratic simulation with Bureaucrats and Forms.

## Technologies

- C++98
- Makefile

## Exercises

| Exercise | Description |
|----------|-------------|
| ex00 | Bureaucrat class with grade bounds enforced via custom exceptions |
| ex01 | Form class that Bureaucrats can sign, with grade requirements |
| ex02 | Abstract Form (AForm) with concrete types: ShrubberyCreation, RobotomyRequest, PresidentialPardon |
| ex03 | Intern class that creates Forms by name using function pointers |

## Build Instructions

Each exercise is compiled independently from its own directory:

```bash
cd ex00        # or ex01, ex02, ex03
make           # compile
make clean     # remove object files
make fclean    # remove object files and binary
make re        # full recompile
```

## Usage

```bash
cd ex00 && make && ./bureaucrat
cd ex01 && make && ./form
cd ex02 && make && ./form
cd ex03 && make && ./form
```

## Key Concepts

- **Custom exceptions**: nested classes inheriting from `std::exception`
- **Orthodox Canonical Form**: default constructor, copy constructor, assignment operator, destructor
- **Abstract classes**: `AForm` with a pure virtual `execute()` method
- **Polymorphism**: concrete form types override `execute()` for distinct behavior
- **Function pointers to member functions**: used in `Intern::makeForm()` to dispatch form creation without conditional chains
