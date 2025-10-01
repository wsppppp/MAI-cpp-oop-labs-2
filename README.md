# MAI-cpp-oop-labs2
У меня был 11 вариант, создать класс Thirteen для работы с беззнаковыми тринадцетиричными числами, исапользуя массив где каждый элемент - тринадцетиричная цифра. Младшая цифра - младший индекс.

```
запуск из labs/lab_oop_2 
cd labs/lab_oop_2
mkdir -p build
cd build
cmake ..
make()
```
После успешной сборки появятся исполняемые файлы:
- `lab_oop_2_app` — основное приложение
- `run_tests` — тесты

Запуск тестов: 
ctest 
или
./run_tests


## ПОЛНЫЙ ЦИКЛ СБОРКИ выглядит вот так:
```
cd labs/lab_oop_2
mkdir build
cd build
cmake ..
make
./lab_oop_2_app    
ctest               
```