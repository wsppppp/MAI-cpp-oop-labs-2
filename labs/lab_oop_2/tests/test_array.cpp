#include <gtest/gtest.h>
#include "array.h"

// Базовые проверки: создание, push, pop, clear, копирование, перемещение
TEST(ArraySuite, BasicOpsAndEdges) {
    Array arr;
    arr.push(5);
    arr.push(7);
    arr.push(12);
    ASSERT_EQ(arr.len(), 3);
    EXPECT_EQ(arr.get(0), 5);
    EXPECT_EQ(arr.get(1), 7);
    EXPECT_EQ(arr.get(2), 12);

    // Проверка выброса при неверном разряде
    EXPECT_THROW(arr.push(13), std::invalid_argument);
    EXPECT_THROW(arr.push(255), std::invalid_argument);

    // Проверка удаления и очистки
    arr.pop(); // удалил 12
    ASSERT_EQ(arr.len(), 2);
    arr.clear();
    ASSERT_EQ(arr.len(), 0);

    // Проверка выброса при pop на пустом массиве
    EXPECT_THROW(arr.pop(), std::out_of_range);

    // Проверка конструктора из initializer_list
    Array arr2{1, 2, 3};
    ASSERT_EQ(arr2.len(), 3);
    EXPECT_EQ(arr2.get(2), 3);

    // *** УДАЛИ ЭТО ***
    // EXPECT_THROW((Array{}), std::invalid_argument);

    // Проверка конструктора из строки (буквы, нули, пробелы)
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

    // Копирование и перемещение
    Array arr4(arr3);
    ASSERT_EQ(arr4.len(), 3);
    Array arr5(std::move(arr4));
    ASSERT_EQ(arr5.len(), 3);

    // Проверка выброса при get вне диапазона
    EXPECT_THROW(arr5.get(10), std::out_of_range);

    // Конструктор из строки с пустой строкой — должен быть один разряд, равный 0
    Array arrEmpty("");
    ASSERT_EQ(arrEmpty.len(), 1);
    EXPECT_EQ(arrEmpty.get(0), 0);
}