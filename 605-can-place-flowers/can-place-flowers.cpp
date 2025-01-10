class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // for (int i = 1; i < flowerbed.size()-1; i++) {
        //     if (i == 1 && flowerbed[i-1] == 0 && flowerbed[i] ==)
        //     if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0) {
        //         flowerbed[i] = 1;
        //         n--;
        //     }
        // }
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                bool left = (i == 0) || (flowerbed[i-1] == 0);
                bool right = (i == flowerbed.size() - 1 || flowerbed[i+1] == 0);

                if (left && right) {
                    flowerbed[i] = 1;
                    n--;
                    if (n <= 0) return true;
                }
            }
        }
        return n<=0;
    }
};