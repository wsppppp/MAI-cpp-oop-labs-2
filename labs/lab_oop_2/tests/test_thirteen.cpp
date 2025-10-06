#include <gtest/gtest.h>
#include "thirteen.h"

// Универсальный тест — объединяет разные проверки
TEST(ThirteenSuite, CreationAndBasicOps) {
    // Из строки, из списка, из одного разряда
    Thirteen x("CBA");       // только буквы (12, 11, 10)
    Thirteen y{10, 11, 12};  // тоже только буквы, но порядок младший → старший

    ASSERT_EQ(x.len(), 3);
    ASSERT_EQ(y.len(), 3);

    // Проверка корректности разрядов
    EXPECT_EQ(x.get(0), 10); // младший разряд (A)
    EXPECT_EQ(x.get(1), 11); // средний (B)
    EXPECT_EQ(x.get(2), 12); // старший (C)

    EXPECT_EQ(y.get(0), 10); // младший разряд (A)
    EXPECT_EQ(y.get(1), 11); // средний (B)
    EXPECT_EQ(y.get(2), 12); // старший (C)

    // Число с одним разрядом
    Thirteen single("5");
    ASSERT_EQ(single.len(), 1);
    EXPECT_EQ(single.get(0), 5);

    // Число с нулями
    Thirteen zeros("000A"); // 10
    zeros.print(); // Просто для визуального контроля, можно убрать

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

    // Проверка суммы
    EXPECT_EQ(sum.len(), 3);
    EXPECT_EQ(sum.get(0), 7); // младший
    EXPECT_EQ(sum.get(1), 0);
    EXPECT_EQ(sum.get(2), 3); // старший

    // Проверка разности
    EXPECT_EQ(diff.len(), 2);
    EXPECT_EQ(diff.get(0), 10); // младший
    EXPECT_EQ(diff.get(1), 8);  // старший

    // Проверка print для суммы и разности (вывод в строку)
    std::stringstream ss_sum, ss_diff;
    sum.print(ss_sum);
    diff.print(ss_diff);
    EXPECT_EQ(ss_sum.str(), "307");
    EXPECT_EQ(ss_diff.str(), "8A");
}

// Тест граничных и ошибочных случаев
TEST(ThirteenSuite, EdgeCases) {
    // Попытка создать число с невалидным разрядом через initializer_list
    EXPECT_THROW((Thirteen{13}), std::invalid_argument);

    // Попытка создать число из строки с невалидным символом
    EXPECT_THROW(Thirteen("1Z"), std::invalid_argument);

    // Попытка сложить числа с одним разрядом
    Thirteen a("C"), b("C");
    Thirteen s = Thirteen::add13(a, b);
    EXPECT_EQ(s.len(), 2);
    EXPECT_EQ(s.get(0), 11); // 12+12=24 → 24%13=11
    EXPECT_EQ(s.get(1), 1);  // 24/13=1

    // Вычитание с отрицательным результатом
    Thirteen small("1"), big("A");
    EXPECT_THROW(Thirteen::sub13(small, big), std::invalid_argument);

    // Проверка сравнения для одинаковых чисел
    Thirteen x("B"), y("B");
    EXPECT_TRUE(Thirteen::equals(x, y));
    EXPECT_FALSE(Thirteen::greater(x, y));
    EXPECT_FALSE(Thirteen::less(x, y));
}