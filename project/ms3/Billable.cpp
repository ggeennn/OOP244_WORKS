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