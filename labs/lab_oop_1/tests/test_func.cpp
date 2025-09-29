#include <gtest/gtest.h>
#include "func.h" // Подключаем наш заголовочный файл, чтобы тестировать функцию

// Тест 1: Базовый случай, успешная замена
TEST(ReplaceNthTest, BasicReplacement) {
    // Ожидаем, что замена 2-го 'a' на 'Z' в "abacaba" даст "abaZaba"
    EXPECT_EQ(replace_char("abacaba", 2, 'a', 'Z'), "abZcaba");
}

// Тест 2: Номер вхождения 'n' больше, чем количество символов
TEST(ReplaceNthTest, NIsTooLarge) {
    // Если мы хотим заменить 5-е 'a', а их всего 4, строка не должна измениться
    EXPECT_EQ(replace_char("abacaba", 5, 'a', 'Z'), "abacaba");
}

// Тест 3: Номер вхождения 'n' равен 0 или отрицательный
TEST(ReplaceNthTest, NIsZeroOrNegative) {
    // Функция должна вернуть исходную строку без изменений
    EXPECT_EQ(replace_char("abacaba", 0, 'a', 'Z'), "abacaba");
    EXPECT_EQ(replace_char("abacaba", -5, 'a', 'Z'), "abacaba");
}

// Тест 4: Заменяемого символа нет в строке
TEST(ReplaceNthTest, CharNotFound) {
    // Если мы ищем 'x' в "abacaba", ничего не должно произойти
    EXPECT_EQ(replace_char("abacaba", 1, 'x', 'Z'), "abacaba");
}

// Тест 5: Замена первого вхождения
TEST(ReplaceNthTest, FirstOccurrence) {
    EXPECT_EQ(replace_char("abacaba", 1, 'a', 'Z'), "Zbacaba");
}

// Тест 6: Замена последнего вхождения
TEST(ReplaceNthTest, LastOccurrence) {
    // В "abacaba" 4 символа 'a'
    EXPECT_EQ(replace_char("abacaba", 4, 'a', 'Z'), "abacabZ");
}

// Тест 7: Пустая строка на входе
TEST(ReplaceNthTest, EmptyString) {
    // Если строка пустая, она должна остаться пустой
    EXPECT_EQ(replace_char("", 1, 'a', 'Z'), "");
}