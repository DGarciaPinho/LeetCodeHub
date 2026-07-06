int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 1;

    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[j - 1]) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}