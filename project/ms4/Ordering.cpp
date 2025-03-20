#include "Ordering.h"
#include "Food.h"
#include "Drink.h"
#include "Menu.h"
#include "Utils.h"  // 包含Utils模块
#include <iostream>
#include <iomanip>

namespace seneca {
    // 第二步：实现构造函数
    Ordering::Ordering(const char* drinksFile, const char* foodsFile) {
        // 统计文件记录数
        m_foodCnt = countRecords(foodsFile);
        m_drinkCnt = countRecords(drinksFile);
        
        // 动态分配数组
        m_foods = new Food[m_foodCnt];
        m_drinks = new Drink[m_drinkCnt];
        
        // 加载数据
        std::ifstream foodFile(foodsFile);
        std::ifstream drinkFile(drinksFile);
        
        // 验证并加载数据
        bool valid = true;
        for(size_t i = 0; valid && i < m_foodCnt; i++) {
            if(!m_foods[i].read(foodFile)) valid = false;
        }
        for(size_t i = 0; valid && i < m_drinkCnt; i++) {
            if(!m_drinks[i].read(drinkFile)) valid = false;
        }
        
        // 失败处理
        if(!valid) {
            delete[] m_foods;  // 释放内存
            delete[] m_drinks;
            m_foods = nullptr;
            m_drinks = nullptr;
            m_foodCnt = m_drinkCnt = 0;
        }
    }

    // 第三步：实现析构函数
    Ordering::~Ordering() {
        delete[] m_foods;
        delete[] m_drinks;
        for(size_t i = 0; i < m_billCnt; i++) {
            delete m_billItems[i];  // 释放每个Billable对象
        }
    }

    // 第四步：实现核心方法
    void Ordering::orderFood() {
        Menu foodMenu("Food Menu", "Back to Order", 2);
        for(size_t i = 0; i < m_foodCnt; i++) {
            foodMenu << m_foods[i];  // 使用运算符重载添加菜单项
        }
        
        size_t selection = std::cout<< foodMenu;  // 使用运算符重载显示菜单
        if(selection > 0) {
            m_billItems[m_billCnt] = new Food(m_foods[selection-1]);  // 深拷贝
            if(m_billItems[m_billCnt]->order()) {  // 调用order方法
                m_billCnt++;
            } else {
                delete m_billItems[m_billCnt];
            }
        }
    }

    // 第五步：实现账单打印
    void Ordering::printBill(std::ostream& ostr) const {
        double total = 0;
        printBillTitle(ostr);
        for(size_t i = 0; i < m_billCnt; i++) {
            m_billItems[i]->print(ostr); 
            ostr<<std::endl; // 多态调用
            total += *m_billItems[i];     // 使用运算符重载
        }
        printTotals(ostr, total);
    }

    // orderDrink实现示例
    void Ordering::orderDrink() {
        Menu drinkMenu("Drink Menu", "Back to Order", 2);
        for(size_t i = 0; i < m_drinkCnt; i++) {
            drinkMenu << m_drinks[i];
        }
        
        size_t selection = std::cout<<drinkMenu;
        if(selection > 0 && m_billCnt < MaximumNumberOfBillItems) {
            m_billItems[m_billCnt] = new Drink(m_drinks[selection-1]); // 多态拷贝
            if(m_billItems[m_billCnt]->order()) {
                m_billCnt++;
            } else {
                delete m_billItems[m_billCnt];
                m_billItems[m_billCnt] = nullptr;
            }
        }
    }

    // listFoods实现
    void Ordering::listFoods() const {
        std::cout << "List Of Available Meals\n";
        std::cout << std::string(40, '=') << '\n';
        for(size_t i = 0; i < m_foodCnt; i++) {
            m_foods[i].print(std::cout) << '\n';
        }
        std::cout << std::string(40, '=') << '\n';
    }

    // resetBill实现
    void Ordering::resetBill() {
        char filename[50];
        ut.makeBillFileName(filename, m_billNo);  // 调用Utils模块中的函数
        
        std::ofstream billFile(filename);
        if(billFile) {
            printBill(billFile);
            std::cout << "Saved bill number " << m_billNo << '\n';
        }
        
        // 清理账单项
        for(size_t i = 0; i < m_billCnt; i++) {
            delete m_billItems[i];
        }
        m_billCnt = 0;
        m_billNo++;
        
        std::cout << "Starting bill number " << m_billNo << '\n';
    }

    // 补充listDrinks实现
    void Ordering::ListDrinks() const {
        std::cout << "List Of Available Drinks\n";
        std::cout << std::string(40, '=') << '\n';
        for(size_t i = 0; i < m_drinkCnt; i++) {
            m_drinks[i].print(std::cout) << '\n';
        }
        std::cout << std::string(40, '=') << '\n';
    }

    // 补充hasUnsavedBill实现
    bool Ordering::hasUnsavedBill() const {
        return m_billCnt > 0;
    }

    // 补充bool转换运算符实现
    Ordering::operator bool() const {
        return m_foods != nullptr && m_drinks != nullptr;
    }

    // 补充printBillTitle实现
    void Ordering::printBillTitle(std::ostream& ostr) const {
        ostr << "Bill # " << std::setw(3) << std::setfill('0') << m_billNo
             << " " << std::string(29, '=') << '\n';
    }

    // 补充printTotals实现
    void Ordering::printTotals(std::ostream& ostr, double total) const {
        double tax = total * Tax;
        ostr << std::fixed << std::setprecision(2);
        ostr << "                     Total: " << std::setw(12) << total << '\n';
        ostr << "                     Tax: " << std::setw(14) << tax << '\n';
        ostr << "                     Total+Tax: " << std::setw(8) << total + tax << '\n';
        ostr << std::string(40, '=') << '\n';
    }

    size_t Ordering::countRecords(const char* file) const {
        size_t count = 0;
        std::ifstream inFile(file);
        if(inFile) {
            char ch;
            while(inFile.get(ch)) {
                if(ch == '\n') count++;
            }
        }
        return count;
    }

    size_t Ordering::noOfBillItems() const {
        return m_billCnt;  // 直接返回账单项目数量
    }
}
