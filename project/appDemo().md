```cpp
void appDemo() {
   size_t appSel{}, ordSel{};
   Menu appMenu("Seneca Resturant", "End Program");
   appMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
   Menu orderMenu("Order Menu", "Back to main menu", 1);
   orderMenu << "Food" << "Drink";
   cout << endl << "***********************************************************************" << endl;

   do {
      switch (appSel = appMenu.select()) {
      case 1:
         do {
            switch (ordSel = orderMenu.select()) {
            case 1:
               cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                  "Start Food Ordering Process!!!\n"
                  "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
               break;
            case 2:
               cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                  "Start Drink Ordering Process!!!\n"
                  "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
               break;
            }
         } while (ordSel);
         break;
      // ... other cases ...
      }
   } while (appSel);
   cout << "End Final Milestone Demo **********************************************" << endl;
}
```