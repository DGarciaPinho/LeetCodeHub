int romanToInt(char* s) {
    int cont = 0, i = 0;
    int valor = 0;

    while(s[i] != '\0') {
        cont++;
        i++;
    }

    for(int j = cont - 1; j >= 0; --j) {
        if((j > 0) && (s[j]=='M') && (s[j-1]=='C')) {
            valor += 900;
            --j;
        }
        else if((j > 0) && (s[j]=='D') && (s[j-1]=='C')) {
            valor += 400;
            --j;
        }
        else if((j > 0) && (s[j]=='C') && (s[j-1]=='X')) {
            valor += 90;
            --j;
        }
        else if((j > 0) && (s[j]=='L') && (s[j-1]=='X')) {
            valor += 40;
            --j;
        }
        else if((j > 0) && (s[j]=='X') && (s[j-1]=='I')) {
            valor += 9;
            --j;
        }
        else if((j > 0) && (s[j]=='V') && (s[j-1]=='I')) {
            valor += 4;
            --j;
        }
        else if(s[j]=='I') valor += 1;
        else if(s[j]=='V') valor += 5;
        else if(s[j]=='X') valor += 10;
        else if(s[j]=='L') valor += 50;
        else if(s[j]=='C') valor += 100;
        else if(s[j]=='D') valor += 500;
        else if(s[j]=='M') valor += 1000;
    }

    return valor;
}