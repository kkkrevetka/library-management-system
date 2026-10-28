# Library Management System

A console-based Library Management System developed in C++ using object-oriented programming principles, which provides a simple way to manage different types of library materials, including books, magazines, DVDs, and research publications. It demonstrates the use of inheritance, polymorphism, smart pointers, and file handling in C++.

## Features
- multiple item types: manage books, magazines, DVDs, and research publications.
- search: find library items by ID, title, or type.
- sorting: sort library items by year or title.
- borrowing and returning: manage the borrowing and return of library items.
- library reports: generate reports about the collection.
- file handling: save library data to a text file and load it when needed.
  
## Technologies
- c++
- object-oriented programming (OOP)
- inheritance and polymorphism
- STL and smart pointers (`std::unique_ptr`)
- file input/output (`fstream`)

## Project Structure
```
library-management-system/
├── Book.cpp
├── Book.h
├── DVD.cpp
├── DVD.h
├── Library.cpp
├── Library.h
├── Magazine.cpp
├── Magazine.h
├── Manager.cpp
├── Manager.h
├── Research.cpp
├── Research.h
├── main.cpp
├── library_data.txt
└── README.md
```

## Getting Started

Prerequisites
- a c++ compiler that supports C++17 or later
- an IDE such as Xcode, Visual Studio, or CLion (optional)

Installation
1. clone the repository:
   ```
   git clone https://github.com/kkkrevatka/library-management-system.git
   ```

2. open the project in your preferred C++ IDE.
3. make sure `library_data.txt` is in the program's working directory.
4. compile and run the application.

## Data Storage
The application uses a text file to store library items. Each record contains fields separated by the `|` character. The file allows library data to be loaded into the program and saved between sessions.

## What I Learned
Through this project, I practiced:
- designing classes and organizing code across header and implementation files
- applying inheritance and polymorphism
- managing objects with smart pointers
- implementing search and sorting operations
- reading from and writing to text files
- organizing a multi-file c++ project

## Future Improvements
- add a graphical user interface
- implement unit tests
- improve input validation and error handling
- add member accounts and borrowing history
