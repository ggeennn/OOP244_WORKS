/* Citation and Sources...
Final Project Milestone 5 
Module: food
Filename: food.h
Version 1.1
Author: Yicheng Wang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/28  food Module implemented
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <fstream>
#include "Billable.h"

namespace seneca {
    class Food : public Billable {
        bool m_ordered = false;
        bool m_child = false;
        char* m_customize = nullptr;
    public:
        Food()=default;
        Food(const Food&);
        Food& operator=(const Food&);
        ~Food();
        
        std::ostream& print(std::ostream& ostr= std::cout) const override;
        bool order() override;
        bool ordered() const override { return m_ordered; }
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };
}

#endif // FOOD_H
