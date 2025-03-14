/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   int Utils::getInt() {  //using cin.peek()
      int value;
      bool valid;
      do {
         valid = true;
         std::string input;
         std::getline(std::cin, input);
         
         if (input.empty()) {
            std::cout << "You must enter a value: ";
            valid = false;
            continue;
         }
         
         try {
            size_t pos;
            value = std::stoi(input, &pos);
            if (pos != input.length()) {
               throw std::invalid_argument("Trailing characters");
            }
         } catch (...) {
            std::cout << (input.find_first_not_of("0123456789") != std::string::npos 
                         ? "Invalid integer: " : "Only an integer please: ");
            valid = false;
         }
      } while (!valid);
      return value;
   }

   int Utils::getInt(int min, int max) {
      int value;
      do {
         value = getInt();
         if (value < min || value > max) {
            std::cout << "Invalid value: [" << min << " <= value <= " 
                      << max << "], try again: ";
         }
      } while (value < min || value > max);
      return value;
   }
}