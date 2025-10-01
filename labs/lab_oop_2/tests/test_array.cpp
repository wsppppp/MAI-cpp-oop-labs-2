#include <gtest/gtest.h>
#include "array.h"

// Проверка конструкторов
TEST(ArrayTest, Constructors) {
    // Пустой массив (должен быть размер 0)
    Array a;
    EXPECT_EQ(a.size(), 0);

    // Массив фиксированного размера с заполнением значением 7
    Array b(5, 7);
    EXPECT_EQ(b.size(), 5);
    EXPECT_EQ(b[0], 7);

    // Массив через список инициализации (C++11 feature)
    Array c{1,2,3};
    EXPECT_EQ(c.size(), 3);
    EXPECT_EQ(c[2], 3); // последний элемент
}

// Проверка арифметики (поэлементное сложение)
TEST(ArrayTest, Arithmetic) {
    // Сложение двух массивов разных размеров
    Array a{1,2,3};
    Array b{4,5};
    Array c = a + b; // ожидаем [5,7,3]
    EXPECT_EQ(c.size(), 3);
    EXPECT_EQ(c[0], 5);
    EXPECT_EQ(c[1], 7);
    EXPECT_EQ(c[2], 3);
}

// Проверка доступа и модификации
TEST(ArrayTest, AccessAndModify) {
    Array a{1,2,3};
    a.set(1, 9); // меняем второй элемент
    EXPECT_EQ(a[1], 9);

    a.push_back(4); // добавляем элемент
    EXPECT_EQ(a.size(), 4);

    a.pop_back(); // удаляем последний элемент
    EXPECT_EQ(a.size(), 3);
    EXPECT_EQ(a.back(), 3); // последний элемент - 3
}