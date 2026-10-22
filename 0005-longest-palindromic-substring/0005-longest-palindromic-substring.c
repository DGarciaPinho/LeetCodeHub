#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool palindromo(const char *palavra, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        if (palavra[i] != palavra[j]) return false;
        i++; j--;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int n = (int) strlen(s);
    int inicio = 0, maior = (n > 0) ? 1 : 0;

    for (int i = 0; i < n; i++) {
        // testa do maior tamanho possÃ­vel para baixo; sÃ³ vale a pena se superar 'maior'
        for (int len = n - i; len > maior; len--) {
            if (palindromo(s + i, len)) {   // s + i: comeÃ§a no Ã­ndice i
                inicio = i;
                maior = len;
                break;
            }
        }
    }

    char *res = malloc(maior + 1);
    memcpy(res, s + inicio, maior);
    res[maior] = '\0';
    return res;
}