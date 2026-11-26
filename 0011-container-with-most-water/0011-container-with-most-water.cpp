class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maior = calculo(i, j, height[i], height[j]);

        while(i < j){
            if(height[i] < height[j]){
                ++i;
            }else{
                --j;
            }
            if(maior < calculo(i, j, height[i], height[j])){
                maior = calculo(i, j, height[i], height[j]);
            }
        }
        return maior;
    }

    int calculo(int i, int j, int x1, int x2){
        int height, res=0;
        if(x1 > x2){
            height = x2;
        }else{
            height = x1;
        }
        res = (j-i) * (height);
        return res;
    }
};