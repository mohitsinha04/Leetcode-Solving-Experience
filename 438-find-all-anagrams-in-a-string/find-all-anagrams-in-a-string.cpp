class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int winstart = 0;
        int match = 0;
        unordered_map<int, int> map;
        vector<int> res;

        for (int i = 0; i < p.size(); i++) {
            map[p[i]]++;
        }

        for (int winend = 0; winend < s.size(); winend++) {
            if (map.count(s[winend])) {
                map[s[winend]]--;
                if (map[s[winend]] == 0) match++;
            }
            if (match == map.size()) {
                res.push_back(winstart);
            } 
            if (winend >= p.size() - 1) {

                if (map.count(s[winstart])) {
                    if (map[s[winstart]] == 0) match--;
                    map[s[winstart]]++;
                }
                winstart++;
            }
        }
        return res;
    }
};