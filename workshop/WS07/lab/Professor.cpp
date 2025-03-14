/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/11
 */
#include <iostream>
#include "Professor.h"
#include "Utils.h"

using namespace std;
namespace seneca {

    Professor::Professor() : subjectName(nullptr), numSections(0) {}

    Professor::Professor(const char* name, const char* subject, int sections, size_t empNo, double salary)
        : Employee(name, empNo, salary), numSections(sections) {
        subjectName = ut.alocpy(subject);
    }

    Professor::~Professor() {
        delete[] subjectName;
    }

    double Professor::devPay() const {
        return salary() * 0.01 * numSections;
    }

    std::istream& Professor::read(std::istream& istr) {
        Employee::read(istr);  
        char tempSubject[1024];
        istr.ignore(); 
        istr.getline(tempSubject, 1024, ',');
        ut.alocpy(subjectName, tempSubject);
        istr >> numSections;
        // istr.ignore(1000，'\n');  already implemented in main line#46: P.read(file).ignore(1000, '\n');
        return istr;
    }

    std::ostream& Professor::write(std::ostream& ostr) const {
        Employee::write(ostr);  
        ostr << " ";
        char sub2print[21]{};
        if(subjectName) ut.strcpy(sub2print, subjectName,20);
        ostr.width(20);
        ostr.setf(ios::left);
        ostr << sub2print << " | ";
        ostr.unsetf(ios::left);
        ostr.width(5);
        ostr.setf(ios::right);
        ostr << numSections << " | ";
        ostr.width(8);
        ostr.precision(2);
        ostr << devPay() << " |";
        ostr.unsetf(ios::right);
        return ostr;
    }

    std::ostream& Professor::title(std::ostream& ostr) const {
        Employee::title(ostr); 
        ostr << " Teaching Subject     | Sec # | $Dev Pay |";
        return ostr;
    }

    std::ostream& operator<<( std::ostream& ostr, const Professor& P ){ 
        return P.write(ostr);
    }
    std::istream& operator>>( std::istream& istr, Professor& P ){ 
        return P.read(istr);
    }
}
