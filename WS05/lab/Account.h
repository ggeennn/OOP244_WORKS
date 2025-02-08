/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/2/8
 */
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      bool invalid() const{return m_number == -1;}
      bool isNew() const{return m_number == 0;}
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int number);
      Account& operator=(Account& src);
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& src);
      Account& operator>>(Account& dest);
   };

   double operator+(const Account& left, const Account& right);
   double operator+=(double& left, const Account& right);

}
#endif // SENECA_ACCOUNT_H_