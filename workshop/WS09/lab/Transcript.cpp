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
        ut.alocpy(m_studentName, name); // 使用Utils工具安全分配内存
        m_studentNumber = stno;
    }

    Transcript::Transcript(const Transcript& other) : Marks(other) { // 调用基类拷贝构造
        ut.alocpy(m_studentName, other.m_studentName);
        m_studentNumber = other.m_studentNumber;
    }

    Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) { // 防止自赋值
            Marks::operator=(other); // 调用基类赋值运算符
            ut.alocpy(m_studentName, other.m_studentName);
            m_studentNumber = other.m_studentNumber;
        }
        return *this;
    }

    Transcript::~Transcript() {
        delete[] m_studentName; // 释放动态内存
    }

    std::ostream& Transcript::display(std::ostream& ostr) const {
        ostr << m_studentName << " (" << m_studentNumber << ")" << std::endl;
        ostr << "--------------------------------------------------------------------------" << std::endl;
        Marks::display(ostr); // 调用基类显示方法
        return ostr;
    }
}
