class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2) return {};

        sort(changed.begin(), changed.end());

        unordered_map<int, int> freq;
        for (int num : changed) {
            freq[num]++;
        }

        vector<int> original;

        for (int num : changed) {
            if (freq[num] == 0) continue;

            if (freq[2 * num] == 0) {
                return {};
            }

            original.push_back(num);
            freq[num]--;
            freq[2 * num]--;
        }

        return original;
    }
};