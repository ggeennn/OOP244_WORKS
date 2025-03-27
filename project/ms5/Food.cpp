#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Food.h"
#include "Utils.h"
#include "Menu.h"

namespace seneca {

Food::Food(const Food& other) : Billable(other) {
    m_ordered = other.m_ordered;
    m_child = other.m_child;
    ut.alocpy(m_customize, other.m_customize);
}

Food& Food::operator=(const Food& other) {
    if (this != &other) {
        Billable::operator=(other);
        delete[] m_customize;
        m_customize = nullptr;
        m_ordered = other.m_ordered;
        m_child = other.m_child;
        ut.alocpy(m_customize, other.m_customize);
    }
    return *this;
}



    Food::~Food() {
        delete[] m_customize;
    }

    std::ostream& Food::print(std::ostream& ostr) const {
        ostr.width(28);
        ostr.fill('.');
        ostr << std::left << (m_name ? m_name : ".....");
        
        if(ordered()) {
            ostr << (m_child ? "Child" : "Adult");
        } else {
            ostr << ".....";
        }
        
        ostr.width(7);
        ostr.fill(' ');
        ostr << std::right << std::fixed << std::setprecision(2) << this->price();
        
        if(&ostr == &std::cout && m_customize) {
            ostr << " >> " << m_customize;
        }
        return ostr;
    }

    bool Food::order() {
        Menu portionMenu("Food Size Selection", "Back", 3);
        portionMenu << "Adult" << "Child";
        
        size_t choice = std::cout <<portionMenu;
        if(choice == 0) {
            m_ordered = false;
            ut.alocpy(m_customize, nullptr);
            return false;
        }
        
        m_ordered = true;
        m_child = (choice == 2);
        
        std::cout << "Special instructions\n> ";
        std::string instructions;
        std::getline(std::cin, instructions);
        ut.alocpy(m_customize, instructions.empty() ? nullptr : instructions.c_str());
        
        return true;
    }

    std::ifstream& Food::read(std::ifstream& file) {
        std::string name;
        double price;
        if (std::getline(file, name, ',') && (file >> price)) {
            this->name(name.c_str());
            this->Billable::price(price);
            m_child = false;
            m_ordered = false;
            delete m_customize;
            m_customize = nullptr;
            file.ignore();
        }
        return file;
    }

    double Food::price() const {
        return ordered() && m_child ? m_price * 0.5 : m_price;
    }
}
