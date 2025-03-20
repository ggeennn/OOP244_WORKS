#ifndef ORDERING_H
#define ORDERING_H

#include "Food.h"
#include "Drink.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>
namespace seneca
{
    class Ordering
    {
        Food *m_foods = nullptr;                           // 食物动态数组
        Drink *m_drinks = nullptr;                         // 饮料动态数组
        Billable *m_billItems[MaximumNumberOfBillItems]{}; // 账单项指针数组
        size_t m_foodCnt = 0;                              // 食物数量
        size_t m_drinkCnt = 0;                             // 饮料数量
        size_t m_billCnt = 0;                              // 账单项数量
        size_t m_billNo = 1;                               // 账单序列号

        // 私有方法
        void printBillTitle(std::ostream &) const;
        void printTotals(std::ostream &, double) const;
        size_t countRecords(const char *file) const;

    public:
        Ordering(const char *drinksFile, const char *foodsFile);
        ~Ordering();
        void listFoods() const;
        void ListDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream &ostr = std::cout) const;
        void resetBill();
        bool hasUnsavedBill() const;
        operator bool() const;
        size_t noOfBillItems() const; // 返回当前账单中的项目数量
                                      // ... 其他公共方法声明
    };
}

#endif // ORDERING_H

