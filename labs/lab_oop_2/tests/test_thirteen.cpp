#include <gtest/gtest.h>
#include "thirteen.h"

// Универсальный тест — объединяет разные проверки
TEST(ThirteenSuite, CreationAndBasicOps) {
    Thirteen x("CBA");       // только буквы (12, 11, 10)
    Thirteen y{10, 11, 12};  // тоже только буквы, но порядок младший → старший

    ASSERT_EQ(x.len(), 3);
    ASSERT_EQ(y.len(), 3);

    EXPECT_EQ(x.to_string(), "C B A");
    EXPECT_EQ(y.to_string(), "C B A");

    Thirteen single("5");
    ASSERT_EQ(single.len(), 1);
    EXPECT_EQ(single.to_string(), "5");

    Thirteen zeros("000A"); // 10
    Thirteen trimmedZeros = zeros.delZeroes();
    EXPECT_EQ(trimmedZeros.to_string(), "A");

    Thirteen spaced("  A   2   "); // Пустые пробелы!
    EXPECT_EQ(spaced.to_string(), "A 2");

    // Проверка сравнения
    EXPECT_TRUE(Thirteen::equals(x, y));
    EXPECT_FALSE(Thirteen::notequals(x, y));
    EXPECT_TRUE(Thirteen::greater(x, single));
    EXPECT_TRUE(Thirteen::less(single, x));
    EXPECT_TRUE(Thirteen::equalsless(single, x));
    EXPECT_TRUE(Thirteen::equalsgreater(x, y));
}

// Тест арифметики и вывода
TEST(ThirteenSuite, AddAndShow) {
    Thirteen a("1B2"), b("125");
    Thirteen sum = Thirteen::add13(a, b);
    Thirteen diff = Thirteen::sub13(a, b);

    EXPECT_EQ(sum.to_string(), "3 0 7");
    EXPECT_EQ(diff.to_string(), "8 A");
}

// Тест граничных и ошибочных случаев
TEST(ThirteenSuite, EdgeCases) {
    EXPECT_THROW((Thirteen{13}), std::invalid_argument);
    EXPECT_THROW(Thirteen("1Z"), std::invalid_argument);

    Thirteen empty_str("");
    EXPECT_EQ(empty_str.to_string(), "0");

    Thirteen a("C"), b("C");
    Thirteen s = Thirteen::add13(a, b);
    EXPECT_EQ(s.to_string(), "1 B");

    Thirteen small("1"), big("A");
    EXPECT_THROW(Thirteen::sub13(small, big), std::invalid_argument);

    Thirteen x("B"), y("B");
    EXPECT_TRUE(Thirteen::equals(x, y));
    EXPECT_FALSE(Thirteen::greater(x, y));
    EXPECT_FALSE(Thirteen::less(x, y));
}