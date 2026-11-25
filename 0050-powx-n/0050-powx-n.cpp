class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return npow(x, n);
        } else {
            return pow(x, n);
        }
    }

    double pow(double x, long long n) {
        if (n == 1) {
            return x;
        }
        double metade = pow(x, n / 2);
        if (n % 2 == 0) {
            return metade * metade;
        } else {
            return x * metade * metade;
        }
    }

    double npow(double x, long long n) {
        n = n * (-1);
        return 1 / pow(x, n);
    }
};