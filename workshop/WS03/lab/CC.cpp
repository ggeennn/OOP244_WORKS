/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/1/25
 */

#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }
   
bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
   return (strlen(name) > 2) &&
          (cardNo >= 4000000000000000ull && cardNo <= 4099999999999999ull) &&
          (cvv > 99 && cvv < 1000) &&
          (expMon > 0 && expMon < 13) &&
          (expYear > 23 && expYear < 33);
}

void CC::display() const{
   if(isEmpty()){
      cout << "Invalid Credit Card Record" << endl;
   }
   else{
      display(name, number, expYear, expMon, cvv);
   }
}

void CC::set(){
   name = nullptr;
   number = 0;
   cvv = 0;
   expMon = 0;
   expYear = 0;
}

void CC::set(const char* cc_name, 
         unsigned long long cc_no, 
         short cvv, 
         short expMon, 
         short expYear){
   cleanUp();
   if(validate(cc_name, cc_no, cvv, expMon, expYear)){
      if(!alocpy(name, cc_name)){
         cout << "Memory Allocation Failed!" << endl;
      }
      number = cc_no;
      this->cvv = cvv;
      this->expMon = expMon;
      this->expYear = expYear;
   }
}  

void CC::cleanUp(){
   freeMem(name);
   set();
}

bool CC::isEmpty() const{
   return (name == nullptr);
}
}