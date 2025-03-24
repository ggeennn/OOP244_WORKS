#ifndef ORDERING_H
#define ORDERING_H

#include <iostream>
#include "Food.h"
#include "Drink.h"
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
}

#endif // ORDERING_H
