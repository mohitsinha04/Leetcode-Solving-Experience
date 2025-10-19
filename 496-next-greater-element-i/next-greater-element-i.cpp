class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> nextGreaterNums2;

        for (int i = 0; i < nums2.size(); i++) {
            while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
                nextGreaterNums2[nums2[stk.top()]] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            nextGreaterNums2[nums2[stk.top()]] = -1;
            stk.pop();
        }

        vector<int> res;
        for (int nums : nums1) {
            res.push_back(nextGreaterNums2[nums]);
        }
        return res;
    }
};