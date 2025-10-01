#include "../include/thirteen.h"
#include <algorithm>
#include <sstream>

Thirteen::Thirteen() : digits(1, 0) {}

void Thirteen::check(const Array& arr) const {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > 12)
            throw std::invalid_argument("digit out of range");
    }
}

void Thirteen::normalize() {
    while (digits.size() > 1 &&digits.operator[](digits.size() - 1) == 0)
        digits.pop_back();
}


Thirteen::Thirteen(const std::string& str) {
    Array arr;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        unsigned char value;
        if (*it >= '0' && *it <= '9') {
            value = *it -'0';
        } else if (*it >='A' && *it <= 'C') {
            value = 10 + (*it - 'A');
        } else {
            throw std::invalid_argument("invalid digit in string");
        }
        arr.push_back(value);
    }

    check(arr);
    digits = arr;
    normalize();
}

Thirteen::Thirteen(const Array& arr) : digits(arr) {
    check(digits);
    normalize();
}

Thirteen::Thirteen(const Thirteen& other) : digits(other.digits) {}
Thirteen::Thirteen(Thirteen&& other) noexcept : digits(std::move(other.digits)) {}
Thirteen::~Thirteen() noexcept = default;

Thirteen Thirteen::operator+(const Thirteen& other) const {
    size_t max_size = std::max(digits.size(), other.digits.size());
    Array result(max_size, 0);
    unsigned char carry = 0; 
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < digits.size()) ? digits[i] : 0;
        unsigned char b = (i < other.digits.size()) ? other.digits[i] : 0;
        unsigned char sum = a + b + carry; 
        carry = sum / 13; 
        result.set(i, sum % 13);
    }
    if (carry > 0)
        result.push_back(carry);
    return Thirteen(result);
}

Thirteen Thirteen::operator-(const Thirteen& other) const {
    if (*this < other)
        throw std::invalid_argument("result < 0 not allowed");
    Array result(digits.size(), 0);
    unsigned char borrow = 0;
    for (size_t i = 0; i < digits.size(); ++i) {
        int a = digits[i] - borrow; // с учетом займа
        int b = (i < other.digits.size()) ? other.digits[i] : 0;
        if (a < b) {
            a += 13;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.set(i, static_cast<unsigned char>(a - b));
    }

    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    return Thirteen(result);
}


bool Thirteen::operator==(const Thirteen& other) const {
    return digits == other.digits;
}

bool Thirteen::operator!=(const Thirteen& other) const {
    return digits != other.digits; 
}

bool Thirteen::operator<(const Thirteen& other) const {
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();
    for (size_t i = digits.size(); i-- > 0;) {
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    }
    return false;
}

bool Thirteen::operator>(const Thirteen& other) const {
    return other < *this;
}

std::string Thirteen::to_string() const {
    if (digits.size() == 1 && digits[0] == 0)
        return "0";
    std::ostringstream oss; // поток для записи строки
    for (size_t i = digits.size(); i-- > 0;) {
        unsigned char val = digits[i];
        if (val < 10)
            oss << char('0' + val);
        else
            oss << char('A' + (val - 10));
    }
    return oss.str();
}

size_t Thirteen::size() const {
    return digits.size();
}

