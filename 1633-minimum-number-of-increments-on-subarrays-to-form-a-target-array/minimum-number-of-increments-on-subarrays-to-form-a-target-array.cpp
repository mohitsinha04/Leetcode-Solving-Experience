class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int total = target[0];
        int operationWeCanReuse = target[0];

        for (int i = 1; i < target.size(); i++) {
            if (target[i] <= operationWeCanReuse) {
                operationWeCanReuse = target[i];
            } else {
                total += target[i] - operationWeCanReuse;
                operationWeCanReuse = target[i];
            }
        }
        return total;
    }
};
// 1, 2
// 2-1 = 1;

// 1, 2, 3, 2; -> 0, 1, 2, 1 -> 0, 0, 1, 0 -> 

// can = 1, total = 3;

// total += 2 - 1 = 1;
// can = 2;

// total += 3 - 1 = 1;
// can = 3;

// can = 2;