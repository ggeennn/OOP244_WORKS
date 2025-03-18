/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/18
 */
#include <iostream>
#include "LblShape.h"
#include "Utils.h"

namespace seneca {

    LblShape::LblShape(const char* label) {
        m_label = ut.alocpy(label); 
    }

    void LblShape::getSpecs(std::istream& is) {
        char buffer[81];
        is.getline(buffer, 81, ','); 
        ut.alocpy(m_label, buffer); 
    }

    LblShape::~LblShape() {
        delete[] m_label; 
    }


}