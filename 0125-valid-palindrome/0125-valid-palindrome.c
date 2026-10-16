#include <ctype.h>
#include <string.h>

bool isPalindrome(char* s) {
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        if (!isalnum((unsigned char)s[i])){
            i++; 
            continue; 
        }
        if (!isalnum((unsigned char)s[j])) {
            j--; 
            continue; 
        }
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])){ 
            return false;
        }
        i++;
        j--;
    }
    return true;
}