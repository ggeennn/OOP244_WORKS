/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
// Version 1.0
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript :
      public Marks {
      char* m_studentName{};  // 学生姓名（动态内存）
      size_t m_studentNumber{}; // 学生编号

   public:
      // Constructor
      Transcript(const char* name, size_t stno);

      // Rule of Three
      Transcript(const Transcript& other);       // 拷贝构造函数
      Transcript& operator=(const Transcript& other); // 拷贝赋值运算符
      ~Transcript();                              // 析构函数

      // Destructor
      std::ostream& display(std::ostream& ostr) const override; // 重写display方法
   };
}
#endif // !SENECA_TRANSCRIPT_H


