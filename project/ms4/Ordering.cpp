#include <iostream>
#include <iomanip>
#include <fstream> 
#include "Ordering.h"
#include "Menu.h"
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
             << " " << std::string(29, '=') << '\n';
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
        std::cout << "List Of Available Meals\n";
        std::cout << std::string(40, '=') << '\n';
        for(size_t i = 0; i < m_foodCnt; i++) {
            m_foods[i].print(std::cout) << '\n';
        }
        std::cout << std::string(40, '=') << '\n';
    }

    void Ordering::ListDrinks() const {
        std::cout << "List Of Available Drinks\n";
        std::cout << std::string(40, '=') << '\n';
        for(size_t i = 0; i < m_drinkCnt; i++) {
            m_drinks[i].print(std::cout) << '\n';
        }
        std::cout << std::string(40, '=') << '\n';
    }

    void Ordering::orderFood() {
        Menu foodMenu("Food Menu", "Back to Order", 2);
        for(size_t i = 0; i < m_foodCnt; i++) {
            foodMenu << m_foods[i]; 
        }
        
        size_t selection = std::cout<< foodMenu;  
        if(selection > 0 && m_billCnt < MaximumNumberOfBillItems) {
            m_billItems[m_billCnt] = new Food(m_foods[selection-1]);  
            if(m_billItems[m_billCnt]->order()) {  
                m_billCnt++;
            } else {
                delete m_billItems[m_billCnt];
                m_billItems[m_billCnt] = nullptr;
            }
        }
    }

    void Ordering::orderDrink() {
        Menu drinkMenu("Drink Menu", "Back to Order", 2);
        for(size_t i = 0; i < m_drinkCnt; i++) {
            drinkMenu << m_drinks[i];
        }
        
        size_t selection = std::cout<<drinkMenu;
        if(selection > 0 && m_billCnt < MaximumNumberOfBillItems) {
            m_billItems[m_billCnt] = new Drink(m_drinks[selection-1]); 
            if(m_billItems[m_billCnt]->order()) {
                m_billCnt++;
            } else {
                delete m_billItems[m_billCnt];
                m_billItems[m_billCnt] = nullptr;
            }
        }
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
