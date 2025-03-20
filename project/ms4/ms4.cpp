/***********************************************************************
// OOP244 Project, milestone 4 : tester program
//
// File	ms4.cpp
// Version 1.0
// Date 2024-11-20
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;

void saveBill(Ordering& ord) {
   ofstream billtest("billTest.txt");
   ord.printBill(billtest);
}
void showSavedBill(const char* filename) {
   ifstream billtest(filename);
   char ch;
   while (billtest.get(ch) && cout << ch);
}
int main() {
   cout << "Testing Invalid Ordering if data file don't exist!" << endl;
   Ordering badord("drink.csv", "food.csv");
   if (badord) {
      cout << "The ordering should have been invalid" << endl;
   }
   else {
      cout << "Passed!" << endl;
   }
   Ordering ord("drinks.csv", "foods.csv");
   cout << "Testing list foods.................................." << endl;
   ord.listFoods();
   cout << "Testing list drinks................................." << endl;
   ord.ListDrinks();

   cout << "Testing order food.................................."
           "\nEnter:\n 1\n 1\n abc\n ---->" << endl;
   ord.orderFood();
   if (ord.noOfBillItems() == 1) {
      cout << "Passed!" << endl;
   }
   else {
      cout << "The number of bill times shoudl be 1!" << endl;
   }
   cout << "Testing order drink................................."
           "\nEnter:\n 1\n 1\n ---->" << endl;
   ord.orderDrink();
   if (ord.noOfBillItems() == 2) {
      cout << "Passed!" << endl;
   }
   else {
      cout << "The number of bill times shoudl be 2!" << endl;
   }
   cout << "Testing print bill on screen........................." << endl;
   ord.printBill(cout);
   cout << "Testing saving bill in a file........................" << endl;
   saveBill(ord);
   showSavedBill("billTest.txt");
   cout << "testing hassUnsavedBill()............................" << endl;
   if (ord.hasUnsavedBill()) {
      cout << "Passed hassUnsavedBill()!" << endl;
   }
   else{
      cout << "ord.hasUnsavedBill() should have returned true!" << endl;
   }
   cout << "testing restBill()..................................." << endl;
   ord.resetBill();
   if (ord.noOfBillItems()== 0 && !ord.hasUnsavedBill()) {
      showSavedBill("bill_1.txt");
   }
   else {
      cout << "Reset Bill should save the bill and reset the bill" << endl;
   }

   return 0;
}
