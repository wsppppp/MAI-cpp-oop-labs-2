#include <iostream>
#include <string>
#include <limits> 
#include "func.h"

// Используем пространство имен std для удобства
using namespace std;

int main() {
    string input_text;
    int n;
    char old_val;
    char new_val;

    cout << "Enter the string:\n";
    getline(cin, input_text); // Используем getline для чтения строки с пробелами (до перевода каретки)

    cout << "Enter the number char for replace (n):\n";
    cin >> n;
    
    cout << "Enter the char to replace (old_value):\n";
    cin >> old_val;

    cout << "Enter the new character (new_value):\n";
    cin >> new_val;

    string res_text = replace_char(input_text, n, old_val, new_val);

    cout << "\nResult:\n";
    cout << "Original: " << input_text << "\n";
    cout << "Modified: " << res_text << "\n";

    return 0;
}