#include "func.h"

using namespace std;

string replace_char(string text, int n, char old_char, char new_char) {
    if (n <= 0) {
        return text;
    }

    int count = 0;

    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == old_char) {
            ++count;

            if (count == n) {
                text[i] = new_char;
                return text;
            }
        }
    }
    
    return text;
}