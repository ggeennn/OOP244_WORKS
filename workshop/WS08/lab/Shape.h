/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/3/18
 */
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca
{

   class Shape
   {
   public:

      virtual void draw(std::ostream &os) const = 0;
      virtual void getSpecs(std::istream &is) = 0;

      virtual ~Shape() = default;
   };

   std::ostream &operator<<(std::ostream &os, const Shape &shape);
   std::istream &operator>>(std::istream &is, Shape &shape);

}

#endif // !SENECA_SHAPE_H
