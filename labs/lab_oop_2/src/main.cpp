#include <iostream>
#include "../include/thirteen.h"

using namespace std;
int main() {
    Thirteen a("1B2");
    Thirteen b("7AC");

    // Сравнение
    if (Thirteen::greater(a, b))
        cout << "a > b" << "\n";
    else if (Thirteen::less(a, b))
        cout << "a < b" << "\n";
    else
        cout << "a == b" << "\n";

    // Сложение
    Thirteen sum = Thirteen::plus(a, b);
    cout << "a + b = ";
    for (int i = sum.len() - 1; i >= 0; --i) {
        unsigned char d = sum.get(i);
        if (d < 10) cout << char('0' + d);
        else cout << char('A' + (d - 10));
    }
    cout << "\n";

    // Вычитание с оберткой исключения
    try {
        Thirteen diff = Thirteen::sub(a, b);
        cout << "a - b = ";
        for (int i = diff.len() - 1; i >= 0; --i) {
            unsigned char d = diff.get(i);
            if (d < 10) cout << char('0' + d);
            else cout << char('A' + (d - 10));
        }
        cout << "\n";
    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}