#include <iostream>
#include "../include/thirteen.h"

using namespace std;
int main() {
    Thirteen a("1B2");
    Thirteen b("7AC");

    // проверка сравнений
    if (Thirteen::greater(a, b))
        cout << "a > b" << "\n";
    else if (Thirteen::less(a, b))
        cout << "a < b" << "\n";
    else
        cout << "a == b" << "\n";

    // Сложение
    Thirteen sum = Thirteen::add13(a, b);
    cout << "a + b = ";
    sum.print();
    cout << "\n";

    // Вычитание с оберткой исключения
    try {
        Thirteen diff = Thirteen::sub13(a, b);
        cout << "a - b = ";
        diff.print();
        cout << "\n";
    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}