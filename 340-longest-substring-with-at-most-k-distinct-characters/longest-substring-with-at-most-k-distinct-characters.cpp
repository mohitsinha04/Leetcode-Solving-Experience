class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int winstart = 0, maxLen = 0;

        for (int winend = 0; winend < s.size(); winend++) {
            map[s[winend]]++;
            while (map.size() > k) {
                map[s[winstart]]--;
                if (map[s[winstart]] == 0) map.erase(s[winstart]);
                winstart++;
            }
            maxLen = max(maxLen, winend - winstart + 1);
        }
        return maxLen;
    }
};