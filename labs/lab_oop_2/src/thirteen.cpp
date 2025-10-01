#include "../include/thirteen.h"
#include <algorithm>
#include <sstream>


// 0 по умолчанию
Thirteen::Thirteen() : digits_(1, 0) {}

// Валидация
void Thirteen::check(const Array& arr) const {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > 12)
            throw std::invalid_argument("digit out of range");
    }
}

// удаление ведущих нулей
void Thirteen::normalize() {
    while (digits_.size() > 1 && digits_.operator[](digits_.size() - 1) == 0)
        digits_.pop_back();
}

// Из строки
Thirteen::Thirteen(const std::string& str) {
    Array arr;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        unsigned char value;
        if (*it >= '0' && *it <= '9') {
            value = *it - '0';
        } else if (*it >= 'A' && *it <= 'C') {
            value = 10 + (*it - 'A');
        } else {
            throw std::invalid_argument("invalid digit in string");
        }
        arr.push_back(value); 
    }
    check(arr);
    digits_ = arr;
    normalize();
}

// Из массива цифр
Thirteen::Thirteen(const Array& arr) : digits_(arr) {
    check(digits_);
    normalize();
}

// копия
Thirteen::Thirteen(const Thirteen& other) : digits_(other.digits_) {}

// move-конструктор
Thirteen::Thirteen(Thirteen&& other) noexcept : digits_(std::move(other.digits_)) {}

// Деструктор
Thirteen::~Thirteen() noexcept = default;


// Сложение
Thirteen Thirteen::operator+(const Thirteen& other) const {
    size_t max_size = std::max(digits_.size(), other.digits_.size());
    Array result(max_size, 0);
    unsigned char carry = 0; 
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < digits_.size()) ? digits_[i] : 0;
        unsigned char b = (i < other.digits_.size()) ? other.digits_[i] : 0;
        unsigned char sum = a + b + carry; 
        carry = sum / 13; 
        result.set(i, sum % 13);
    }
    if (carry > 0)
        result.push_back(carry); // закидываем в конец остаток 
    return Thirteen(result);
}

// Вычитание
Thirteen Thirteen::operator-(const Thirteen& other) const {
    if (*this < other)
        throw std::invalid_argument("result < 0 not allowed");
    Array result(digits_.size(), 0);
    unsigned char borrow = 0;
    for (size_t i = 0; i < digits_.size(); ++i) {
        int a = digits_[i] - borrow; // с учетом займа
        int b = (i < other.digits_.size()) ? other.digits_[i] : 0;
        if (a < b) {
            a += 13; // занимаем
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.set(i, static_cast<unsigned char>(a - b));
    }
    // убираем ведущие нули
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    return Thirteen(result);
}


bool Thirteen::operator==(const Thirteen& other) const {
    return digits_ == other.digits_;
}

bool Thirteen::operator!=(const Thirteen& other) const {
    return !(*this == other); // юзаем реализованный ==
}

bool Thirteen::operator<(const Thirteen& other) const {
    if (digits_.size() != other.digits_.size())
        return digits_.size() < other.digits_.size();
    for (size_t i = digits_.size(); i-- > 0;) {
        if (digits_[i] != other.digits_[i])
            return digits_[i] < other.digits_[i];
    }
    return false;
}

bool Thirteen::operator>(const Thirteen& other) const {
    return other < *this; // юзаем реализованный <
}

std::string Thirteen::to_string() const {
    if (digits_.size() == 1 && digits_[0] == 0)
        return "0";
    std::ostringstream oss; // поток для записи строки
    for (size_t i = digits_.size(); i-- > 0;) {
        unsigned char val = digits_[i];
        if (val < 10)
            oss << char('0' + val);
        else
            oss << char('A' + (val - 10));
    }
    return oss.str();
}

// размер
size_t Thirteen::size() const {
    return digits_.size();
}

