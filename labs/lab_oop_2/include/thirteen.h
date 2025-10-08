#pragma once
#include <initializer_list>
#include <iostream>
#include "array.h"

class Thirteen {

private:
    void delZeroes(); // удалить ведущие нули


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
    static Thirteen add13(const Thirteen&, const Thirteen&); 
    static Thirteen sub13(const Thirteen&, const Thirteen&);


    void print(std::ostream& out = std::cout) const;


    static bool equals(const Thirteen&, const Thirteen&);        // ==
    static bool greater(const Thirteen&, const Thirteen&);       // >
    static bool less(const Thirteen&, const Thirteen&);          // <
    static bool notequals(const Thirteen&, const Thirteen&);     // это !=
    static bool equalsgreater(const Thirteen&, const Thirteen&); // >=
    static bool equalsless(const Thirteen&, const Thirteen&);    // <=
};