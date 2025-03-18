/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/18
 */
#include "Rectangle.h"
#include "Utils.h"
#include <iomanip>
#include <cstring>

namespace seneca
{
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char *label, int width, int height)
        : LblShape(label)
    {
        m_height = (height < 3) ? 3 : height;
        int minWidth = strlen(label) + 2;
        m_width = (width < minWidth) ? minWidth : width;
    }

    void Rectangle::getSpecs(std::istream &is)
    {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(); 
        is >> m_height;
        is.ignore(1000, '\n'); 
    }

    void Rectangle::draw(std::ostream &os) const
    {
        if (m_width > 0 && m_height > 0)
        {
            os << '+' << std::setw(m_width - 2) << std::setfill('-') << '-' << "+\n";
            os << '|' << std::left << std::setw(m_width - 2)<< std::setfill(' ') << label() << "|\n";
            for (int i = 0; i < m_height - 3; ++i)
            {
                os << '|' << std::setw(m_width - 2) << ' ' << "|\n";
            }
            os << '+' << std::setw(m_width - 2) << std::setfill('-') << '-' << "+"<< std::setfill(' ');
        }
    }
}