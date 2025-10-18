#include <gtest/gtest.h>
#include "array.h"

// Базовые проверки: создание, копирование, перемещение
TEST(ArraySuite, BasicOpsAndEdges) {
    // Проверка конструктора по умолчанию
    Array arr;
    ASSERT_EQ(arr.len(), 1);
    EXPECT_EQ(arr.get(0), 0);

    // Проверка конструктора из initializer_list
    Array arr2{1, 2, 3};
    ASSERT_EQ(arr2.len(), 3);
    EXPECT_EQ(arr2.get(0), 1);
    EXPECT_EQ(arr2.get(1), 2);
    EXPECT_EQ(arr2.get(2), 3);

    // Проверка конструктора из строки
    Array arr3("0A B");
    ASSERT_EQ(arr3.len(), 3);
    EXPECT_EQ(arr3.get(0), 11); // B
    EXPECT_EQ(arr3.get(1), 10); // A
    EXPECT_EQ(arr3.get(2), 0);  // 0

    // Конструктор из строки с нижним регистром
    Array arrLow("abc");
    EXPECT_EQ(arrLow.get(0), 12); // c
    EXPECT_EQ(arrLow.get(1), 11); // b
    EXPECT_EQ(arrLow.get(2), 10); // a

    // Конструктор из строки с невалидным символом
    EXPECT_THROW(Array("1Z2"), std::invalid_argument);

    // Копирование
    Array arr4(arr3);
    ASSERT_EQ(arr4.len(), 3);
    EXPECT_EQ(arr4.get(0), 11);
    EXPECT_EQ(arr4.get(1), 10);
    EXPECT_EQ(arr4.get(2), 0);

    // Перемещение
    Array arr5(std::move(arr4));
    ASSERT_EQ(arr5.len(), 3);
    EXPECT_EQ(arr5.get(0), 11);
    EXPECT_EQ(arr5.get(1), 10);
    EXPECT_EQ(arr5.get(2), 0);

    // Проверка выброса при get вне диапазона
    EXPECT_THROW(arr5.get(10), std::out_of_range);

    // Конструктор из строки с пустой строкой — должен быть один разряд, равный 0
    Array arrEmpty("");
    ASSERT_EQ(arrEmpty.len(), 1);
    EXPECT_EQ(arrEmpty.get(0), 0);
}

// Проверка удаления ведущих нулей
TEST(ArraySuite, RemoveZeroes) {
    Array arr("00012");
    Array trimmed = arr.removeZeroesCopy();
    ASSERT_EQ(trimmed.len(), 2);
    EXPECT_EQ(trimmed.get(0), 2);
    EXPECT_EQ(trimmed.get(1), 1);

    Array singleZero("0");
    Array trimmedSingle = singleZero.removeZeroesCopy();
    ASSERT_EQ(trimmedSingle.len(), 1);
    EXPECT_EQ(trimmedSingle.get(0), 0);

    Array allZeroes("000");
    Array trimmedAllZeroes = allZeroes.removeZeroesCopy();
    ASSERT_EQ(trimmedAllZeroes.len(), 1);
    EXPECT_EQ(trimmedAllZeroes.get(0), 0);
}