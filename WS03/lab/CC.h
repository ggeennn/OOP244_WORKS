/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/1/24
 */
#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      char* name;
      short cvv;
      short expMon;  
      short expYear;
      unsigned long long number;
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      void prnNumber(unsigned long long no) const;
      bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
   public:
   
   
   };

}
#endif // !SENECA_CC_H_


