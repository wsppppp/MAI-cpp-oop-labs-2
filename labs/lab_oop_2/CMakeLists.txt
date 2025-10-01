# Указываем минимальную версию CMake, которую поддерживает мой проект
cmake_minimum_required(VERSION 3.16)

# Явно задаём имя проекта (тематика: нестандартная арифметика, 13-ричная система счисления)
project(lab-oop-2)

# Использую стандарт C++20, т.к. он поддерживает современные фичи и удобные списки инициализации
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаю директорию include, где лежат мои заголовочные файлы (array.h, thirteen.h)
include_directories(include)

# ==== Логическая библиотека ====
# Здесь собирается основная логика работы с числами
add_library(lab_oop_2_logic
    src/array.cpp     # Массив для хранения разрядов числа
    src/thirteen.cpp  # Класс для работы с 13-ричными числами
)

# ==== Основное приложение ====
# Главный исполняемый файл для демонстрации работы программы
add_executable(lab_oop_2_app src/main.cpp)
target_link_libraries(lab_oop_2_app PRIVATE lab_oop_2_logic)

# ==== Подключение GoogleTest для тестирования ====
# Я использую FetchContent, чтобы автоматически скачать и собрать GoogleTest
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip # Актуальная стабильная версия
)
FetchContent_MakeAvailable(googletest)

# ==== Тесты ====
# Здесь подключаются тесты, которые проверяют корректность работы классов Array и Thirteen
add_executable(run_tests tests/test_array.cpp tests/test_thirteen.cpp)
target_link_libraries(run_tests PRIVATE gtest_main lab_oop_2_logic)
add_test(NAME unit_tests COMMAND run_tests)