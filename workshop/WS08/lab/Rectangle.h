/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/18
 */
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      int m_width;  
      int m_height; 

   public:
      Rectangle();
      Rectangle(const char* label, int width, int height);

      void draw(std::ostream& os) const override;
      void getSpecs(std::istream& is) override;
   };

}

#endif // !SENECA_RECTANGLE_H
