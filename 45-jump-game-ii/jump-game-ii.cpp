class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int currEnd = 0, currFar = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            currFar = max(currFar, i + nums[i]);
            if (i == currEnd) {
                res++;
                currEnd = currFar;
            }
        }
        return res;
    }
};