/* Citation and Sources...
Final Project Milestone 5 
Module: main
Filename: main.cpp
Version 1.1
Author: Yicheng Wang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/28  main Module implemented
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#include <iostream>
#include "Ordering.h"
#include "Utils.h"
#include "Menu.h"

using namespace std;
using namespace seneca;

int main() {
    Ordering ordering("drinks.csv", "foods.csv");
    
    if (!ordering) {
        cout << "Failed to open data files or the data files are corrupted!\n";
        return 1;
    }

    Menu mainMenu("Seneca Restaurant", "End Program");
    mainMenu << "Order" << "Print Bill" << "Save & Start a New Bill" << "List Foods" << "List Drinks";

    Menu orderMenu("Order Menu", "Back to main menu", 1);
    orderMenu << "Food" << "Drink";

    do {
        switch (mainMenu.select()) {
        case 1:{ // Order
            size_t orderSelect=orderMenu.select();
            switch (orderSelect) {
               case 1:
                ordering.orderFood();
                break;
               case 2:
                ordering.orderDrink();
                break;
               case 0:
                break;
            }
            break;
        }
            
        case 2: // Print Bill
            ordering.printBill();
            break;
            
        case 3: // Start New Bill
            ordering.resetBill();
            break;
            
        case 4: // List Foods
            ordering.listFoods();
            break;
            
        case 5: // List Drinks
            ordering.ListDrinks();
            break;
            
        case 0: // Exit
            if (ordering.hasUnsavedBill()) {
                Menu confirmMenu("You have bills that are not saved. Are you sure you want to exit?", "No");
                confirmMenu << "Yes";
                if (confirmMenu.select() == 1) return 0;
            } else {
                return 0;
            }
        }
    } while (true);
}

