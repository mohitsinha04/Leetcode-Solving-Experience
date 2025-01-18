class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || s.size() < t.size()) return "";

        unordered_map<char, int> map;

        for (char c : t) {
            map[c]++;
        }

        int winstart = 0;
        int minLength = INT_MAX;
        int minLeft = 0;
        int count = 0;

        for (int winend = 0; winend < s.size(); winend++) {
            if (map.count(s[winend]) && map[s[winend]] > 0) count++;

            map[s[winend]]--;

            if (count == t.size()) {
                while (winstart < winend && map[s[winstart]] < 0) {
                    map[s[winstart]]++;
                    winstart++;
                } 
                if (minLength > winend - winstart) {
                    minLength = winend - winstart + 1;
                    minLeft = winstart;
                }
                map[s[winstart]]++;
                winstart++;
                count--;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
    }
};