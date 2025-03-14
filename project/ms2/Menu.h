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
