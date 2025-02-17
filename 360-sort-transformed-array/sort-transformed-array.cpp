class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty()) return {};

        vector<int> results;
        for (int num : nums) {
            int res = a * num * num + b * num + c;
            results.push_back(res);
        }

        int min_val = *min_element(results.begin(), results.end());
        int max_val = *max_element(results.begin(), results.end());

        vector<int> arr(max_val - min_val + 1, 0);

        for (int res : results) {
            arr[res - min_val]++;
        }

        vector<int> sorted;
        for (int i = 0; i < arr.size(); i++) {
            while (arr[i] > 0) {
                sorted.push_back(i + min_val);
                arr[i]--;
            }
        }

        return sorted;
    }
};