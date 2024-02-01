#include "../include/System.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

void System::showBook(int bno) const {
    auto it = std::find_if(books.begin(), books.end(), [bno](const Book& book) { return book.bno == bno; });
    if (it != books.end()) {
        const auto& book = *it;
        std::cout << "Book Number: " << book.bno << "\n"
                  << "Name: " << book.bname << "\n"
                  << "Author: " << book.aname << "\n"
                  << "Publication: " << book.pname << "\n"
                  << "Quantity: " << book.quant << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }
}

void System::showStudent(){
    
}