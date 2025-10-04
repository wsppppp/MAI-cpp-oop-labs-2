#include <gtest/gtest.h>
#include "../include/array.h"

// Тест конструктора и push
TEST(ArrayTest, PushAndGet) {
    Array arr;
    arr.push(5);
    arr.push(7);
    arr.push(12);
    EXPECT_EQ(arr.len(), 3);
    EXPECT_EQ(arr.get(0), 5);
    EXPECT_EQ(arr.get(1), 7);
    EXPECT_EQ(arr.get(2), 12);
}

// Тест исключения при неверном разряде
TEST(ArrayTest, InvalidDigit) {
    Array arr;
    EXPECT_THROW(arr.push(13), std::invalid_argument);
}

// Тест pop и clear
TEST(ArrayTest, PopAndClear) {
    Array arr;
    arr.push(1);
    arr.push(2);
    arr.pop();
    EXPECT_EQ(arr.len(), 1);
    arr.clear();
    EXPECT_EQ(arr.len(), 0);
    EXPECT_THROW(arr.pop(), std::out_of_range);
}


// Тест копирования и перемещения
TEST(ArrayTest, CopyMove) {
    Array arr;
    arr.push(2);
    arr.push(4);
    Array arr2(arr);
    EXPECT_EQ(arr2.len(), 2);
    EXPECT_EQ(arr2.get(1), 4);
    Array arr3(std::move(arr2));
    EXPECT_EQ(arr3.len(), 2);
    EXPECT_EQ(arr3.get(0), 2);
}