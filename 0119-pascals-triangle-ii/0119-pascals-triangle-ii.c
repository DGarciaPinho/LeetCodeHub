int* getRow(int rowIndex, int* returnSize) {
    int n = rowIndex + 1;
    int* row = (int*)calloc(n, sizeof(int));
    row[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 1; j--) {
            row[j] += row[j - 1];
        }
    }
    *returnSize = n;
    return row;

}