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
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "constants.h"

namespace seneca {
    class Menu;  // Forward declaration

    class MenuItem {
        char* m_content;
        size_t m_indentation;
        size_t m_indentationSize;
        int m_rowNumber;
        bool m_isValid;

        void setEmpty();
        MenuItem(const char* content = nullptr, size_t indentation = 0, 
                size_t indentationSize = 0, int rowNumber = -1);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();
        
        friend class Menu;  // Make Menu a friend
    public:
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& ostr, const MenuItem& item);

    class Menu {
        MenuItem m_title{};
        MenuItem m_exit;
        MenuItem m_prompt;
        MenuItem* m_items[MaximumNumberOfMenuItems]{};
        size_t m_indent = 0;
        size_t m_indentSize = 3;
        size_t m_count=0;

    public:
        Menu(const char* title, const char* exitText = "Exit", 
             size_t indent = 0, size_t indentSize = 3);
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        ~Menu();
        
        Menu& operator<<(const char* item);
        size_t select() const;
        operator bool() const;
    };

    size_t operator<<(std::ostream& os, const Menu& menu);
}

#endif
