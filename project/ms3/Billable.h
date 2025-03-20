#ifndef BILLABLE_H
#define BILLABLE_H
#include <iostream>
#include <fstream>

namespace seneca {
    class Billable {
    protected:
        char* m_name{};
        double m_price{};
        
        void price(double value) { m_price = value; }
        void name(const char* name);
    public:
        Billable()=default;
        Billable(const Billable&);
        Billable& operator=(const Billable&);
        virtual ~Billable();
        virtual double price() const { return m_price; }

        virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream& read(std::ifstream& file) = 0;
        
        virtual operator const char*() const { return m_name; }
    };

    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);
}
#endif
