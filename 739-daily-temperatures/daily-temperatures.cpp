class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<int> stk;

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                res[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return res;
    }
};