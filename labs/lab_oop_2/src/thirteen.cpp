#include "../include/thirteen.h"
#include <stdexcept>
#include <iostream>


Thirteen::Thirteen() : digits() {
    digits.push(0);
}


void Thirteen::delZeroes() {
    while (digits.len() > 1 && digits.get(digits.len() - 1) == 0)
        digits.pop();
}


Thirteen::Thirteen(std::initializer_list<unsigned char> lst) : digits() {
    for (auto d : lst) {
        if (d > 12) throw std::invalid_argument("digit must be 0-12");
        digits.push(d);
    }
    delZeroes();
}


// из строки
Thirteen::Thirteen(const std::string& str) : digits(str) {
    delZeroes();
}


// копирование
Thirteen::Thirteen(const Thirteen& other) : digits(other.digits) {}


// move-конструктор
Thirteen::Thirteen(Thirteen&& other) noexcept : digits(std::move(other.digits)) {}


// Деструктор
Thirteen::~Thirteen() noexcept = default;


unsigned char Thirteen::get(size_t idx) const {
    return digits.get(idx);
}


int Thirteen::len() const {
    return digits.len();
}


// тут у нас все сравнения
bool Thirteen::equals(const Thirteen& a, const Thirteen& b) {
    if (a.len() != b.len()) return false;
    for (int i = 0; i < a.len(); ++i)
        if (a.get(i) != b.get(i)) return false;
    return true;
}


bool Thirteen::greater(const Thirteen& a, const Thirteen& b) {
    if (a.len() != b.len()) return a.len() > b.len();
    for (int i = a.len() - 1; i >= 0; --i) {
        if (a.get(i) != b.get(i)) return a.get(i) > b.get(i);
    }
    return false;
}


bool Thirteen::less(const Thirteen& a, const Thirteen& b) {
    if (a.len() != b.len()) return a.len() < b.len();
    for (int i = a.len() - 1; i >= 0; --i) {
        if (a.get(i) != b.get(i)) return a.get(i) < b.get(i);
    }
    return false;
}


bool Thirteen::notequals(const Thirteen& a, const Thirteen& b) {
    return !equals(a, b);
}


bool Thirteen::equalsgreater(const Thirteen& a, const Thirteen& b) {
    return greater(a, b) || equals(a, b);
}


bool Thirteen::equalsless(const Thirteen& a, const Thirteen& b) {
    return less(a, b) || equals(a, b);
}


// тут у нас сложение типа в столбик! 
Thirteen Thirteen::add13(const Thirteen& a, const Thirteen& b) {
    Thirteen res;
    res.digits.clear();

    size_t n = std::max(a.len(), b.len());
    unsigned char carry = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned char da = (i < a.len()) ? a.get(i) : 0;
        unsigned char db = (i < b.len()) ? b.get(i) : 0;
        unsigned char s = da + db + carry;
        carry = s / 13;
        res.digits.push(s % 13);
    }
    if (carry) res.digits.push(carry);
    res.delZeroes();
    return res;
}


// тут у нас вычитание с проверкой!
Thirteen Thirteen::sub13(const Thirteen& a, const Thirteen& b) {
    if (less(a, b)) throw std::invalid_argument("error: negative result");
    Thirteen res;
    res.digits.clear();

    unsigned char borrow = 0; // заём, если не хватает в разряде
    for (size_t i =0; i < a.len(); ++i) {
        int da = a.get(i)- borrow; // учитываем заём, который брали в предыдущем разряде
        int db = (i < b.len()) ? b.get(i) : 0;
        if (da < db) {
            da += 13;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.digits.push(static_cast<unsigned char>(da - db));
    }
    res.delZeroes();
    return res;
}


void Thirteen::print(std::ostream& out) const {
    for (int i = digits.len() - 1; i >= 0; --i) {
        unsigned char d = digits.get(i);
        if (d < 10) out << char('0' + d);
        else out << char('A' + (d - 10));
    }
}

