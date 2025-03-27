#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Drink.h"
#include "Utils.h"
#include "Menu.h"

namespace seneca {


    std::ostream& Drink::print(std::ostream& ostr) const {
        ostr.width(28);
        ostr.fill('.');
        ostr << std::left << (m_name ? m_name : ".....");
        
        switch(m_size) {
            case 'S': ostr << "SML.."; break;
            case 'M': ostr << "MID.."; break;
            case 'L': ostr << "LRG.."; break;
            case 'X': ostr << "XLR.."; break;
            default:  ostr << ".....";
        }
        
        ostr.width(7);
        ostr.fill(' ');
        ostr << std::right << std::fixed << std::setprecision(2) << this->price();
        return ostr;
    }

    bool Drink::order() {
        Menu sizeMenu("Drink Size Selection", "Back", 3);
        sizeMenu << "Small" << "Medium" << "Large" << "Extra Large";
        
        size_t choice = std::cout <<sizeMenu;
        if(choice == 0) {
            m_size = '\0';
            return false;
        }
        
        m_size = "SMLX"[choice-1];
        return true;
    }

    std::ifstream& Drink::read(std::ifstream& file) {
        std::string name;
        double price;
        if (std::getline(file, name, ',') && (file >> price)) {
            this->name(name.c_str());
            this->Billable::price(price);
            m_size = '\0';
            file.ignore();
        }
        return file;
    }

    double Drink::price() const {
        if (!ordered()) return m_price;
        switch (m_size) {
            case 'S': return m_price * 0.5;
            case 'M': return m_price * 0.75;
            case 'L': return m_price;
            case 'X': return m_price * 1.5;
            default:  return m_price;
        }
    }
}
