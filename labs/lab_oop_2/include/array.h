#pragma once
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>

class Array {
public:
    Array(); 
    Array(size_t n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char>& t);
    Array(const std::string& t);
    
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


    size_t size() const; 
    void push_back(unsigned char value); 
    void pop_back();
    unsigned char back() const; 
    void set(size_t idx, unsigned char value);

protected:
    std::vector<unsigned char> data; 
};