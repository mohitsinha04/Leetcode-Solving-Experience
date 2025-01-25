class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxi = 0;
        int maxj = height.size() - 1;

        int maxWater = 0;

        while (i < j) {
            int currWater = min(height[i], height[j]) * (j - i);
            maxWater = max(maxWater, currWater);

            if (height[i] < height[j]) i++;
            else j--;
        }
        return maxWater;
    }
};