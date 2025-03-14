/* Citation and Sources...
Final Project Milestone 2 
Module: Menu
Filename: Menu.cpp
Version 1.1
Author: Yicheng Wang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/15  Menu Module implemented
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

namespace seneca {
    MenuItem::MenuItem(const char* content, size_t indentation, size_t indentationSize, int rowNumber)
        : m_content(nullptr), m_indentation(indentation), m_indentationSize(indentationSize), m_rowNumber(rowNumber), m_isValid(true) {
        if (!content || ut.isspace(content) || indentation > 4 || indentationSize > 4 || rowNumber > static_cast<int>(MaximumNumberOfMenuItems)) {
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

        bool leading = true;
        for (const char* p = m_content; *p; ++p) {
            if (leading && ut.isspace(*p)) {
                continue;
            }
            leading = false;
            ostr << *p;
        }

        return ostr;
    }
    
    std::ostream& operator<<(std::ostream& ostr, const MenuItem& item) {
        item.display(ostr);
        return ostr;
    }

    Menu::Menu(const char* title, const char* exitText, size_t indent, size_t indentSize) 
        : m_title(title, indent, indentSize, -1), 
          m_exit(exitText, indent, indentSize, 0),
          m_prompt("> ", indent, indentSize, -1),
          m_indent(indent),
          m_indentSize(indentSize) {}


    Menu::~Menu() {
        for (size_t i = 0; i < m_count; ++i) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* item) {
        if (m_count < MaximumNumberOfMenuItems && item && item[0] != '\0') {
            m_items[m_count] = new MenuItem(item, m_indent, m_indentSize, m_count + 1);
            ++m_count;
        }
        return *this;
    }

    size_t Menu::select() const {
        if (m_title) std::cout << m_title << std::endl;
        
        for (size_t i = 0; i < m_count; ++i) {
            std::cout << *m_items[i] << std::endl;
        }
        std::cout << m_exit << std::endl;
        
        std::cout << m_prompt;
        return ut.getInt(0, m_count);
    }

    Menu::operator bool() const {
        return m_count > 0;
    }

    size_t operator<<(std::ostream& os, const Menu& menu) {
        if (&os == &std::cout) {
            return menu.select();
        }
        return 0;
    }
}
