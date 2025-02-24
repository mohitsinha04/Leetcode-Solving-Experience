class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (matches(s1map, s2map)) return true;
            s2map[s2[i + s1.size()] - 'a']++;
            s2map[s2[i] - 'a']--;
        }
        return matches(s1map, s2map);
    }

    bool matches(vector<int> s1map, vector<int> s2map) {
        for (int i = 0; i < 26; i++) {
            if (s1map[i] != s2map[i]) return false;
        }
        return true;
    }
};