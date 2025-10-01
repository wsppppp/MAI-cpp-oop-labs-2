#pragma once
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>

class Array {
public:
    Array(); // пустой массив
    Array(size_t n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char>& t); // из массива
    Array(const std::string& t); // из строки
    
    Array(const Array& other); // копия
    Array(Array&& other) noexcept; 
    virtual ~Array() noexcept;

    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    bool operator<(const Array& other) const;
    bool operator>(const Array& other) const;

    Array operator+(const Array& other) const;
    Array operator-(const Array& other) const;
    Array& operator=(const Array& other) = default;
    Array& operator=(Array&& other) noexcept = default;
    unsigned char operator[](size_t idx) const;

    // Размер массива
    size_t size() const;

    void push_back(unsigned char value); // новый элемент в конец
    void pop_back(); // убрать последний
    unsigned char back() const; // вернуть последний 
    void set(size_t idx, unsigned char value); // установить по индексу

protected:
    std::vector<unsigned char> data; // внутреннее хранилище 
};