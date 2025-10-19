class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (auto weight : weights) {
            left = max(left, weight);
            right += weight;
        }
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;

            int currDays = 1, currWeights = 0;
            for (int i = 0; i < weights.size(); i++) {
                if (currWeights + weights[i] > mid) {
                    currDays++;
                    currWeights = weights[i];
                } else 
                    currWeights += weights[i];
            }

            if (currDays > days) {
                left = mid + 1;

            } else {
                right = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};