#include "../include/array.h"

Array::Array() : data_() {}
Array::Array(size_t n, unsigned char t) : data_(n, t) {}

// Из массива
Array::Array(const std::initializer_list<unsigned char>& t) : data_(t) {}

// Из строки
Array::Array(const std::string& t) : data_() {
    data_.reserve(t.size());
    // цикл по символам строки
    for (char c : t) { 
        if (c < '0' || c > '9')
            throw std::invalid_argument("invalid character in string");
        data_.push_back(static_cast<unsigned char>(c - '0')); // делаем из строки цифры
    }
}

// Копия
Array::Array(const Array& other) : data_(other.data_) {}

// move-конструктор
Array::Array(Array&& other) noexcept : data_(std::move(other.data_)) {}

// Деструктор
Array::~Array() noexcept = default;


// сложение (поэлементное)
Array Array::operator+(const Array& other) const {
    size_t max_size = std::max(data_.size(), other.data_.size());
    Array res(max_size, 0);
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < data_.size()) ? data_[i] : 0;
        unsigned char b = (i < other.data_.size()) ? other.data_[i] : 0;
        res.data_[i] = a + b; 
    }
    return res;
}

// Вычитание (поэлементное)
Array Array::operator-(const Array& other) const {
    size_t max_size = std::max(data_.size(), other.data_.size());
    Array res(max_size, 0);
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < data_.size()) ? data_[i] : 0; // если вышли за пределы, считаем как 0
        unsigned char b = (i < other.data_.size()) ? other.data_[i] : 0;
        res.data_[i] = (a > b) ? (a - b) : 0;
    }
    return res;
}

// сравнение

bool Array::operator==(const Array& other) const {
    return data_ == other.data_;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

// Лексикографическое сравнение
bool Array::operator<(const Array& other) const {
    return data_ < other.data_;
}
bool Array::operator>(const Array& other) const {
    return data_ > other.data_;
}

// Доступ к элементам 
unsigned char Array::operator[](size_t idx) const {
    if (idx >= data_.size())
        throw std::out_of_range("index out of range");
    return data_[idx];
}

// Размер массива
size_t Array::size() const {
    return data_.size();
}

void Array::push_back(unsigned char value) {
    data_.push_back(value);
}

void Array::pop_back() {
    if (data_.empty()) {
        throw std::out_of_range("error: empty array");
    }
    data_.pop_back();
}

unsigned char Array::back() const {
    return data_.back();
}

void Array::set(size_t idx, unsigned char value) {
    if (idx >= data_.size())
        throw std::out_of_range("index out of range in set()");
    data_[idx] = value;
}