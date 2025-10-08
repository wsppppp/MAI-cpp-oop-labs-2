#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

class Array {

private:
    std::vector<unsigned char> v; 



public:
    Array(); 
    Array(const size_t& n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char>& t); // из списка
    Array(const std::string& t); // из строки
    Array(const Array& other); // Копирование


    Array(Array&& other) noexcept; // move-конструктор
    ~Array(); // деструктор


    void push(unsigned char digit); 
    void pop();                     
    void clear();                


    unsigned char get(size_t idx) const;
    size_t len() const;
    
};