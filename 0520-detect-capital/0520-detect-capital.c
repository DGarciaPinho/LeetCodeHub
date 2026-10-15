bool detectCapitalUse(char* word) {
    int len = 0, upper = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') upper++;
        len++;
    }
    if (upper == len || upper == 0) return true;
    if (upper == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;
    return false;
}