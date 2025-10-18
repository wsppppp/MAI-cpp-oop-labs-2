#include "../include/thirteen.h"
#include <stdexcept>


Thirteen::Thirteen() : digits(Array()) {}

Thirteen::Thirteen(const std::string& str) : digits(Array(str).removeZeroesCopy()) {}

Thirteen::Thirteen(const Array& array) : digits(array.removeZeroesCopy()) {}

Thirteen::Thirteen(std::initializer_list<unsigned char> lst) : digits(Array(lst).removeZeroesCopy()) {}

Thirteen::Thirteen(const Thirteen& other) : digits(other.digits.copy()) {}

Thirteen::Thirteen(Thirteen&& other) noexcept : digits(std::move(other.digits)) {}

Thirteen::~Thirteen() noexcept = default;

unsigned char Thirteen::get(size_t idx) const {
    return digits.get(idx);
}

int Thirteen::len() const {
    return digits.len();
}

std::string Thirteen::to_string() const {
    if (len() == 0) return "0";

    std::string result;
    for (size_t i = len(); i-- > 0;) {
        unsigned char d = get(i);
        if (d < 10) result += char('0' + d);
        else result += char('A' + (d - 10));
        if (i > 0) result += " ";
    }
    return result;
}

void Thirteen::print(std::ostream& out) const {
    out << to_string();
}

// Сравнения
bool Thirteen::equals(const Thirteen& a, const Thirteen& b) {
    if (a.len() != b.len()) return false;
    for (size_t i = 0; i < a.len(); ++i)
        if (a.get(i) != b.get(i)) return false;
    return true;
}

bool Thirteen::greater(const Thirteen& a, const Thirteen& b) {
    if (a.len() != b.len()) return a.len() > b.len();
    for (size_t i = a.len(); i-- > 0;) {
        if (a.get(i) != b.get(i)) return a.get(i) > b.get(i);
    }
    return false;
}

bool Thirteen::less(const Thirteen& a, const Thirteen& b) {
    if (a.len() != b.len()) return a.len() < b.len();
    for (size_t i = a.len(); i-- > 0;) {
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

Thirteen Thirteen::add13(const Thirteen& a, const Thirteen& b) {
    size_t max_len = std::max(a.len(), b.len());
    unsigned char carry = 0;
    unsigned char* resultDigits = new unsigned char[max_len + 1]{};

    size_t result_size = 0;
    for (size_t i = 0; i < max_len || carry != 0; ++i) {
        unsigned char da = (i < a.len()) ? a.get(i) : 0;
        unsigned char db = (i < b.len()) ? b.get(i) : 0;
        unsigned char sum = da + db + carry;
        resultDigits[i] = sum % 13;
        carry = sum / 13;
        result_size = i + 1;
    }
    // Гарантируем, что массив не пустой
    if (result_size == 0) {
        resultDigits[0] = 0;
        result_size = 1;
    }
    Thirteen result(Array(resultDigits, result_size));
    delete[] resultDigits;
    return result;
}

Thirteen Thirteen::sub13(const Thirteen& a, const Thirteen& b) {
    if (less(a, b)) {
        throw std::invalid_argument("error: negative result");
    }

    size_t max_len = a.len();
    unsigned char borrow = 0;
    unsigned char* resultDigits = new unsigned char[max_len]{};

    size_t result_size = 0;
    for (size_t i = 0; i < max_len; ++i) {
        int da = a.get(i) - borrow;
        int db = (i < b.len()) ? b.get(i) : 0;

        if (da < db) {
            da += 13;
            borrow = 1;
        } else {
            borrow = 0;
        }
        resultDigits[i] = static_cast<unsigned char>(da - db);
        result_size = i + 1;
    }
    // Гарантируем, что массив не пустой
    if (result_size == 0) {
        resultDigits[0] = 0;
        result_size = 1;
    }
    Thirteen result(Array(resultDigits, result_size)); 
    delete[] resultDigits;
    return result;
}


// Удаление ведущих нулей
Thirteen Thirteen::delZeroes() const {
    return Thirteen(digits.removeZeroesCopy());
}