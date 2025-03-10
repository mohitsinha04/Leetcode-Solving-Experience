class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minElement = *min_element(arr.begin(), arr.end());
        int maxElement = *max_element(arr.begin(), arr.end());
        int shift = -minElement;
        vector<uint8_t> line(maxElement - minElement + 1);
        vector<vector<int>> res;
        
        // For each integer `num` in `arr`, we increment line[num + shift] by 1.
        for (const int& num : arr) {
            line[num + shift] = 1;
        }

        int minPairDiff = maxElement - minElement;
        int prev = 0;

        for (int i = 1; i <= maxElement + shift; i++) {
            if (line[i] == 0) continue;

            if (i - prev == minPairDiff) {
                res.push_back({prev - shift, i - shift});
            } else if (i - prev < minPairDiff) {
                minPairDiff = i - prev;
                res = {{prev - shift, i - shift}};
            }
            prev = i;
        }
        return res;

    }
};
