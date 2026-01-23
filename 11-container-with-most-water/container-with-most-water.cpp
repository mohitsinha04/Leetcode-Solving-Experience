class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int curr_min = min(height[left], height[right]);
            int curr_container = curr_min * (right - left);

            res = max(res, curr_container);
            if (height[left] > height[right]) {
                right--;
            } else left++;
        }
        return res;
    }
};