#pragma once
#include <initializer_list>
#include <iostream>
#include "array.h"

class Thirteen {
public:
    Thirteen();
    Thirteen(const std::string& str); // из строки
    Thirteen(std::initializer_list<unsigned char>); // из списка разрядов
    Thirteen(const Thirteen&); // копирование
    Thirteen(Thirteen&&) noexcept; // move-конструктор
    ~Thirteen() noexcept; // деструктор

    unsigned char get(size_t) const; 
    int len() const;  

    Array digits;
    static Thirteen plus(const Thirteen&, const Thirteen&); 
    static Thirteen sub(const Thirteen&, const Thirteen&);

    static bool equals(const Thirteen&, const Thirteen&);        // ==
    static bool greater(const Thirteen&, const Thirteen&);       // >
    static bool less(const Thirteen&, const Thirteen&);          // <
    static bool notequals(const Thirteen&, const Thirteen&);     // это !=
    static bool equalsgreater(const Thirteen&, const Thirteen&); // >=
    static bool equalsless(const Thirteen&, const Thirteen&);    // <=

private:
    void normalize(); // удалить ведущие нули
};