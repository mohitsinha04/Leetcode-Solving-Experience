class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int curr = 0;
        int res = 0;

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

// 1 - 3
// 2 - 4
// 3 - 5
// 4 - 1
// 5 - 2