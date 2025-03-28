/* Citation and Sources...
Final Project Milestone 5 
Module: billable
Filename: billable.h
Version 1.1
Author: Yicheng Wang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/28  billable Module implemented
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef BILLABLE_H
#define BILLABLE_H
#include <iostream>
#include <fstream>

namespace seneca {
    class Billable {
    protected:
        char* m_name{};
        double m_price{};
        
        void price(double value) { m_price = value; }
        void name(const char* name);
    public:
        Billable()=default;
        Billable(const Billable&);
        Billable& operator=(const Billable&);
        virtual ~Billable();
        virtual double price() const { return m_price; }

        virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream& read(std::ifstream& file) = 0;
        
        virtual operator const char*() const { return m_name; }
    };

    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);
}
#endif
