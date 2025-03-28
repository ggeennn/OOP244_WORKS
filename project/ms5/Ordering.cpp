/* Citation and Sources...
Final Project Milestone 5 
Module: Ordering
Filename: Ordering.cpp
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
#include <iostream>
#include <iomanip>
#include <fstream> 
#include "Ordering.h"
#include "Utils.h" 


namespace seneca {

    Ordering::Ordering(const char* drinksFile, const char* foodsFile) {
        m_foodCnt = countRecords(foodsFile);
        m_drinkCnt = countRecords(drinksFile);
        
        std::ifstream foodFile(foodsFile);
        std::ifstream drinkFile(drinksFile);
        
        if (!foodFile || !drinkFile) {
            m_foods = nullptr;
            m_drinks = nullptr;
            m_foodCnt = m_drinkCnt = 0;
            return;
        }
        
        m_foods = new Food[m_foodCnt];
        m_drinks = new Drink[m_drinkCnt];
        
        bool valid = true;
        for(size_t i = 0; valid && i < m_foodCnt; i++) {
            if(!m_foods[i].read(foodFile)) valid = false;
        }
        for(size_t i = 0; valid && i < m_drinkCnt; i++) {
            if(!m_drinks[i].read(drinkFile)) valid = false;
        }
        
        if(!valid) {
            delete[] m_foods;  
            delete[] m_drinks;
            m_foods = nullptr;
            m_drinks = nullptr;
            m_foodCnt = m_drinkCnt = 0;
        }
    }

    Ordering::~Ordering() {
        delete[] m_foods;
        delete[] m_drinks;
        for(size_t i = 0; i < m_billCnt; i++) {
            delete m_billItems[i];  
        }
    }

    void Ordering::printBillTitle(std::ostream& ostr) const {
        ostr << "Bill # " << std::setw(3) << std::setfill('0') << m_billNo
             << " " << std::string(29, '=')<<std::setfill(' ')  << '\n';
    }

    void Ordering::printTotals(std::ostream& ostr, double total) const {
        double tax = total * Tax;
        ostr << std::fixed << std::setprecision(2);
        ostr << "                     Total: " << std::setw(12) << total << '\n';
        ostr << "                     Tax: " << std::setw(14) << tax << '\n';
        ostr << "                     Total+Tax: " << std::setw(8) << total + tax << '\n';
        ostr << std::string(40, '=') << '\n';
    }

    size_t Ordering::countRecords(const char* file) const {
        size_t count = 0;
        std::ifstream inFile(file);
        if(inFile) {
            char ch;
            while(inFile.get(ch)) {
                if(ch == '\n') count++;
            }
        }
        return count;
    }

    void Ordering::listFoods() const {
        listItems("List Of Available Meals", m_foods, m_foodCnt);
    }

    void Ordering::ListDrinks() const {
        listItems("List Of Available Drinks", m_drinks, m_drinkCnt);
    }

    void Ordering::orderFood() {
        orderItem("Food Menu", m_foods, m_foodCnt);
    }

    void Ordering::orderDrink() {
        orderItem("Drink Menu", m_drinks, m_drinkCnt);
    }

    void Ordering::printBill(std::ostream& ostr) const {
        double total = 0;
        printBillTitle(ostr);
        for(size_t i = 0; i < m_billCnt; i++) {
            m_billItems[i]->print(ostr); 
            ostr<<std::endl; 
            total += *m_billItems[i];     
        }
        printTotals(ostr, total);
    }

    void Ordering::resetBill() {
        char filename[50];
        ut.makeBillFileName(filename, m_billNo);  
        
        std::ofstream billFile(filename);
        if(billFile) {
            printBill(billFile);
            std::cout << "Saved bill number " << m_billNo << '\n';
        }
        
        for(size_t i = 0; i < m_billCnt; i++) {
            delete m_billItems[i];
        }
        m_billCnt = 0;
        m_billNo++;
        
        std::cout << "Starting bill number " << m_billNo << '\n';
    }

}
