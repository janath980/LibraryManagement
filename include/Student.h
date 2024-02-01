#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    int bno; // Book number issued to the student, 0 if no book is issued
    int token; // 1 if a book is issued, otherwise 0
    int admno; // Admission number

    // Constructor for convenience
    Student(std::string name, int admno, int bno = 0, int token = 0)
        : name(std::move(name)), admno(admno), bno(bno), token(token) {}
};

#endif // STUDENT_H
