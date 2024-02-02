#include "include/System.h"
#include <iostream>
#include <limits>
#include <string> // Include for std::string

void clearCin() {
    std::cin.clear(); // Reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the line
}

int main() {
    System librarySystem;
    int choice;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Create Book\n";
        std::cout << "2. Show Book\n";
        std::cout << "3. Create Student\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearCin(); // Clear cin to avoid issues with getline

        int bno, admno, quant;
        std::string bname, aname, pname, sname;

        switch (choice) {
            case 1: {
                std::cout << "Enter book number: ";
                std::cin >> bno;
                std::cout << "Enter quantity: ";
                std::cin >> quant;
                clearCin(); // Clear cin to properly use getline next
                std::cout << "Enter book name: ";
                getline(std::cin, bname);
                std::cout << "Enter author name: ";
                getline(std::cin, aname);
                std::cout << "Enter publication name: ";
                getline(std::cin, pname);
                librarySystem.createBook(bno, quant, bname, aname, pname);
                break;
            }
            case 2:
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                librarySystem.showBook(bno);
                break;
            case 3: {
                std::cout << "Enter student name: ";
                getline(std::cin, sname);
                std::cout << "Enter student admission number: ";
                std::cin >> admno;
                clearCin();
                librarySystem.createStudent(sname, admno);
                break;
            }
            case 4:
                std::cout << "Enter student admission number: ";
                std::cin >> admno;
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                librarySystem.issueBook(admno, bno);
                break;
            case 5:
                std::cout << "Enter student admission number: ";
                std::cin >> admno;
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                librarySystem.returnBook(admno, bno);
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
