class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        stack<float> stk;

        for (int i = 0; i < cars.size(); i++) {
            float time = (target - cars[i].first) / (float) cars[i].second;

            while (!stk.empty() && time >= stk.top()) {
                stk.pop();
            }
            stk.push(time);
        }
        return stk.size();
    }
};