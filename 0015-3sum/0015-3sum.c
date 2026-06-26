#include <stdlib.h>

int compara(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;

    if (numsSize < 3)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compara);

    int capacidade = 16;

    int **resultado = malloc(capacidade * sizeof(int *));
    *returnColumnSizes = malloc(capacidade * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int soma = nums[i] + nums[left] + nums[right];

            if (soma == 0)
            {
                if (*returnSize == capacidade)
                {
                    capacidade *= 2;
                    resultado = realloc(resultado, capacidade * sizeof(int *));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacidade * sizeof(int));
                }

                resultado[*returnSize] = malloc(3 * sizeof(int));

                resultado[*returnSize][0] = nums[i];
                resultado[*returnSize][1] = nums[left];
                resultado[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;

                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;

                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (soma < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return resultado;
}