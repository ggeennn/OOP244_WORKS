/* Citation and Sources...
Final Project Milestone 1 
Module: Menu
Filename: Menu.h
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

#ifndef MENU_H
#define MENU_H

#include <iostream>

namespace seneca {
    class MenuItem {
    private:
        char* m_content;          
        size_t m_indentation;     
        size_t m_indentationSize; 
        int m_rowNumber;          
        bool m_isValid;           

        void setEmpty();          
    public:
        MenuItem(const char* content = nullptr, size_t indentation = 0, size_t indentationSize = 0, int rowNumber = -1);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& ostr, const MenuItem& item);
}

#endif 

