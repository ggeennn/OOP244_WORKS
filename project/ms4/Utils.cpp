/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.cpp
// Version 0.2
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Yicheng Wang    2025/3/14       getInt method implemented
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
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

   int Utils::getInt() {
      int value;
      bool valid;
      do {
         valid = true;

         if (std::cin.peek() == '\n') {
            std::cout << "You must enter a value: ";
            std::cin.ignore();  
            valid = false;
            continue;
         }


         std::cin >> value;
         

         if (std::cin.fail()) {
            std::cin.clear();  
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid integer: ";
            valid = false;
         }
         else if (std::cin.peek() != '\n' && std::cin.peek() != EOF) {
            std::cin.ignore(1000, '\n');
            std::cout << "Only an integer please: ";
            valid = false;
         }

         else {
            std::cin.ignore(1000, '\n');
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

char* Utils::makeBillFileName(char* filename, size_t billNo) {

   size_t temp = billNo;
   int cnt = 5, i = 0;
   int length = 0;
   // set name prefix
   while ("bill_"[i]) {
      filename[i] = "bill_"[i];
      i++;
   }
   // Calculate the number of digits
   do {
      cnt++;
      temp /= 10;
   } while (temp > 0);
   length = cnt;
   // Convert each digit to character from the end
   temp = billNo;
   while (temp > 0) {
      filename[--cnt] = (temp % 10) + '0';
      temp /= 10;
   }
   // Handle the case when billNo is 0
    if (!billNo) {
       filename[--cnt] = '0';
    }
   // Attach .txt to the end of the file name
   for (i = 0; ".txt"[i]; i++) {
      filename[length++] = ".txt"[i];
   }
   filename[length] = '\0';
   return filename;

}

}