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
#include "Menu.h"
#include "Utils.h" // 引入 Utils 模块
#include <iostream> // 仅使用 iostream

namespace seneca {
    // 构造函数
    MenuItem::MenuItem(const char* content, unsigned int indentation, unsigned int indentationSize, int rowNumber)
        : m_content(nullptr), m_indentation(indentation), m_indentationSize(indentationSize), m_rowNumber(rowNumber), m_isValid(true) {
        // 使用 Utils 模块验证内容
        if (!content || ut.isspace(content) || indentation > 4 || indentationSize > 4 || rowNumber > 20) {
            setEmpty();
            return;
        }

        // 使用 Utils 模块动态分配内存并复制内容
        m_content = ut.alocpy(content);
    }

    // 析构函数
    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    // 将对象设置为空状态
    void MenuItem::setEmpty() {
        delete[] m_content;
        m_content = nullptr;
        m_isValid = false;
    }

    // 类型转换重载
    MenuItem::operator bool() const {
        return m_isValid;
    }

    // 显示功能
    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (!m_isValid) {
            ostr << "??????????";
            return ostr;
        }

        // 输出缩进
        for (unsigned int i = 0; i < m_indentation * m_indentationSize; ++i) {
            ostr << ' ';
        }

        // 输出行号（如果有）
        if (m_rowNumber >= 0) {
            ostr.width(2); // 使用 iostream 的 width() 方法设置行号宽度为 2
            ostr << m_rowNumber << "- ";
        }

        // 输出内容，跳过空白字符
        for (const char* p = m_content; *p; ++p) {
            if (!ut.isspace(*p)) { // 使用 Utils 模块检查是否为空白字符
                ostr << *p;
            }
        }

        return ostr;
    }

    // 实现 << 操作符重载
    std::ostream& operator<<(std::ostream& ostr, const MenuItem& item) {
        return item.display(ostr);
    }
}
