#include <iostream>
#include "../include/thirteen.h"

using namespace std;

int main() {
    Thirteen a("A5");      
    Thirteen b("7C"); 

    // +
    Thirteen sum = a + b;
    cout << a.to_string()<< " + " << b.to_string() << " = "<< sum.to_string() << "\n";

    // -
    Thirteen diff = a - Thirteen("5");
    cout << a.to_string() << " - "<< "5"<< " = " << diff.to_string() << "\n";

    // Сравнение
    if (a > b) {
        cout << a.to_string() << " > " << b.to_string() << "\n";
    } else if (a == b) {
        cout << a.to_string() << " = " << b.to_string() << "\n";
    }else {
        cout << a.to_string() << " < " << b.to_string() << "\n";
    }

    // обрабатываем исключение
    try {
        Thirteen fail = Thirteen("5") - Thirteen("A5");
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}