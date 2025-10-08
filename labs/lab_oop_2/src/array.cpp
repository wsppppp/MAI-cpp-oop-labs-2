#include "../include/array.h"

Array::Array() : v() {}


Array::Array(const size_t& n, unsigned char t) : v(n, t) {
    if (t > 12) throw std::invalid_argument("digit must be 0-12 ");
}


Array::Array(const std::initializer_list<unsigned char>& t) : v(t) {
    for (unsigned char d : v)
        if (d > 12) throw std::invalid_argument("digit must be 0-12");
}


// из строки
Array::Array(const std::string& t) : v() {
    for (auto it = t.rbegin(); it != t.rend(); ++it) {
        char c = *it;
        unsigned char digit;
        if (c >= '0' && c <= '9')
            digit = c - '0';
        else if (c == 'A' || c == 'a')
            digit = 10;
        else if (c == 'B' || c == 'b')
            digit = 11;
        else if (c == 'C' || c == 'c')
            digit = 12;
        else
            throw std::invalid_argument("Invalid digit in string for base 13");
        v.push_back(digit);
    }
}


// копирование
Array::Array(const Array& other) : v(other.v) {}


// move-rонструктор
Array::Array(Array&& other) noexcept : v(std::move(other.v)) {}


Array::~Array() noexcept = default;


void Array::push(unsigned char digit) {
    if (digit > 12) throw std::invalid_argument("digit must be 0-12");
    v.push_back(digit);
}


void Array::pop() {
    if (v.empty()) throw std::out_of_range("pop from empty");
    v.pop_back();
}


void Array::clear() {
    v.clear();
}


unsigned char Array::get(size_t idx) const {
    if (idx >= v.size()) throw std::out_of_range("index out of range");
    return v[idx];
}


size_t Array::len() const {
    return v.size();
}



