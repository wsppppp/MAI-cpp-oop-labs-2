#include "../include/array.h"

Array::Array() : data() {}
Array::Array(size_t n, unsigned char t) : data(n, t) {}

Array::Array(const std::initializer_list<unsigned char>& t) : data(t) {}

Array::Array(const std::string& t) : data() {
    data.reserve(t.size());
    for (char c : t) { 
        if (c < '0' || c > '9')
            throw std::invalid_argument("invalid character in string");
        data.push_back(static_cast<unsigned char>(c - '0')); // делаем из строки цифры
    }
}


Array::Array(const Array& other) : data(other.data) {}

Array::Array(Array&& other) noexcept : data(std::move(other.data)) {}
Array::~Array() noexcept = default;


bool Array::operator==(const Array& other) const {
    return data == other.data;
}

bool Array::operator!=(const Array& other) const {
    return data != other.data;
}

bool Array::operator<(const Array& other) const {
    return data < other.data;
}
bool Array::operator>(const Array& other) const {
    return data > other.data;
}

Array Array::operator+(const Array& other) const {
    size_t max_size = std::max(data.size(), other.data.size());
    Array res(max_size, 0);
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < data.size()) ? data[i] : 0;
        unsigned char b = (i < other.data.size()) ? other.data[i] : 0;
        res.data[i] = a + b; 
    }
    return res;
}

Array Array::operator-(const Array& other) const {
    size_t max_size = std::max(data.size(), other.data.size());
    Array res(max_size, 0);
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < data.size()) ? data[i] : 0; 
        unsigned char b = (i < other.data.size()) ? other.data[i] : 0;
        res.data[i] = (a > b) ? (a - b) : 0;
    }
    return res;
}

unsigned char Array::operator[](size_t idx) const {
    if (idx >= data.size())
        throw std::out_of_range("index out of range");
    return data[idx];
}

size_t Array::size() const {
    return data.size();
}

void Array::push_back(unsigned char value) {
    data.push_back(value);
}
void Array::pop_back() {
    if (data.empty()) {
        throw std::out_of_range("error: empty array");
    }
    data.pop_back();
}
unsigned char Array::back() const {
    return data.back();
}

void Array::set(size_t idx, unsigned char value) {
    if (idx >= data.size())
        throw std::out_of_range("index out of range in set()");
    data[idx] = value;
}