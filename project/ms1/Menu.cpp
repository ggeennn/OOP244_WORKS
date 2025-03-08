/* Citation and Sources...
Final Project Milestone 1 
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Yicheng Wang
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#include <iostream> 
#include "Menu.h"
#include "Utils.h" 
#include "constants.h"

namespace seneca {
    MenuItem::MenuItem(const char* content, size_t indentation, size_t indentationSize, int rowNumber)
        : m_content(nullptr), m_indentation(indentation), m_indentationSize(indentationSize), m_rowNumber(rowNumber), m_isValid(true) {
        if (!content || ut.isspace(content) || indentation > 4 || indentationSize > 4 || rowNumber > MaximumNumberOfMenuItems) {
            setEmpty();
            return;
        }
        m_content = ut.alocpy(content);
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    void MenuItem::setEmpty() {
        delete[] m_content;
        m_content = nullptr;
        m_isValid = false;
    }

    MenuItem::operator bool() const {
        return m_isValid;
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (!m_isValid) {
            ostr << "??????????";
            return ostr;
        }

        for (size_t i = 0; i < m_indentation * m_indentationSize; ++i) {
            ostr << ' ';
        }

        if (m_rowNumber >= 0) {
            ostr.width(2); 
            ostr << m_rowNumber << "- ";
        }

        for (const char* p = m_content; *p; ++p) {
            if (!ut.isspace(*p)) {
                ostr << *p;
            }
        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const MenuItem& item) {
        item.display(ostr);
        return ostr;
    }
}
