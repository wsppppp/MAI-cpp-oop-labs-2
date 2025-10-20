#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

class Array {
private:
    unsigned char* data; 
    size_t size;         

    void validateDigit(unsigned char d) const {
        if (d > 12) throw std::invalid_argument("digit must be 0-12");
    }

public:
    Array();
    Array(const size_t& n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char>& t);
    Array(const std::string& t);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    Array(const unsigned char* arr, size_t n);
    ~Array();

    unsigned char get(size_t idx) const;
    size_t len() const;

    Array copy() const;  
    
    void removeZeroes(); 
    Array removeZeroesCopy() const; 
};