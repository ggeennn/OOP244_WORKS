/* Citation and Sources...
Final Project Milestone 5 
Module: Ordering
Filename: Ordering.h
Version 1.1
Author: Yicheng Wang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/28  Ordering Module implemented
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef ORDERING_H
#define ORDERING_H

#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "Menu.h"
#include "constants.h"

namespace seneca
{
    class Ordering
    {
        Food *m_foods = nullptr;
        Drink *m_drinks = nullptr;
        Billable *m_billItems[MaximumNumberOfBillItems]{};
        size_t m_foodCnt = 0;
        size_t m_drinkCnt = 0;
        size_t m_billCnt = 0;
        size_t m_billNo = 1;

        void printBillTitle(std::ostream &) const;
        void printTotals(std::ostream &, double) const;
        size_t countRecords(const char *file) const;

        template<typename T>
        void listItems(const std::string& title, const T* items, size_t count) const;

        template<typename T>
        void orderItem(const std::string& menuTitle, const T* items, size_t itemCount);

    public:
        Ordering(const char *drinksFile, const char *foodsFile);
        ~Ordering();
        operator bool() const { return m_foods != nullptr && m_drinks != nullptr; }
        size_t noOfBillItems() const { return m_billCnt; }
        bool hasUnsavedBill() const{ return m_billCnt > 0; }
        void listFoods() const;
        void ListDrinks() const;
        void orderFood();
        void orderDrink();

        void printBill(std::ostream &ostr = std::cout) const;
        void resetBill();
    };

    template<typename T>
    void Ordering::listItems(const std::string& title, const T* items, size_t count) const {
        std::cout << title << "\n";
        std::cout << std::string(40, '=') << '\n';
        for(size_t i = 0; i < count; i++) {
            items[i].print(std::cout) << '\n';
        }
        std::cout << std::string(40, '=') << '\n';
    }

    template<typename T>
    void Ordering::orderItem(const std::string& menuTitle, const T* items, size_t itemCount) {
        Menu itemMenu(menuTitle.c_str(), "Back to Order", 2);
        for(size_t i = 0; i < itemCount; i++) {
            itemMenu << items[i];
        }
        
        size_t selection = std::cout << itemMenu;
        if(selection > 0 && m_billCnt < MaximumNumberOfBillItems) {
            m_billItems[m_billCnt] = new T(items[selection-1]);
            if(m_billItems[m_billCnt]->order()) {
                m_billCnt++;
            } else {
                delete m_billItems[m_billCnt];
                m_billItems[m_billCnt] = nullptr;
            }
        }
    }
}

#endif // ORDERING_H
