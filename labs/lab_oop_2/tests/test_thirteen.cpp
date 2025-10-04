#include <gtest/gtest.h>
#include "thirteen.h"

// Проверка создания из строки
TEST(ThirteenTest, FromString) {
    Thirteen b("125"); // 200 в 13-ричной системе: 1*13^2 + 2*13 + 5 = 200
    ASSERT_EQ(b.len(), 3);
    ASSERT_EQ(b.get(0), 5); // младший разряд
    ASSERT_EQ(b.get(1), 2);
    ASSERT_EQ(b.get(2), 1); // старший разряд
}

// Проверка создания из initializer_list
TEST(ThirteenTest, FromInitializerList) {
    Thirteen b{5, 2, 1}; // младший разряд первый!
    ASSERT_EQ(b.len(), 3);
    ASSERT_EQ(b.get(0), 5);
    ASSERT_EQ(b.get(1), 2);
    ASSERT_EQ(b.get(2), 1);
}

// Сравнение чисел
TEST(ThirteenTest, Compare) {
    Thirteen a("1B2"), b("125");
    ASSERT_TRUE(Thirteen::greater(a, b));
    ASSERT_FALSE(Thirteen::less(a, b));
    ASSERT_FALSE(Thirteen::equals(a, b));
}

// Сложение
TEST(ThirteenTest, Addition) {
    Thirteen a("1B2"), b("125");
    Thirteen sum = Thirteen::plus(a, b);
    // Для достоверности можно проверить младший разряд суммы
    ASSERT_EQ(sum.len(), 3);
    // Выведем ожидаемые разряды вручную: 1B2 + 125 = (1*13^2+11*13+2)+(1*13^2+2*13+5)=
    // 1B2 = 1*169 + 11*13 + 2 = 169 + 143 + 2 = 314
    // 125 = 1*169 + 2*13 + 5 = 169 + 26 + 5 = 200
    // 314 + 200 = 514
    // 514 / 13 = 39, остаток 7 (младший разряд)
    // 39 / 13 = 3, остаток 0
    // 3 / 13 = 0, остаток 3
    // Ответ: 3 0 7 (но ещё надо проверить порядок)
    // Действительно, сумма в 13-ричной: 3 0 7  (младший разряд первый)
    ASSERT_EQ(sum.get(0), 7);
    ASSERT_EQ(sum.get(1), 0);
    ASSERT_EQ(sum.get(2), 3);
}

// Вычитание (без отрицательного результата)
TEST(ThirteenTest, Subtraction_Positive) {
    Thirteen a("1B2"), b("125");
    Thirteen diff = Thirteen::sub(a, b);
    // 314 - 200 = 114
    // 114 / 13 = 8, остаток 10
    // 8 / 13 = 0, остаток 8
    // Ответ: 8A (A = 10)
    ASSERT_EQ(diff.len(), 2);
    ASSERT_EQ(diff.get(0), 10); // младший разряд
    ASSERT_EQ(diff.get(1), 8);  // старший разряд
}

// Вычитание (отрицательный результат — должно выбросить исключение)
TEST(ThirteenTest, Subtraction_Negative) {
    Thirteen a("125"), b("1B2");
    EXPECT_THROW(Thirteen::sub(a, b), std::invalid_argument);
}