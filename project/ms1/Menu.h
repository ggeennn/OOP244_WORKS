/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author: John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2024/?/?  Preliminary release
2024/?/?  Debugged DMA
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
    class MenuItem {
    private:
        char* m_content;          // 动态存储菜单项内容
        unsigned int m_indentation; // 缩进数量
        unsigned int m_indentationSize; // 每个缩进的字符大小
        int m_rowNumber;          // 菜单项的行号
        bool m_isValid;           // 标记对象是否有效

        void setEmpty();          // 将对象设置为空状态
    public:
        // 构造函数
        MenuItem(const char* content = nullptr, unsigned int indentation = 0, unsigned int indentationSize = 0, int rowNumber = -1);

        // 规则三：禁止拷贝构造函数和拷贝赋值运算符
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;

        // 析构函数
        ~MenuItem();

        // 类型转换重载
        operator bool() const;

        // 显示功能
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };

    // 重载 << 操作符
    std::ostream& operator<<(std::ostream& ostr, const MenuItem& item);
}

#endif // !MENU_H

