/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/18
 */
#include "Shape.h"
#include <iostream>

namespace seneca
{

    std::ostream &operator<<(std::ostream &os, const Shape &shape)
    {
        shape.draw(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Shape &shape)
    {
        shape.getSpecs(is);
        return is;
    }
}