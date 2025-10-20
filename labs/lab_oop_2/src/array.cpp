#include "../include/array.h"
#include <algorithm>

Array::Array() : data(new unsigned char[1]{0}), size(1) {}

Array::Array(const size_t& n, unsigned char t) : data(new unsigned char[n]), size(n) {
    validateDigit(t);
    std::fill(data, data + n, t);
}

Array::Array(const std::initializer_list<unsigned char>& t) : data(new unsigned char[t.size()]), size(t.size()) {
    if (t.size() == 0)
        throw std::invalid_argument("empty initializer_list not allowed");
    size_t idx = 0;
    for (unsigned char d : t) {
        validateDigit(d);
        data[idx++] = d;
    }
}

Array::Array(const std::string& t) : data(nullptr), size(0) {
    if (t.empty()) {
        data = new unsigned char[1]{0};
        size = 1;
        return;
    }

    size = std::count_if(t.begin(), t.end(), [](char c) { return c != ' '; });
    data = new unsigned char[size];
    size_t idx = 0;
    for (auto it = t.rbegin(); it != t.rend(); ++it) {
        char c = *it;
        if (c == ' ') continue;
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
        validateDigit(digit);
        data[idx++] = digit;
    }
}

// Конструктор копирования
Array::Array(const Array& other) : data(new unsigned char[other.size]), size(other.size) {
    std::copy(other.data, other.data + other.size, data);
}

// Конструктор перемещения
Array::Array(Array&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

// Деструктор
Array::~Array() {
    delete[] data;
}

// Получение элемента по индексу
unsigned char Array::get(size_t idx) const {
    if (idx >= size) throw std::out_of_range("index out of range");
    return data[idx];
}

// Получение длины массива
size_t Array::len() const {
    return size;
}

// Копирование массива
Array Array::copy() const {
    return Array(*this);
}

// удаление ведущих
void Array::removeZeroes() {
    if (size == 0) {
        return;
    }


    size_t newSize = size;
    for (size_t i = size - 1; i > 0; i--) {
        if (data[i] == 0) {
            newSize--;
        } else {
            break;
        }
    }

    if (newSize != size) {
        unsigned char* newData = new unsigned char[newSize];
        for (size_t i = 0; i < newSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }
}

Array Array::removeZeroesCopy() const {
    size_t newSize = size;
    while (newSize > 1 && data[newSize - 1] == 0) {
        --newSize;
    }
    if (newSize == 0) {
        return Array(1, 0);
    }
    Array newArray(newSize);
    for (size_t i = 0; i < newSize; ++i) {
        newArray.data[i] = data[i];
    }
    return newArray;
}

Array::Array(const unsigned char* arr, size_t n) {
    if (n == 0) {
        data = new unsigned char[1]{0};
        size = 1;
    } else {
        data = new unsigned char[n];
        size = n;
        for (size_t i = 0; i < n; ++i) {
            validateDigit(arr[i]);
            data[i] = arr[i];
        }
    }
}