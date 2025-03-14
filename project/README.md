# Project: Dine-In Digital - A Restaurant Ordering System
  

## Objective  
In this project, you will build an application that enables waiters to take customer orders for food and drinks and generate a bill upon order completion. Each bill will have a unique number, and once an order is finalized, the bill will be saved in a separate file named according to its bill number.

### Milestones  

| Milestone | Revision | Comments | Walkthrough |
|-----------|:--------:|:--------:|:-----------:|
| [MS1](#milestone-1) | V1.0 | | [video](https://youtu.be/lqJI57TdSpA) |
| [MS2](#milestone-2) | V1.0 | | [video](https://youtu.be/lymXEXn6eh0) |
| [MS3](#milestone-3) | | | |
| [MS4](#milestone-4) |  | | |
| [MS5](#milestone-5-the-final-milestone) |  | | |

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

## [Back to milestones](#milestones)


# Milestone 4:  
## Ordering Module  


## [Back to milestones](#milestones)

# Milestone 5: The Final Milestone  


