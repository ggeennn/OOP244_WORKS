/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/2/8
 */
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const {
      return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
   }

   Account::operator int() const {
      return m_number;
   }
 
   Account::operator double() const {
      return m_balance;
   }

   bool Account::operator~() const {
      return m_number == 0;
   }

   Account& Account::operator=(int number) {
      if(!invalid() && isNew()){
         if(number >= 10000 && number <= 99999){
            m_number = number;
         }

         else{
            setEmpty();
         }
      }
      return *this;
   }

   Account& Account::operator=(Account& src) {
      if(!invalid() && isNew() && src){
         m_number = src.m_number;
         m_balance = src.m_balance;
         src.m_number = 0;
         src.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator+=(double amount) {
      if(*this && amount > 0){
         m_balance += amount;
      }
      return *this;
   }

   Account& Account::operator-=(double amount) {
      if(*this && amount > 0 && m_balance >= amount){
         m_balance -= amount;
      }
      return *this;
   }

   Account& Account::operator<<(Account& src) {
      if(*this && src && this != &src){
         m_balance += src.m_balance;
         src.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& dest) {
      if(*this && dest && this != &dest){
         dest.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   double operator+(const Account& left, const Account& right) {
      if(left && right){
         return (double)left + (double)right;
      }
      return 0;
   }

   double operator+=(double& left, const Account& right) {
      if(right){
         left += (double)right;
      }
      return left;
   }


}