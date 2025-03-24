/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/24
 */
#include "Transcript.h"
#include "Utils.h"

namespace seneca {
    Transcript::Transcript(const char* name, size_t stno) {
        ut.alocpy(m_studentName, name); 
        m_studentNumber = stno;
    }

    Transcript::Transcript(const Transcript& other) : Marks(other) { 
        ut.alocpy(m_studentName, other.m_studentName);
        m_studentNumber = other.m_studentNumber;
    }

    Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) { 
            Marks::operator=(other); 
            ut.alocpy(m_studentName, other.m_studentName);
            m_studentNumber = other.m_studentNumber;
        }
        return *this;
    }

    Transcript::~Transcript() {
        delete[] m_studentName; 
    }

    std::ostream& Transcript::display(std::ostream& ostr) const {
        ostr << m_studentName << " (" << m_studentNumber << ")" << std::endl;
        ostr << "--------------------------------------------------------------------------" << std::endl;
        Marks::display(ostr); 
        return ostr;
    }
}
