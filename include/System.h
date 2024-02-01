#ifndef SYSTEM_H
#define SYSTEM_H

#include "Book.h"
#include "Student.h"
#include <vector>
#include <unordered_map>

class System {
private:
    std::vector<Book> books;
    std::vector<Student> students;
    std::unordered_map<int, Book*> bookMap; // Maps book number to Book pointer for quick access
    std::unordered_map<int, Student*> studentMap; // Maps admission number to Student pointer

public:
    System();
    ~System();
    void createBook(int bno, int quant, const std::string& bname, const std::string& aname, const std::string& pname);
    void createStudent(const std::string& name, int admno);
    void issueBook(int admno, int bno);
    void returnBook(int admno, int bno);
};

#endif // SYSTEM_H
