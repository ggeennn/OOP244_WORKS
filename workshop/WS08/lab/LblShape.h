/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/18
 */
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"
#include "Utils.h"

namespace seneca {
    class LblShape : public Shape {
        char* m_label{}; 
    protected:
        const char* label() const { return m_label;} 
    public:

        LblShape() = default;
        LblShape(const char* label);

        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;

        void getSpecs(std::istream& is) override;

        virtual ~LblShape();
    };
}

#endif // !SENECA_LABELEDSHAPE_H
