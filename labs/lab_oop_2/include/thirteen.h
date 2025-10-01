#pragma once
#include "array.h"
#include <string>
#include <stdexcept>

class Thirteen {
public:
    Thirteen();
    Thirteen(const std::string& str); // из строки
    Thirteen(const Array& arr); // из массива цифр

    Thirteen(const Thirteen& other); // копия
    Thirteen(Thirteen&& other) noexcept; // move-конструктор
    ~Thirteen() noexcept;

    bool operator==(const Thirteen& other) const;
    bool operator!=(const Thirteen& other) const;
    bool operator<(const Thirteen& other) const;
    bool operator>(const Thirteen& other) const;

    Thirteen operator+(const Thirteen& other) const;
    Thirteen operator-(const Thirteen& other) const;


    std::string to_string() const; // конвертация

    size_t size() const; // размер 

private:
    Array digits;

    void normalize();
    void check(const Array& arr) const; // валидация
};