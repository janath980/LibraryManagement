// In main.cpp

#include "include/System.h"
#include <iostream>
#include <limits>

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

        int bno, admno;
        switch (choice) {
            case 1:
                librarySystem.createBook();
                break;
            case 2:
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                librarySystem.showBook(bno);
                break;
            case 3:
                librarySystem.createStudent();
                break;
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
