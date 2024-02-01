#include "../include/System.h"
#include <iostream>
#include <algorithm>

System::System() {}

System::~System() {
    // Implement cleanup if you're using dynamic memory
}


void System::createBook(int bno, int quant, const std::string& bname, const std::string& aname, const std::string& pname) {
    Book newBook(bno, quant, bname, aname, pname);

    std::cout << "Enter book number: ";
    std::cin >> newBook.bno;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cout << "Enter book name: ";
    getline(std::cin, newBook.bname);
    std::cout << "Enter author name: ";
    getline(std::cin, newBook.aname);
    std::cout << "Enter publication name: ";
    getline(std::cin, newBook.pname);
    std::cout << "Enter quantity: ";
    std::cin >> newBook.quant;
    books.push_back(newBook);
    bookMap[bno] = &books.back(); // Point to the newly added book
}

void System::createStudent() {
    Student newStudent;
    std::cout << "Enter student admission number: ";
    std::cin >> newStudent.admno;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cout << "Enter student name: ";
    getline(std::cin, newStudent.name);
    students.push_back(newStudent);
}

// In System.cpp or wherever you are implementing the System class methods

void System::issueBook(int admno, int bno) {
    auto studentIt = std::find_if(students.begin(), students.end(), [admno](const Student& student) { return student.admno == admno; });
    auto bookIt = bookMap.find(bno);

    if (studentIt != students.end() && bookIt != bookMap.end()) {
        if (studentIt->token == 0 && bookIt->second.quant > 0) {
            studentIt->bno = bno;
            studentIt->token = 1;
            bookIt->second.quant--;
            std::cout << "Book issued successfully." << std::endl;
        } else {
            std::cout << "Book cannot be issued. Either the book is out of stock or the student already has a book issued." << std::endl;
        }
    } else {
        std::cout << "Either the book or the student does not exist." << std::endl;
    }
}

void System::returnBook(int admno, int bno) {
    auto studentIt = std::find_if(students.begin(), students.end(), [admno](const Student& student) { return student.admno == admno; });
    auto bookIt = bookMap.find(bno);

    if (studentIt != students.end() && bookIt != bookMap.end()) {
        if (studentIt->bno == bno && studentIt->token == 1) {
            studentIt->bno = 0;
            studentIt->token = 0;
            bookIt->second.quant++;
            std::cout << "Book returned successfully." << std::endl;
        } else {
            std::cout << "Error in returning the book. Either the book does not match or the student did not issue any book." << std::endl;
        }
    } else {
        std::cout << "Either the book or the student does not exist." << std::endl;
    }
}
