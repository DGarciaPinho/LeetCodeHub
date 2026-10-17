#include <stdlib.h>

int compara_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(nums[0]), compara_int);

    int best = nums[0] + nums[1] + nums[2];
    int *fim = &nums[numsSize - 1];

    for (int *m = nums; m < fim - 1; ++m) {
        int *left = m + 1;
        int *right = fim;

        while (left < right) {
            int sum = *m + *left + *right;

            if (abs(sum - target) < abs(best - target)) best = sum;
            if (sum == target) return sum;          
            else if (sum < target) ++left;              
            else --right;             
        }
    }
    return best;
}