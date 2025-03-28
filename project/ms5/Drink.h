/* Citation and Sources...
Final Project Milestone 5 
Module: drink
Filename: drink.h
Version 1.1
Author: Yicheng Wang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/28  drink Module implemented
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <fstream>
#include "Billable.h"

namespace seneca {
    class Drink : public Billable {
        char m_size = '\0'; // S/M/L/X
    public:
        Drink()=default;
        
        std::ostream& print(std::ostream& ostr= std::cout) const override;
        bool order() override;
        bool ordered() const override { return m_size != '\0'; }
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };
}

#endif
