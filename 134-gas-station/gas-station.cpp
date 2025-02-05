class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int total = 0;
        int curr = 0;

        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];

            if (curr < 0) {
                res = i + 1;
                curr = 0;
            }
        }
        return total >= 0 ? res : -1;
    }
};