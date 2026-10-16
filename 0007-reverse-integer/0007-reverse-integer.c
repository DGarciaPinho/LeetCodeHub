int reverse(int x){
    int sum = 0, signal = 1;

    if (x == -2147483647 - 1) {
        return 0;
    }

    if(x<0){
        x = x * -1;
        signal = -1;
    }

    while(x!=0){
        if(x<10){
            sum += x;
            break;
        }
        sum += x % 10;
        x = x / 10;
        int d = x % 10;
        if (sum > 214748364 || (sum == 214748364 && d > 7)) return 0;
        sum = sum * 10;
    }

    return sum * signal;
}