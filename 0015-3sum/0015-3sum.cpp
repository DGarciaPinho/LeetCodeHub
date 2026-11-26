#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int* inicio = nums.data();
        int* fim = inicio + nums.size();   // uma posiÃ§Ã£o depois do Ãºltimo

        for(int* p1 = inicio; p1 < fim - 2; ++p1){
            if(*p1 > 0) break;
            if(p1 > inicio && *p1 == *(p1-1)) continue;  // pula repetido

            int* p2 = p1 + 1;
            int* p3 = fim - 1;

            while(p2 < p3){
                int soma = *p1 + *p2 + *p3;

                if(soma < 0){
                    ++p2;
                }else if(soma > 0){
                    --p3;
                }else{
                    res.push_back({*p1, *p2, *p3});
                    ++p2;
                    --p3;
                    while(p2 < p3 && *p2 == *(p2-1)) ++p2;  // pula repetidos
                }
            }
        }
        return res;
    }
};