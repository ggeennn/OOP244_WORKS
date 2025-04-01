/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/4/1
 */
#ifndef SENECA_DYNA_COPY_H
#define SENECA_DYNA_COPY_H

#include <iostream>

namespace seneca
{

    template <typename T>
    T *dynaCopy(const T *src, int size)
    {
        T *dest = nullptr;
        if (size > 0 && src)
        {
            dest = new T[size];
            for (int i = 0; i < size; ++i)
            {
                dest[i] = src[i];
            }
        }
        return dest;
    }

    template <typename T>
    T *dynaCopy(T *&dest, const T *src, int size)
    {
        if (size > 0 && src)
        {
            if (src != dest)
            {
                delete[] dest;
                dest = new T[size];
                for (int i = 0; i < size; ++i)
                {
                    dest[i] = src[i];
                }
            }
        } else {
            delete[] dest;
            dest = nullptr;
        }
        return dest;
    }

    template <typename T>
    void prnArray(const T *arr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i];
            if (i < size - 1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }

} // namespace seneca

#endif
