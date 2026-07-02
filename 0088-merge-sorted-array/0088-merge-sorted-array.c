void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    for(int i = 0; i < n; ++i)
    {
        nums1[m + i] = nums2[i];   
    }

    for(int i = 0; i < m + n; ++i)
    {
        for(int j = 0; j < m + n; ++j)
        {
            if(nums1[i] < nums1[j])
            {
                swap(&nums1[i], &nums1[j]);
            }
        }
    }
}