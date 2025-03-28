/* Citation and Sources...
Final Project Milestone 5 
Module: billable
Filename: billable.cpp
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
#include "Billable.h"
#include "Utils.h"

namespace seneca {

    Billable::Billable(const Billable& other) {
        ut.alocpy(m_name, other.m_name);
        m_price = other.m_price;
    }

    Billable& Billable::operator=(const Billable& other) {
        if (this != &other) {
            delete[] m_name;
            m_name = nullptr;
            ut.alocpy(m_name, other.m_name);
            m_price = other.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    void Billable::name(const char* name) {
        ut.alocpy(m_name, name);
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    }
}