cmake_minimum_required(VERSION 3.16)
project(lab-oop-1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- ОБЩИЕ НАСТРОЙКИ ---
# Указываем CMake, где искать заголовочные файлы (.h) для ВСЕХ частей проекта.
include_directories(include)

# Создаем "библиотеку" из нашей основной логики (func.cpp).
# Это позволяет использовать ее и в основном приложении, и в тестах.
add_library(my_logic src/func.cpp)


# --- ОСНОВНОЕ ПРИЛОЖЕНИЕ (ТВОЙ main.cpp) ---
# Создаем исполняемый файл lab1_app из main.cpp
add_executable(lab1_app src/main.cpp)

# "Связываем" (link) основное приложение с нашей логикой.
# Теперь main.cpp "видит" функции из func.cpp.
target_link_libraries(lab1_app PRIVATE my_logic)


# --- НАСТРОЙКА ТЕСТОВ ---
# Включаем фреймворк CTest, который управляет тестами
enable_testing()

# Подключаем FetchContent для скачивания Google Test из интернета
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Скачиваем и настраиваем Google Test (только если его еще нет)
FetchContent_MakeAvailable(googletest)

# Создаем отдельный исполняемый файл для тестов
add_executable(run_tests tests/test_func.cpp)

# Связываем наши тесты с:
# 1. Библиотекой Google Test (gtest_main)
# 2. Нашей логикой, которую мы хотим протестировать (my_logic)
target_link_libraries(run_tests PRIVATE gtest_main my_logic)

# Добавляем наш тестовый исполняемый файл в список тестов CTest
add_test(NAME unit_tests COMMAND run_tests)