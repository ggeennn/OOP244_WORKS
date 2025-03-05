/***********************************************************************
// OOP244 Workshop 6 lab
//
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca
{
   class Numbers
   {
      double *m_numbers;
      char *m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty() const;
      void setEmpty();
      void setFilename(const char *filename);
      void sort();
      void save();
      size_t numberCount() const;
      bool load();

   public:
      Numbers();
      Numbers(const char *filename);
      Numbers(const Numbers &other);
      ~Numbers();
      Numbers &operator=(const Numbers &other);
      Numbers &operator+=(double value);
      std::ostream &display(std::ostream &ostr) const;
      double average() const;
      double max() const;
      double min() const;
   };

   std::ostream &operator<<(std::ostream &os, const Numbers &N);
   std::istream &operator>>(std::istream &istr, Numbers &N);
}
#endif // !SENECA_NUMBERS_H_
