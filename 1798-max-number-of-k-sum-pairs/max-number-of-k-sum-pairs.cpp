class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i : nums) {
            map[i]++;
        }
        int res = 0;
        for (int i : nums) {
            if (map.count(k - i)) {
                if (k - i == i) {
                    if (map[i] >= 2) {
                        res++;
                        map[i] -= 2;
                    }
                } else {
                    if (map[i] > 0 && map[k - i] > 0) {
                        res++;
                        map[i]--;
                        map[k - i]--;
                    }
                }
            }
        }
        return res;
    }
};