class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> map;

        for (auto i : changed) map[i]++;

        vector<int> res;
        int countZero = 0;
        for (int i = 1; i < changed.size(); i++) {
            if (changed[i] % 2 == 0 && map.count(changed[i]/2)) {
                map[changed[i]]--;
                map[changed[i]/2]--;
                if (map[changed[i]] == 0) map.erase(changed[i]);
                if (map[changed[i]/2] == 0) map.erase(changed[i]/2);

                res.push_back(changed[i]/2);
            }
        }
        if ((res.size() == changed.size()/2 || map[0] == changed.size()) && (map[0] % 2 == 0)) {
            return res;
        }
        return {};
    }
};