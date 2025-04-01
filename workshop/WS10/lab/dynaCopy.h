/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * Name :	Yicheng Wang
 * Email :	ywang841@myseneca.ca
 * Student ID :	150868206
 * Date :	2025/4/1
 */
#ifndef SENECA_DYNA_COPY_H
#define SENECA_DYNA_COPY_H

#include <iostream> // 必须包含iostream用于输出

namespace seneca {

    // 两参数版本：返回新分配的指针
    template <typename T>
    T* dynaCopy(const T* src, int size) {
        if (size <= 0 || !src) return nullptr;
        T* dest = new T[size];
        for (int i = 0; i < size; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }

    // 三参数版本：修改目标指针并返回
    template <typename T>
    T* dynaCopy(T*& dest, const T* src, int size) {
        delete[] dest;
        dest = new T[size];
        for (int i = 0; i < size; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }

    // nullptr结尾版本
    template <typename T>
    T* dynaCopy(const T* src) {
        if (!src) return nullptr;
        int size = 0;
        while (src[size] != nullptr) ++size;
        return dynaCopy(src, size);
    }

    // 打印函数保持不变
    template <typename T>
    void prnArray(const T* arr, int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

} // namespace seneca

#endif
