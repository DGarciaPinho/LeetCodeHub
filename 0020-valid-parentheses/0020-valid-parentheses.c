#include <string.h>

bool isValid(char* s) {
    char stack[10001];
    int top = 0;
    char *open = "([{", *close = ")]}";

    for (int i = 0; s[i]; i++) {
        char *p = strchr(open, s[i]);
        if (p) {
            stack[top++] = close[p - open]; // guarda o fechamento esperado
        } else {
            if (top == 0 || stack[--top] != s[i]) return false;
        }
    }

    return top == 0;
}