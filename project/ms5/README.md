# Project: Dine-In Digital - A Restaurant Ordering System
  

## Objective  
In this project, you will build an application that enables waiters to take customer orders for food and drinks and generate a bill upon order completion. Each bill will have a unique number, and once an order is finalized, the bill will be saved in a separate file named according to its bill number.

### Milestones  

| Milestone | Revision | Comments | Walkthrough |
|-----------|:--------:|:--------:|:-----------:|
| [MS1](#milestone-1) | V1.0 | | [video](https://youtu.be/lqJI57TdSpA) |
| [MS2](#milestone-2) | V1.1 | ms2.cpp had a typo and it is fixed | [video](https://youtu.be/lymXEXn6eh0) |
| [MS3](#milestone-3) | V1.0 | | [video](https://youtu.be/P5y-vpk37mU)|
| [MS4](#milestone-4) | V0.9 | | |
| [MS5](#milestone-5-the-final-milestone) | V0.9 | | |

For this project, you will develop an application that enables waiters to take customer orders for food and drinks and generate a bill upon order completion.

Each bill will be numbered, and after an order is finalized, a copy of the bill will be saved in a separate file titled with the corresponding bill number.

---

## Milestone Due Dates  
This project consists of **five milestones**, each with a **specific due date**. The due dates are based on the workload required for each milestone.

### **Final Project Mark and Due Dates**  

| Milestone | Mark | Due Date | Submission Policy |
|:---------:|:----:|:--------:|------------------|
| MS1 | 10% | Mar 9 | Mandatory to submit by Apr 15.<br>Full marks awarded if submitted within one week late. **0% after the due date.** |
| MS2 | 10% | Mar 16 | Mandatory to submit by Apr 15.<br>Full marks awarded if submitted within one week late. **0% after the due date.** |
| MS3 | 10% | Mar 26 | Mandatory to submit by Apr 15.<br>Full marks awarded if submitted within one week late. **0% after the due date.** |
| MS4 | 10% | Apr 3 | Mandatory to submit by Apr 15.<br>Full marks awarded if submitted within one week late. **0% after the due date.** |
| MS5 | 60% | Apr 10 | See details below. |

> To facilitate the final project submission and allow partial submissions, **Milestone 5** is divided into **six smaller submissions**. Each submission is worth **10% of the project mark**.  
> **Your project will only be marked if you have submitted all four milestones and at least one of the six submissions of Milestone 5.**

### **Milestone 5 Submissions**  

| Submission | Mark | Due Date | Submission Policy |
|------------|:----:|:--------:|------------------|
| m51 (List Food and Drink) | 10% | Apr 10 | 10% penalty per day late, up to 5 days. |
| m52 (Order Drink) | 10% | Apr 10 | 10% penalty per day late, up to 5 days. |
| m53 (Order Food) | 10% | Apr 10 | 10% penalty per day late, up to 5 days. |
| m54 (Display Bill) | 10% | Apr 10 | 10% penalty per day late, up to 5 days. |
| m55 (Reset, Exit, and Save Bill) | 10% | Apr 10 | 10% penalty per day late, up to 5 days. |
| m56 (Foolproofing and Bad Data File) | 10% | Apr 10 | 10% penalty per day late, up to 5 days. |

> The **first four milestones** will not be marked based on code correctness but rather on **successful submission** and **timeliness**.  
> You may modify or debug your previous code as you progress through the milestones.  
> **Only Milestone 5 will be evaluated based on code quality.**  

If you require feedback on any of the first four milestones, you must request it from your professor.

### **Submission Rejection Date: April 15**  

**NOTE:**  
- Your **entire project will receive a mark of zero** if **any of the first four milestones are not submitted** by the rejection date.  
- For your project to be marked, you must submit **all four milestones** and at least **one of the six submissions** of Milestone 5 **before the rejection date**.  

---

## **Checking Milestone Due Dates**  
You can check the due date of each milestone using the `-due` flag in the submission command:

```bash
~profname.proflastname/submit 2??/prj/m? -due
```
- Replace `2??` with the **subject code**.  
- Replace `m?` with the **milestone number**.  

---

## **Citation and Sources**  

When submitting your work, all files must include **full student information** and **citation details**. See the following example:

```cpp
/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author: John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2024/?/?  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
```

**Failure to include the above citation** in any of your files will result in **a mark of zero** for that submission.

If you **borrow any functions or code snippets** from another source (even your professor), you must **add a citation comment** for the specific function or code in addition to the **Citation and Sources** comment at the beginning of the file.  

### **Example Citation for Borrowed Code:**
```cpp
// The following code is copied from Professor John Doe's class notes.
/// <summary>
/// Reads an unlimited number of characters from an input stream dynamically, resizing as needed.
/// </summary>
/// <param name="istr">Reference to the input stream to read from.</param>
/// <returns>Pointer to a dynamically allocated C-string containing the read characters.</returns>
char* Utils::read(istream& istr) const {
    ...
    return temp; 
}
```

> You **do not** need to cite functions provided as part of the project template.

---

## **Compiling and Testing Your Program**  
All code must be compiled using the following command on **Matrix**:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: Reports all warnings.  
- `-std=c++11`: Uses the C++11 standard.  
- `-g`: Includes debugging symbols for better `valgrind` reports.  
- `-o ws`: Names the compiled application `ws`.  

### **Checking for Memory Leaks**
To check for possible memory leaks, run:

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```
---

## Project Implementation Notes: **Very Important, Read Carefully**  

- All code written in this project should be within the `seneca` namespace.  
- You are free and encouraged to add any **attributes (member variables), functions, and methods (member functions)** you find necessary to complete your code. If you are unsure about your strategy for adding functionalities and properties to your classes, ask your professor for advice.  
- If you add methods that are **not called outside the scope of the class**, make sure they are **private**.  

- Unless you are given a specific definition, **name variables and functions yourself**. Use **meaningful** names and follow the **naming conventions** instructed by your professor. **Using misleading or unclear names will result in a penalty.**  

- When creating methods (member functions), ensure they are marked **`const`** if they **do not modify the class**.  

- When passing an object or variable by **address or reference**, if it is **not meant to be modified**, pass it as a **constant pointer or reference**.  

- If an **empty state** is required for an object, it is considered an **"invalid" empty state**, and objects in this state should be **rendered unusable**.  

- A module called **`Utils`** is included in the project. It contains a few predefined methods that you can use.  
  - You are allowed to **add your own custom functions and classes** to the `Utils` module for use throughout the project.  

- You may **reuse and copy** any **code provided by your professor**, functions from **workshops, previous projects, or other subjects** in the `Utils` module with no mark reduction, but you **must include a citation**.  

---


# Project Modules Overview

The project is divided into six main modules and a main module that launches the application:

1. Utils
2. Menu
3. Billable
4. Food
5. Drink
6. Ordering
7. main


## Utils
This module should include utility functions used throughout the project to simplify development. For example:

- Functions for dynamic memory allocation for C-strings.
- Foolproof input handling functions (e.g., to ensure valid data entry).
- Other common helper functions to prevent code duplication.


## Menu
In this module, unlike the other modules you have created, there are two classes:

- `MenuItem` Class: Represents individual items on the menu.
- `Menu` Class: Manages a collection of `MenuItem` objects and allows the user to select items from the menu.

> You will implement member functions and operators that handle adding, removing, and displaying MenuItem objects and facilitate user interaction for selection.

 `MenuItem` and `Menu`. The `Menu` class owns a series of `MenuItem` objects and provides selection facilities for the user. 

## Billable
Abstract Base Class: This class serves as a foundation for all items that can be billed (e.g., food and drinks). 

It will define common interfaces (pure virtual functions) that derived classes must implement.

## Food

Derived Class: Inherits from Billable and represents a food item. This class should allow for different portion sizes, such as:

- Child portion
- Adult portion

## Drink

Derived Class: Inherits from Billable and represents a drink item. It should support various sizes:

- Small
- Medium
- Large
- Extra Large

## Ordering

This module manages the ordering process and will include methods for:

- Loading available foods and drinks from data files.
- Displaying food and drink lists separately.
- Taking customer orders (interacting with the Menu class).
- Generating and printing the bill.
- Saving a copy of the bill to a file named after the bill number.

## Main. 

The main module should initialize and coordinate the program by:

- Creating an Ordering object.
- Handling user interactions (as the waiter) to navigate the ordering process.
- Calling methods from the Ordering class to execute actions based on user input.


# Milestone 5: The Final Milestone  

In this milestone, you will use all the modules you have created so far to build a complete application for the "Dine-In Digital" system. This milestone brings together the logic for menu navigation, order processing, bill handling, and dynamic memory management.  

The goal is to create a program that mimics the behavior demonstrated in the `appDemo()` function provided earlier. Follow the instructions below to structure your program and meet the milestone's requirements.  

---

## Program Requirements  

Your program should use the `Menu` and `Ordering` modules to create a fully functioning application that supports the following tasks:  

---

### Initialization  

1. **Data Files**:  
   - Your program must load the food and drink data from two CSV files:  
     - `"drinks.csv"` for drinks.  
     - `"foods.csv"` for food items.  
   - Pass the file names to the `Ordering` class during initialization.  

2. **Validation**:  
   - If the `Ordering` object fails to load the data (i.e., it enters a safe empty state), display an error message:  
     ```text
     Failed to open data files or the data files are corrupted!
     ```  
   - Terminate the program if the data files are not loaded successfully.  

---

### Menus  

#### Main Menu  

- **Menu Title**: `"Seneca Restaurant"`  
- **Exit Option**: `"End Program"`  
- **Menu Options**:  
  1. **Order**  
  2. **Print Bill**  
  3. **Start a New Bill**  
  4. **List Foods**  
  5. **List Drinks**  

#### Sub-Menu for Ordering  

- **Menu Title**: `"Order Menu"`  
- **Exit Option**: `"Back to main menu"`  
- **Menu Options**:  
  1. **Food**  
  2. **Drink**  

#### Confirmation Menu  

- **Menu Title**: `"You have bills that are not saved. Are you sure you want to exit?"`  
- **Exit Option**: `"No"`  
- **Menu Option**:  
  1. **Yes**  

---

### Menu Functionality  

1. **Order Food**  
   - When the "Food" option is selected from the order sub-menu:  
     - Call the `orderFood` method of the `Ordering` object to handle food ordering.  

2. **Order Drink**  
   - When the "Drink" option is selected from the order sub-menu:  
     - Call the `orderDrink` method of the `Ordering` object to handle drink ordering.  

3. **Print Bill**  
   - When the "Print Bill" option is selected from the main menu:  
     - Call the `printBill` method of the `Ordering` object to print the current bill to the console.  

4. **Start a New Bill**  
   - When the "Start a New Bill" option is selected:  
     - Call the `resetBill` method of the `Ordering` object to save the current bill to a file and start a new one.  

5. **List Foods**  
   - When the "List Foods" option is selected:  
     - Call the `listFoods` method of the `Ordering` object to display all food items.  

6. **List Drinks**  
   - When the "List Drinks" option is selected:  
     - Call the `listDrinks` method of the `Ordering` object to display all drink items.  

---

### Program Exit  

1. **Unsaved Bills Warning**:  
   - If the user attempts to exit the program (selects "End Program") while there are unsaved items in the bill:  
     - Display a confirmation menu asking:  
       ```text
       You have bills that are not saved. Are you sure you want to exit?
       ```  
     - The menu should have the following options:  
       1. **Yes**  
       0. **No**  

   - If the user selects "No," return to the main menu.  
   - If the user selects "Yes," terminate the program.  

2. **Normal Exit**:  
   - If there are no unsaved bills, allow the program to terminate without additional prompts.  

---

### User Input Validation  

Your program should use foolproof input handling for all menu interactions. This ensures the program does not crash due to invalid user input. Follow these steps for validation:

#### Example Scenario  
##### Execution sample:
```text
Seneca Restaurant 
 1- Order
 2- Print Bill
 3- Start a New Bill
 4- List Foods
 5- List Drinks
 0- End Program
><ENTER> 
You must enter a value: abc<ENTER> 
Invalid integer: 1 abc<ENTER> 
Only an integer please: -1<ENTER> 
Invalid value: [0<= value <=5], try again: 6<ENTER> 
Invalid value: [0<= value <=5], try again: 0<ENTER>
```
##### Explanation
Given the following menu:  
```text
Seneca Restaurant
 1- Order
 2- Print Bill
 3- Start a New Bill
 4- List Foods
 5- List Drinks
 0- End Program
> 
```  

If the user inputs invalid data, the program should respond as follows and wait for re-entry:  
1. **Empty Input:**  
   ```text
   You must enter a value:
   ```  
2. **Non-Integer Input:**  
   ```text
   Invalid integer: 
   ```  
3. **Trailing Characters After Integer:**  
   ```text
   Only an integer please: 
   ```  
4. **Out of Range Input:**  
   ```text
   Invalid value: [0 <= value <= 5], try again: 
   ```  
> 0 and 5 are lower and upper acceptable limits in this case

The program should continue prompting the user until a valid integer within the menu range is entered.  

---

### General Requirements  

- **Error Handling**: Follow the input validation process outlined above.  
- **Consistency**: Ensure menu titles, exit options, and functionality are consistent with this specification.  

---

# MS5 Submission

## MS51 Submission  

---

### MS51 Tester Program  

**No tester program**; use your own `main.cpp`.  

---

### MS51 Data Entry  

```text
4 <ENTER>
5 <ENTER>
0 <ENTER>
```  

---

### MS51 Expected Output  

[m51_correct_output.txt](prj/m51_correct_output.txt)  

---

### MS51 Submission Process  

To submit your work:  

1. **Upload Source Code**:  
   Ensure you upload the following files to your `matrix` account:  
   - **Utils.cpp, Utils.h**  
   - **Menu.h, Menu.cpp**  
   - **Billable.h, Billable.cpp**  
   - **Drink.h, Drink.cpp**  
   - **Food.h, Food.cpp**  
   - **Ordering.h, Ordering.cpp**  
   - **main.cpp**  
   - **foods.csv, drinks.csv**  

2. **Compile and Test**:  
   Compile and run your code using the `g++` compiler as outlined in the [introduction](#compiling-and-testing-your-program). Ensure your program runs correctly and matches the expected output.  

3. **Submit Your Work**:  
   From your `matrix` account, run the following command (replace `profname.proflastname` with your professor’s Seneca user ID):  

   ```bash
   ~profname.proflastname/submit 2??/prj/m51
   ```  
   - *2??* is replaced with your subject code

   Follow the instructions provided by the submission command.  


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to MS5 Submission](#ms5-submission)



## MS52 Submission 

**Order Drink**

---

### MS52 Tester Program  

**No tester program**; use your own `main.cpp`.  

---

### MS52 Data Entry  

```text
1 <ENTER>
2 <ENTER>
2 <ENTER>
3 <ENTER>
2 <ENTER>
0 <ENTER>
2 <ENTER>
1 <ENTER>
0 <ENTER>
2 <ENTER>
3 <ENTER>
1 <ENTER>
0 <ENTER>
0 <ENTER> <-- this is the last execution line check by the submitter, you can exit the program anyway you like after this
1 <ENTER>
```  
---

### MS52 Expected Output  

[m52_correct_output.txt](prj/m52_correct_output.txt)  

---

### MS52 Submission Process  

To submit your work:  

1. **Upload Source Code**:  
   Ensure you upload the following files to your `matrix` account:  
   - **Utils.cpp, Utils.h**  
   - **Menu.h, Menu.cpp**  
   - **Billable.h, Billable.cpp**  
   - **Drink.h, Drink.cpp**  
   - **Food.h, Food.cpp**  
   - **Ordering.h, Ordering.cpp**  
   - **main.cpp**  
   - **foods.csv, drinks.csv**  

2. **Compile and Test**:  
   Compile and run your code using the `g++` compiler as outlined in the [introduction](#compiling-and-testing-your-program). Ensure your program runs correctly and matches the expected output.  

3. **Submit Your Work**:  
   From your `matrix` account, run the following command (replace `profname.proflastname` with your professor’s Seneca user ID):  

   ```bash
   ~profname.proflastname/submit 2??/prj/m52
   ```  
   - *2??* is replaced with your subject code

   Follow the instructions provided by the submission command.  


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to MS5 Submission](#ms5-submission)


## MS53 Submission 

**Order Food**

---

### MS53 Tester Program  

**No tester program**; use your own `main.cpp`.  

---

### MS53 Data Entry  

```text
1 <ENTER>
1 <ENTER>
1 <ENTER>
0 <ENTER>
1 <ENTER>
1 <ENTER>
1 <ENTER>
well done <ENTER>
0 <ENTER>
0 <ENTER> <-- this is the last execution line check by the submitter, you can exit the program anyway you like after this
1 <ENTER>
```  

---

### MS53 Expected Output  

[m53_correct_output.txt](prj/m53_correct_output.txt)  

---

### MS53 Submission Process  

To submit your work:  

1. **Upload Source Code**:  
   Ensure you upload the following files to your `matrix` account:  
   - **Utils.cpp, Utils.h**  
   - **Menu.h, Menu.cpp**  
   - **Billable.h, Billable.cpp**  
   - **Drink.h, Drink.cpp**  
   - **Food.h, Food.cpp**  
   - **Ordering.h, Ordering.cpp**  
   - **main.cpp**  
   - **foods.csv, drinks.csv**  

2. **Compile and Test**:  
   Compile and run your code using the `g++` compiler as outlined in the [introduction](#compiling-and-testing-your-program). Ensure your program runs correctly and matches the expected output.  

3. **Submit Your Work**:  
   From your `matrix` account, run the following command (replace `profname.proflastname` with your professor’s Seneca user ID):  

   ```bash
   ~profname.proflastname/submit 2??/prj/m53
   ```  
   - *2??* is replaced with your subject code

   Follow the instructions provided by the submission command.  


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to MS5 Submission](#ms5-submission)



## MS54 Submission 

**Display Bill**

---

### MS54 Tester Program  

**No tester program**; use your own `main.cpp`.  

---

### MS54 Data Entry  

```text
1 <ENTER>
1 <ENTER>
1 <ENTER>
2 <ENTER>
well done <ENTER>
2 <ENTER>
2 <ENTER>
1 <ENTER>
1 <ENTER>
6 <ENTER>
1 <ENTER>
<ENTER>
0 <ENTER>
2 <ENTER>
0 <ENTER> <-- this is the last execution line check by the submitter, you can exit the program anyway you like after this
1 <ENTER>

```  

---

### MS54 Expected Output  

[m54_correct_output.txt](prj/m54_correct_output.txt)  

---

### MS54 Submission Process  

To submit your work:  

1. **Upload Source Code**:  
   Ensure you upload the following files to your `matrix` account:  
   - **Utils.cpp, Utils.h**  
   - **Menu.h, Menu.cpp**  
   - **Billable.h, Billable.cpp**  
   - **Drink.h, Drink.cpp**  
   - **Food.h, Food.cpp**  
   - **Ordering.h, Ordering.cpp**  
   - **main.cpp**  
   - **foods.csv, drinks.csv**  

2. **Compile and Test**:  
   Compile and run your code using the `g++` compiler as outlined in the [introduction](#compiling-and-testing-your-program). Ensure your program runs correctly and matches the expected output.  

3. **Submit Your Work**:  
   From your `matrix` account, run the following command (replace `profname.proflastname` with your professor’s Seneca user ID):  

   ```bash
   ~profname.proflastname/submit 2??/prj/m54
   ```  
   - *2??* is replaced with your subject code

   Follow the instructions provided by the submission command.  


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to MS5 Submission](#ms5-submission)


## MS55 Submission 

**Reset Exit and Save Bill Message**

---

### MS55 Tester Program  

**No tester program**; use your own `main.cpp`.  

---

### MS55 Data Entry  

```text
1 <ENTER>
2 <ENTER>
2 <ENTER>
2 <ENTER>
0 <ENTER>
2 <ENTER>
0 <ENTER>
0 <ENTER>
3 <ENTER>
0 <ENTER>
```  

---

### MS55 Expected Output  

[m55_correct_output.txt](prj/m55_correct_output.txt)  

---

### MS55 Submission Process 

To submit your work:  

1. **Upload Source Code**:  
   Ensure you upload the following files to your `matrix` account:  
   - **Utils.cpp, Utils.h**  
   - **Menu.h, Menu.cpp**  
   - **Billable.h, Billable.cpp**  
   - **Drink.h, Drink.cpp**  
   - **Food.h, Food.cpp**  
   - **Ordering.h, Ordering.cpp**  
   - **main.cpp**  
   - **foods.csv, drinks.csv**  

2. **Compile and Test**:  
   Compile and run your code using the `g++` compiler as outlined in the [introduction](#compiling-and-testing-your-program). Ensure your program runs correctly and matches the expected output.  

3. **Submit Your Work**:  
   From your `matrix` account, run the following command (replace `profname.proflastname` with your professor’s Seneca user ID):  

   ```bash
   ~profname.proflastname/submit 2??/prj/m55
   ```  
   - *2??* is replaced with your subject code

   Follow the instructions provided by the submission command.  


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to MS5 Submission](#ms5-submission)



## MS56 Submission 

**Fool-Proofing and Bad Data File**

---

### MS56 Tester Program  

**No tester program**; use your own `main.cpp`.  

---

### MS56 Data Entry  

```text
<ENTER>
-1 <ENTER>
4 <ENTER>
abc <ENTER>
123abc <ENTER>
0 <ENTER>
```  

---

### MS56 Expected Output  

[m56_correct_output.txt](prj/m56_correct_output.txt)  

---

### MS56 Submission Process 

To submit your work:  

1. **Upload Source Code**:  
   Ensure you upload the following files to your `matrix` account:  
   - **Utils.cpp, Utils.h**  
   - **Menu.h, Menu.cpp**  
   - **Billable.h, Billable.cpp**  
   - **Drink.h, Drink.cpp**  
   - **Food.h, Food.cpp**  
   - **Ordering.h, Ordering.cpp**  
   - **ms56.cpp**  
   - **foods.csv, drinks.csv**  

2. **Compile and Test**:  
   Compile and run your code using the `g++` compiler as outlined in the [introduction](#compiling-and-testing-your-program). Ensure your program runs correctly and matches the expected output.  

3. **Submit Your Work**:  
   From your `matrix` account, run the following command (replace `profname.proflastname` with your professor’s Seneca user ID):  

   ```bash
   ~profname.proflastname/submit 2??/prj/m56
   ```  
   - *2??* is replaced with your subject code

   Follow the instructions provided by the submission command.  


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to MS5 Submission](#ms5-submission)

Your message is mostly clear but has a couple of small grammatical and formatting issues. Here’s the refined version:

---

# Project Reflection  

## Reflection Submission (Optional)  

The reflection submission is optional.  

You can use it to:  
- Share your thoughts about the project or provide feedback to your professor.  
- Highlight any additional work or enhancements you have implemented that you would like your professor to notice.  

Feel free to include any insights, challenges you faced, or suggestions for improving the project in future iterations.  

---

### Reflection Submission Process  

1. **Write Your Reflection:**  
   - Create a file named `reflect.txt` and include your reflection.  

2. **Upload to Matrix:**  
   - Upload your the reflection file to matrix
   - Use the following command to submit your reflection:  

     ```bash
     ~profname.proflastname/submit 2??/prj/mref
     ```  
     - Replace **`2??`** with your subject code.  

3. **Follow Instructions:**  
   - Complete the submission process as prompted by the command.  

---

## [Back to MS5 Submission](#ms5-submission)  

