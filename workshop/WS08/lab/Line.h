/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/18
 */
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int m_length; 
    public:
        Line();
        Line(const char* label, int length);

        void draw(std::ostream& os) const override;
        void getSpecs(std::istream& is) override;
    };
}

#endif // !SENECA_LINE_H
