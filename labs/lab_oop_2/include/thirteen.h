#pragma once
#include <initializer_list>
#include <iostream>
#include "array.h"

class Thirteen {
public:
    Thirteen();
    Thirteen(const std::string& str);
    Thirteen(std::initializer_list<unsigned char>);
    Thirteen(const Thirteen&);
    Thirteen(Thirteen&&) noexcept;
    ~Thirteen() noexcept;

    unsigned char get(size_t) const;
    int len() const;
    std::string to_string() const; 

    void print(std::ostream& out = std::cout) const;

    static Thirteen add13(const Thirteen&, const Thirteen&);
    static Thirteen sub13(const Thirteen&, const Thirteen&);

    static bool equals(const Thirteen&, const Thirteen&);
    static bool greater(const Thirteen&, const Thirteen&);
    static bool less(const Thirteen&, const Thirteen&);
    static bool notequals(const Thirteen&, const Thirteen&);
    static bool equalsgreater(const Thirteen&, const Thirteen&);
    static bool equalsless(const Thirteen&, const Thirteen&);

    Array digits;

private:
    void delZeroes();
};