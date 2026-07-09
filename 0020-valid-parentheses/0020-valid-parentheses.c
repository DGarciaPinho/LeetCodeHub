#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    char stack[10001];
    int top = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else {
            if (top == 0) return false;

            char last = stack[--top];
            if ((c == ')' && last != '(') || (c == ']' && last != '[') || (c == '}' && last != '{')) {
                return false;
            }
        }
    }

    return top == 0;
}