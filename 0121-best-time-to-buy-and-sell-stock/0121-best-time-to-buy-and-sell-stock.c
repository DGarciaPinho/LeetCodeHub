
int maxProfit(int* prices, int pricesSize) {
    int profit;
    int maior, menor;

    menor = prices[0];
    maior = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < menor) {
            menor = prices[i];
        } else {
            profit = prices[i] - menor;
            if (profit > maior) {
                maior = profit;
            }
        }
    }

    return maior;   
}