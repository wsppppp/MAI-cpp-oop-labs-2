#include <gtest/gtest.h>
#include "thirteen.h"

// ================== Тесты для класса Thirteen (13-ричная арифметика) ==================
// Проверяем корректность работы конструкторов, арифметики и сравнения

// Тест конструктора из строки и конвертации в строку
TEST(ThirteenTest, ConstructorAndToString) {
    Thirteen t1("A5"); // обычное число
    EXPECT_EQ(t1.to_string(), "A5");

    Thirteen t2("00A"); // ведущие нули должны исчезнуть
    EXPECT_EQ(t2.to_string(), "A");

    Thirteen t3("0"); // ноль
    EXPECT_EQ(t3.to_string(), "0");

    Thirteen t4("C"); // максимальная цифра
    EXPECT_EQ(t4.to_string(), "C");
}

// Тест арифметики: сложение и вычитание
TEST(ThirteenTest, Arithmetic) {
    Thirteen a("A5");
    Thirteen b("7C");
    Thirteen sum = a + b;
    EXPECT_EQ(sum.to_string(), "154"); // результат в 13-ричной

    Thirteen diff = a - Thirteen("5");
    EXPECT_EQ(diff.to_string(), "A0");
}

// Тест сравнения
TEST(ThirteenTest, Comparison) {
    Thirteen a("A5");
    Thirteen b("7C");
    EXPECT_TRUE(a > b);    // A5 больше 7C
    EXPECT_FALSE(a < b);   // A5 не меньше 7C
    EXPECT_FALSE(a == b);  // они не равны
}

// Тест на исключение при отрицательном результате
TEST(ThirteenTest, ExceptionOnNegativeResult) {
    Thirteen t1("5");
    Thirteen t2("A5");
    EXPECT_THROW(t1 - t2, std::invalid_argument); // нельзя получить отрицательное число
}