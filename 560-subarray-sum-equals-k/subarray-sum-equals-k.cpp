class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int sum = 0, res = 0;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            //if (sum == target) res++;
            if (map.count(sum - target)) res += map[sum - target];
            map[sum]++;
        }
        return res;
    }
};
/*
[1,2,3]
[1,3,6]
map 
0 - 1;

map = 0;
if (target -  )*/