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
      char* m_studentName{};  
      size_t m_studentNumber{}; 

   public:
      // Constructor
      Transcript(const char* name, size_t stno);

      // Rule of Three
      Transcript(const Transcript& other);      
      Transcript& operator=(const Transcript& other); 
      ~Transcript();                              

      // Destructor
      std::ostream& display(std::ostream& ostr) const override; 
   };
}
#endif // !SENECA_TRANSCRIPT_H


