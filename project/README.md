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



# Milestone 1


> Note: As we move forward through the milestones of this project, remember that, like in any real-life project, we may need to revisit previous implementations to make changes or corrections to accommodate future requirements.

## `constants.h`
This header file is used to hold all the constant values used in the project. For now, add the following constant value:

- `MaximumNumberOfMenuItems` set to 20. (preferably unsigned)


## MenuItem class

Initially, we will implement this class as a standalone class. We will test it and make sure it works correctly. In Milestone 2, we will implement the Menu class, which is a composition of MenuItem objects.

When creating a menu formatted like the one below, the `title`, the `numbered rows`, and even `the prompt` for data entry at the end are considered MenuItem objects:

```text
Seneca Resturant                        <----  title
 1- Order                               <----  numbered row
 2- Print Bill
 3- Start a New Bill                    <----  numbered row
 4- List Foods
 5- List Drinks                         <----  numbered row
 0- End Program
>                                       <----  the prompt
```

In a module called Menu (i.e., Menu.h and Menu.cpp), create a class called MenuItem.

The MenuItem class must have a minimum of four attributes:

- A character pointer to hold the MenuItem content dynamically.
- An integer (preferably unsigned) to keep track of the number of indentations.
- An integer (preferably unsigned) to keep track of the size of each indentation in characters.
- An integer to be used for the numbering of MenuItem objects.


### Construction
The MenuItem should be constructed using the following four values:

- A C-string holding the content. This should be stored dynamically in the MenuItem content.
- The number of indentations.
- The size of each indentation.
- An integer for the row number (only used for numbered menu items).

#### Constructor Validations

If any of the following conditions occur, the MenuItem should be set to a safe empty state:

- The content is nullptr, empty, or consists only of whitespace characters.
- Any of the indentation or indentation size values exceed 4.
- The row value is greater than `MaximumNumberOfMenuItems`.

### Rule of three
The Rule of Three must be applied to MenuItem to ensure it is not copyable or assignable to another MenuItem, and that the memory is properly deallocated when a MenuItem is destroyed.

### bool Type Conversion Overload
If a MenuItem is cast to a bool, it should return false if it is in a safe empty state and true if it is a valid MenuItem.

### Display
The MenuItem class should have a display member function that outputs the formatted content of the MenuItem to an ostream. This function should be defined as follows:
```c++
ostream& display(ostream& ostr) const;
```
#### Function Requirements:
- The function should output the formatted content of the `MenuItem` to the given `ostream`.
- If the `MenuItem` is valid (m_content is not null), the function should:
   - Display the content with proper indentation based on the `indentation number` and the `indentation size`. 
   - Include the `row` number formatted as a two-character-wide value followed by `"- "` if row is non-negative.
   - Display the content without any leading whitespace. (skip the spaces in conent)
- If the MenuItem is in an invalid or safe empty state (e.g., m_content is null), the function should output `"??????????"`.
#### Output Expectations:
- Indentation should be added to align the content appropriately.
- The row number, if present, should be right-aligned and followed by `"- "`.
- If the content is invalid, display `"??????????"` instead.

## ms1 tester program

[ms1.cpp](ms1/ms1.cpp)

### Sample Execution

[correct_output.txt](ms1/correct_output.txt)


## MS1 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.h , Menu.cpp and ms1.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m1
```
and follow the instructions.

- *2??* is replaced with your subject code


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

## [Back to milestones](#milestones)

# Milestone 2

## Menu class

Add a class to the `Menu` module called `Menu`. The `Menu` class must own the `MenuItem` class as part of its composition. To enforce this, the `MenuItem` class should only be accessible by the `Menu` class.

To achieve this, remove the `public` keyword from the `MenuItem` class and make it fully private.

Forward declare the `Menu` class above the `MenuItem` class and add `Menu` as a friend of the `MenuItem` class.

With this change, only the `Menu` class can instantiate `MenuItem` objects.

### Attributes
- Add three integer (preferably unsigned) attributes to track:
  - The **indentation number and size** for `MenuItem` objects.
  - The **number of `MenuItem` objects** currently held in the `Menu`.

- Add three `MenuItem` attributes for the **title**, **exit option**, and **selection entry prompt** of the `Menu`. Since `MenuItem` does not have a default constructor, these attributes must be initialized in the **member initializer list**. Ensure that the initialization order matches the order in which the attributes are declared in the `Menu` class, as some compilers may issue warnings if the order is inconsistent.  
   > The row number of the `exit option` should be set to zero.

- Add an **array** of `MenuItem` pointers, sized according to the constant `MaximumNumberOfMenuItems`. When adding MenuItem objects, they should be dynamically allocated and stored in this array. Ensure that the number of `MenuItem` objects does not exceed the size of the array.

### Constructor
Create a `Menu` constructor with the following four arguments:

- A C-string for the **title**.
- A C-string for the **exit option content**, defaulted to `"Exit"`.
- An **indentation number**, defaulted to `0`.
- An **indentation size**, defaulted to `3`.

Initialize the corresponding attributes with these arguments and initialize the selection entry prompt `MenuItem` to `"> "`.

Set all elements of the pointer array to `nullptr`.

---

### `<<` Operator Overload for `Menu`

Implement the `<<` operator overload for the `Menu` class to dynamically add new `MenuItem` objects.

#### Requirements:
- The operator should take a `const char*` representing the `content` of a new `MenuItem`.
- Check if the current number of `MenuItem` objects is less than `MaximumNumberOfMenuItems` before adding a new item.
- If the condition is met:
   - Dynamically create a new `MenuItem` using the provided `menuItem` content, the current indentation level, the indentation size, and the row number (calculated as `number-of-menu-items + 1`).
   - Store the new `MenuItem` pointer in the `MenuItem` pointer array.
   - Increment `number-of-menu-items` to reflect the addition.
- Return `*this` to allow chaining of the operator.

#### Constraints:
- Ensure that `number-of-menu-items` does not exceed `MaximumNumberOfMenuItems`. If the array is full, the operation should not add a new item or increment `number-of-menu-items`.

This operator overload enables the use of the `<<` operator to add `MenuItem` objects to a `Menu`, enhancing readability and simplifying the process of building a menu.

---

### Rule of Three
Copying and assignment of a `Menu` object should be explicitly prevented. While this is inherently enforced by making `MenuItem` attributes private to the `Menu` class, explicitly deleting the copy constructor and copy assignment operator in comments enhances code maintainability and clarity.

Implement a destructor that iterates through the array of `MenuItem` pointers, deletes each non-null pointer, and sets them to `nullptr` to safely release allocated memory.

---

### `select` Method 
```c++
size_t select() const;
```
Implement the `select` method for the `Menu` class to perform the following actions:

#### Requirements:
- **Display the Title**: If the `Menu` object has a title, display it first.
- **Display `Menu` Items**: Iterate through all `MenuItem` objects stored in the `Menu` and display them one by one.
- **Display the Exit Option**: Display the `exit option MenuItem` after listing the main `MenuItem` objects.
- **Display the Selection Prompt**: Display the `selection prompt` `MenuItem` to indicate that user input is expected.
- **Return the User's Selection**: Obtain and return a validated integer input representing the user's choice. The input should only be valid if it falls within the range of `0` (representing the exit option) to the number of `MenuItem` objects currently in the `Menu`. See the `getInt` function suggestion below.

#### Expected Outcome:
- The method should output the full menu structure in a readable format and handle user selection.
- It should ensure that the selection is a valid integer within the specified range before returning it.

#### Sample Output:
Two example menus:  
The first has zero indentation, the second has one level of indentation.
```text
Seneca Restaurant
 1- Order
 2- Print Bill
 3- Start a New Bill
 4- List Foods
 5- List Drinks
 0- End Program
> 1
   Order Menu
    1- Food
    2- Drink
    0- Back to main menu
   >
```

---

### Insertion Operator Overload into `ostream`
Create an `operator<<` overload for the `Menu` class:
```c++
size_t operator<<(std::ostream& ostr, const Menu& m);
```
#### Requirements:
- The operator should handle output to an `ostream`.
- When `ostr` is `cout` (check their address to confirm), the operator should invoke the `select()` method of the `Menu` class and return the user's selection.
- The return value should be the result of the `select()` method, representing the user's choice from the menu.
- If the `ostream` is not `cout`, do not perform the selection operation; simply return `0`.

#### Outcome:
- The operator should display the `Menu` on `cout` and allow the user to make a selection, returning the valid selection as a `size_t`.
- Ensure that the operator returns `0` when used with any `ostream` other than `cout`.

> **Note:** Unlike typical insertion overloads, this operator does **not** return an `ostream` reference.

---

## `Utils` Module Foolproof Entry Functions
> The following will be tested in **milestone 5**.

To ensure foolproof data entry, implement two functions in the `Utils` module and use them within your `select` method.

---

### `getInt`
```c++
int getInt();
```
Create a method in the `Utils` class to handle integer input with the following requirements:

#### Requirements:
- **Prompt for Valid Input**: Continuously prompt the user until a valid integer is entered.
- **Handle Empty Input**: If the user presses Enter without typing anything, display:
   ```text
   You must enter a value:
   ```
- **Validate Integer Input**: If the user enters non-integer data, display:
   ```text
   Invalid integer:
   ```
   Clear the error state before prompting again.
- **Check for Trailing Characters**: If extra characters follow the integer, display:
   ```text
   Only an integer please:
   ```
   Prompt the user again.
- **Clear Input Buffer**: After processing the input, clear any remaining characters to prepare for the next entry.

#### Outcome:
The method should only return a valid integer after ensuring proper validation.

---

### `getInt(min, max)`
```c++
int getInt(int min, int max);
```
#### Requirements:
- **Range Validation**: Prompt the user until a valid integer within the range `[min, max]` is entered.
- **Use `getInt()`**: Utilize the basic validation logic from `getInt()`.
- **Handle Out-of-Range Values**: If input is outside the range, display:
   ```text
   Invalid value: [min <= value <= max], try again:
   ```
   Replace `min` and `max` with the respective values.

#### Outcome:
The function should return a valid integer within the specified range after enforcing all validation rules.


## ms2 tester program

[ms2.cpp](ms2/ms2.cpp)

### Sample Execution

[correct_output.txt](ms2/correct_output.txt)

### Data Entry for ms2
```text
1<ENTER>
0<ENTER>
2<ENTER>
2<ENTER>
0<ENTER>
0<ENTER>
0<ENTER>
```

### Data Entry for foolproof entry
> Will be tested in milstone 6
```text
<ENTER>
abc<ENTER>
123abc<ENTER>
-1<ENTER>
4<ENTER>
0<ENTER>
```
> Also try running option 3 for the Final Milestone Application Demo and see how it works.
### Foolproof entry output sample
```text
Milestone 2
 1- Run Test 1
 2- Run Test 2
 3- Final Milestone Application Demo
 0- Exit
>
You must enter a value: abc
Invalid integer: 123abc
Only an integer please: -1
Invalid value: [0<= value <=3], try again: 4
Invalid value: [0<= value <=3], try again: 0
Have a good day!
```


## MS2 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.h , Menu.cpp and ms2.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m2
```
and follow the instructions.

- *2??* is replaced with your subject code


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

## [Back to milestones](#milestones)

# Milestone 3: 
## Billable, Food, and Drink Modules

> **Note:**  
In this milestone, as before, you should simplify your code by implementing helper functions in the `Utils` module. This module should provide utilities for tasks such as dynamic memory allocation, foolproof data entry, and string manipulation. 
---

### `Billable` Class
The `Billable` class serves as an abstract base for items that can be added to a customer’s bill. It contains attributes and methods that define shared functionality among all billable items.

1. **Attributes:**
   - **`m_name`**: A dynamically allocated C-string to hold the name or description of the item.
   - **`m_price`**: A `double` representing the base price of the item.

2. **Protected Methods:**
   - **`void price(double value)`**: Sets the item’s price.
   - **`void name(const char* name)`**: Sets the item’s name, handling dynamic allocation.

3. **Public Methods and Overloads:**
   - **Constructors and Destructor**:
     - A default constructor initializes an empty `Billable` item.
     - Copy constructor and assignment operator to handle deep copies of dynamic members.
     - A virtual destructor ensures proper cleanup of derived objects.

   - **Virtual Methods**:
     - **`double price() const`**: Returns the item’s price, allowing derived classes to override if needed.

   - **Pure Virtual Methods** (to be implemented in derived classes):
     - **`ostream& print(ostream& ostr=cout)const`**: Displays item information in a formatted way.
     - **`bool order()`**: Takes customer order for details of the item (e.g., size, customizations).
     - **`bool ordered()const`**: Returns true if details have been set, indicating the item is ordered.
     - **`ifstream& read(ifstream& file)`**: Reads item details from an input file.

   - **Operator Overloads**:
      ```c++
      double operator+(double money, const Billable& B);
      double& operator+=(double& money, const Billable& B);
      ```
     - `+` and `+=` are overloaded to allow adding an item’s price to a total amount (of type `double`), enabling easy bill calculations.
     - **Conversion Operator (`operator const char*()const`)**: Provides access to the name for display or comparison.

---

### `Drink` Class
The `Drink` class inherits from `Billable` and represents a drink item. It adds functionality to manage the drink size and customizes price based on size.

1. **Attributes:**
   - **`m_size`**: A `char` indicating the size of the drink (e.g., `'S'` for small, `'M'` for medium, `'L'` for large, and `'X'` for extra large). If `m_size` is unset, it defaults to a safe empty state, and `"....."` will display for the size.

2. **Public Methods**:
   - **`print`**: Overrides `Billable`’s print to display or save the drink’s name, size, and price.
   
      The `print` method outputs the drink in the following format:
      - **name**: Up to 25 characters in 28 spaces, left-justified and padded with dots (`'.'`).
      - **size**: Displays as `"SML.."`, `"MID.."`, `"LRG.."`, `"XLR.."` for small, medium, large, and extra large sizes, respectively. If size is unset (i.e., `!ordered()`), it displays as `"....."`.
      - **price**: Right-justified in 7 spaces, padded with spaces and displayed with 2 decimal places.

   - **`order`**:  Overrides `Billable`’s order as follows:
      Displays a menu for drink size selection with 3 indentations:
      ```text
      Drink Size Selection
         1- Small
         2- Medium
         3- Large
         4- Extra Large
         0- Back
      >
      ```
     Sets the order size to its acceptable values or leaves it unset if "Back" is selected.

     The method returns `true` if the size was selected (indicating it was ordered) or `false` if not.

   - **`ordered`**:  Overrides `Billable`’s ordered, returning `true` if a size has been selected.

   - **`read`**:  Overrides `Billable`’s read.
     Reads the drink’s details from a comma-separated input file in the following format:
     ```text
     name of drink,price
     ```
     Example:
     ```text
     Orange Juice,3.5<Newline>
     ```
     If the read is successful
      - the details are set to corresponding values
      - m_size is set to its default value
     
     Otherwise, nothing changes.

   - **`price`**: Adjusts the base price based on `m_size` as follows:
     - Returns `Billable` price if size is large or if item is not ordered.
     - For small, returns half of the price; for medium, returns 3/4 of the price; and for extra large, returns 1.5 times the original price.

3. Since this class does not manage resources outside of its scope, it does not require implementing the rule of three. The object is always created in a safe empty state.

---

### `Food` Class
The `Food` class, derived from `Billable`, represents a food item and includes functionality for customization and portion type.

1. **Attributes:**
   - **`m_ordered`**: A boolean flag indicating whether the item has been ordered.
   - **`m_child`**: A boolean representing if the food is a child portion, which affects pricing.
   - **`m_customize`**: A dynamically allocated C-string for storing customization notes (e.g., "No onions").

2. **Public Methods and Overloads**:
   - **Constructors and Destructor**: The copy constructor, assignment operator, and destructor manage dynamic allocation for `m_customize`. The no-argument constructor leaves the object in a safe empty state.

   - **`print`**: Overrides `Billable`’s print to display or save the food item’s details, including portion type. Customizations are printed only if the `ostream` object is `cout`:
     - **name**: Up to 25 characters in 28 spaces, left-justified and padded with dots (`'.'`).
     - **portion type**: Displays `"Child"` or `"Adult"` if `ordered()` is `true` and `m_child` is set. Otherwise, it displays `"....."`.
     - **price**: Right-justified in 7 spaces, padded with spaces, and displayed with 2 decimal places.
     - **customizations**: If `m_customize` is not null and `ostream` is `cout`, it prints `" >> "` followed by the first 30 characters of `m_customize`. Otherwise, nothing is printed.

   - **`order`**:  Overrides `Billable`’s order as follows:
      Displays a menu for food portion selection with 3 indentations:
      ```text
      Food Size Selection
         1- Adult
         2- Child
         0- Back
      > 
      ```
      Sets the order portion to its acceptable values, setting `m_ordered` to `true`. If "Back" is selected, the portion remains unset, m_ordered is set to false and m_customize is deallocated.

      If a portion is ordered, the user is prompted for customization:
      ```text
      Special instructions
      > 
      ```
      If the user just presses enter, no customization is added, and `m_customize` is deallocated and set to nullptr. Otherwise, customization instructions are stored in `m_customize` (you may refer to the `Utils` functions for dynamic memory allocation here).

      The method returns `true` if a portion is ordered, or `false` if not.

   - **`ordered`**:  Overrides `Billable`’s ordered, returning the `m_ordered` flag.

   - **`read`**:  Overrides `Billable`’s read.
     Reads the food’s details from a comma-separated input file in the following format:
     ```text
     name of Food,price
     ```
     Example:
     ```text
     Pasta with Tomato sauce,3.5<Newline>
     ```
     If the read is successful
      - the details are set to corresponding values
      - m_child and m_order are set to thier default values
      - m_customize is deleted and set to nullptr
      
     Otherwise, the object remains unchanged.

   - **`price`**: Overrides `Billable`’s price. 
     Returns half the price if ordered and `m_child` is true, indicating a child portion; otherwise, it returns the original `Billable` price.
## ms3 tester program

[ms3.cpp](ms3/ms3.cpp)

### Sample Execution

[correct_output.txt](ms3/correct_output.txt)

### Data Entry for ms3

Follow the instructions of the tester


## MS3 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.

Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.h , Menu.cpp, Billable.h, Billable.cpp, Drink.h, Drink.cpp, Food.h, Food.cpp and ms3.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m3
```
and follow the instructions.

- *2??* is replaced with your subject code


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

## [Back to milestones](#milestones)


# Milestone 4:  
## Ordering Module  

Continue developing the system by implementing the `Ordering` module. This module encapsulates and organizes all the tasks involved in taking orders. The methods of this class will be invoked when the options of the main menu are selected by the waiter, assisting with taking customer orders at the restaurant.

---

### Attributes  

#### Billable, Food, and Drink Counters  

The `Ordering` module includes attributes to track the number of food and drink items in the menu and the number of billable items added to a bill. These attributes ensure proper organization and management of the ordering process:  

- **Food Counter**: An integer (preferably unsigned) to keep track of the number of food items loaded from the food data file.  
- **Drink Counter**: An integer (preferably unsigned) to keep track of the number of drink items loaded from the drink data file.  
- **Billable Counter**: An integer (preferably unsigned) to track the number of `Billable` items added to the bill from the food and drink menu.

---

#### Bill Number  

- **Bill Serial Number**: An integer (preferably unsigned) representing the bill serial number, starting from 1. This number increments each time a new bill is generated. It is also used to create a unique file name for each completed bill saved to the file system.  

> **Note:**  
Use the following function, `makeBillFileName` and add it to the `Utils` module to generate unique file names. This function receives a bill number and creates a file name in the format `bill_[billNo].txt`.   
```cpp
char* makeBillFileName(char* filename, size_t billNo) {
   size_t temp = billNo;
   int cnt = 5, i = 0;
   int length = 0;
   // set name prefix
   while ("bill_"[i]) {
      filename[i] = "bill_"[i++];
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

```
---

#### Food and Drink Dynamic Arrays  

- **Food Array**: A `Food` pointer used to store a dynamically allocated array of food items loaded from the food data file.  
- **Drink Array**: A `Drink` pointer used to store a dynamically allocated array of drink items loaded from the drinks data file.

---

#### Billable Array of Pointers  

- **Bill Items**: An array of `Billable` pointers, with a size defined by the `MaximumNumberOfBillItems` constant in `constants.h`. When a food or drink item is about to be ordered, a dynamic copy of the selected item is created and stored in the next available spot in this array. The item is then customized to match the customer’s order.

---

### Private Methods  

#### **Bill Title Print**  
This method prints a header for a bill.  

- **Parameters**:  
  - A reference to an `ostream` object.  

- **Description**:  
  The method prints the bill title in the following format, using the `Bill Number` attribute. For example, if the bill number is `35`, the output would look like:  

  ```text
  Bill # 035 =============================<NEWLINE>
  ```  

---

#### **Print Totals**  
This method prints the footer for a bill.  

- **Parameters**:  
  - A reference to an `ostream` object.  
  - A `double` value representing the total amount.  

- **Description**:  
  The method prints the total, applicable tax, and the grand total into the provided `ostream` object using the `Tax` constant value defined in `constants.h`. For example, if the total value is `16.88`, the output would be:  

  ```text
                       Total:        16.88
                       Tax:           2.19
                       Total+Tax:    19.07
  ========================================<NEWLINE>
  ```

---

#### **`size_t countRecords(const char* file) const`**  

This function calculates the number of records in a file by counting the newline characters.  

- **Parameters**:  
  - A constant character pointer (`const char*`) representing the file name.  

- **Return Value**:  
  - Returns the count of newline characters (`size_t`), representing the number of records in the file.  

- **Implementation**:  
  Use the following pseudocode to implement this function:  

  ```text
  set a newline counter to zero
  open an ifstream using the file argument value
  while the file is not in a failure state
     read one character
     if the file is not in failure state and character is a newline
        add one to the newline counter
  end while
  return the newline counter
  ```  

- **Purpose**:  
  This method is essential for determining the size of dynamically allocated arrays for food and drink items by counting the number of records in their respective files.


### Constructor and Destructor  

#### **Constructor**  

The `Ordering` class is constructed using two C-strings representing the drinks and foods data file names.  

**Steps for Implementation:**  

1. **Count Records:**  
   - Determine the number of records in the drinks and foods data files by using the `countRecords` method. Store these counts in two local variables.  

2. **Open Files for Reading:**  
   - Open the drinks and foods data files using `ifstream`.  

3. **Dynamic Array Allocation:**  
   - Create two dynamic arrays:  
     - A `Food` array, pointed to by the corresponding attribute of the `Ordering` class.  
     - A `Drink` array, pointed to by the corresponding attribute of the `Ordering` class.  

4. **Reading Data:**  
   - If both files are successfully opened:  
     - Loop through the drinks array, calling the `read` method on each element until one of the following occurs:  
       - The number of reads matches the number of records in the file.  
       - A read operation fails.  
     - Repeat the same process for the foods array.  

5. **Validation and Cleanup:**  
   - If the number of successfully read records does not match the number of records in either file:  
     - Revert the operation by **deleting** both arrays.  
     - Set the pointers for both arrays to `nullptr` (safe empty state).  
   - Otherwise:  
     - Set the corresponding attributes of the `Ordering` class to the number of records successfully read.  

---

#### **Destructor**  

The destructor ensures proper cleanup of dynamically allocated memory to prevent memory leaks.  

**Steps for Implementation:**  

1. **Delete Dynamic Arrays:**  
   - Delete the dynamic arrays for foods and drinks by using the `delete[]` operator.  

2. **Delete Billable Items:**  
   - Loop through the `Billable` array of pointers, deleting each element up to the number of items currently in the bill.  

---

### Queries  

> **Note:** Queries cannot change the state of the class.


#### **Boolean Conversion Operator Overload**  
This operator provides a safe empty state indicator.

- **Description:**  
  - This method does not modify the class.  
  - Returns `true` if both the drinks and foods dynamic arrays are not `nullptr`.  

---

#### **Number of Bill Items**  
Method name: 'noOfBillItems'

- **Description:**  
  - Create a method to return the number of items currently in the bill.  
  - This value is stored in the `Billable` counter attribute of the class.  

---

#### **Has Unsaved Bill**  
Method name: `hasUnsavedBill`

- **Description:**  
  - Create a method that returns a boolean value.  
  - This method should return `true` if the number of bill items (tracked by the `Billable` counter attribute) is greater than zero.  
---

### Methods to Be Called in the Main Application's Menu  

These methods handle specific tasks based on the options selected in the main application's menu.  


#### **List Food Method** *(does not modify the class)*  
Method name: `listFoods`
- **Description:**  
  - Prints the following header:  
    ```text
    List Of Avaiable Meals
    ========================================<NEWLINE>
    ```  
  - Loops through the `foods` dynamic array and prints each item on a separate line using its `print` method.  
  - Prints the following footer:  
    ```text
    ========================================<NEWLINE>
    ```  

---

#### **List Drinks Method** *(does not modify the class)*  
Method name: `listDrinks`
- **Description:**  
  - Works exactly like the `List Food` method but operates on the `drinks` dynamic array.  

---

#### **Order Food Method**  
Method name: `orderFood`

- **Description:**  
  - Creates a `Menu` object with:  
    - **Title**: `"Food Menu"`  
    - **Exit Option**: `"Back to Order"`  
    - **Indentations**: `2`  
  - Populates the `Menu` object with the names of the food items from the `foods` dynamic array.  
  - Displays the menu and receives the waiter's selection.  
  - If the selection is not zero:  
    - Creates a dynamic copy of the selected food item and assigns it to the next available element in the `Bill Items` array (i.e. the `Billable` array of pointers).  
    - Calls the `order` method on the `Billable` item to customize the order.  
    - If `order` returns `true`, increments the `number of bill items` attribute.  
    - If `order` returns `false`, deletes the dynamically created food item to revert the operation.  

---

#### **Order Drink Method**  
Method name: `orderDrink`

- **Description:**  
  - Similar to the `Order Food` method but for drinks:  
    - Creates a `Menu` object with:  
      - **Title**: `"Drink Menu"`  
      - **Exit Option**: `"Back to Order"`  
      - **Indentations**: `2`  
    - Populates the `Menu` object with the names of the drink items from the `drinks` dynamic array.  
    - Displays the menu and receives the waiter's selection.  
    - If the selection is not zero:  
      - Creates a dynamic copy of the selected drink item and assigns it to the next available element in the `Bill Items` array.  
      - Calls the `order` method on the `Billable` item to customize the order.  
      - If `order` returns `true`, increments the `number of bill items` attribute.  
      - If `order` returns `false`, deletes the dynamically created drink item to revert the operation.  

---

#### **Print Bill Method** *(does not modify the class)*  
Method name: `printBill`

- **Parameters:**  
  - Receives a reference to an `ostream` object.  

- **Description:**  
  - Creates a `double` variable to track the total price of the bill.  
  - Prints the bill title using the `Bill Title Print` method.  
  - Loops through the elements in the `Bill Items` array:  
    - Prints each item in a separate line using its `print` method.  
    - Adds the price of each item to the total.  
  - Prints the totals using the `Print Totals` method.  

---

#### **Reset Bill**  
Method name: `resetBill`

- **Description:**  
  - Uses the `makeBillFileName` function from the `Utils` module to generate a unique file name for the current bill using the `bill number` attribute.  
  - Opens a file for writing using the generated file name (`ofstream`).  
  - Prints the current bill into the opened file using the `Print Bill` method.  
  - Displays the following message (for example, if the current bill number is 20):  
    ```text
    Saved bill number 20
    Starting bill number 21
    ```  
  - Deletes all dynamically created elements in the `Bill Items` array.  
  - Increments the `bill number` attribute by one.  
  - Resets the `number of bill items` attribute to zero.  

---

## ms4 tester program

[ms4.cpp](ms4/ms4.cpp)

### Sample Execution

[correct_output.txt](ms4/correct_output.txt)

### Data Entry for ms4

Follow the instructions of the tester


## MS4 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.

Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.h , Menu.cpp, Billable.h, Billable.cpp, Drink.h, Drink.cpp, Food.h, Food.cpp, Ordering.h, Ordering.cpp and ms4.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m4
```
and follow the instructions.

- *2??* is replaced with your subject code


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

## [Back to milestones](#milestones)

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

