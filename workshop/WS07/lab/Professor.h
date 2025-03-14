/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/11
 */
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"

namespace seneca {
    class Professor : public Employee {
        char* subjectName;  
        int numSections;    

    public:
        Professor();
        Professor(const char* name, const char* subject, int sections, size_t empNo, double salary);
        ~Professor();
        double devPay() const;
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& title(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<( std::ostream& ostr, const Professor& P );
    std::istream& operator>>( std::istream& istr, Professor& P );
}

#endif // !SENECA_PROFESSOR_H
