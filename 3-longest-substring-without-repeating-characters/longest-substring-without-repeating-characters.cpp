class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int winstart = 0, maxLength = 0;
        unordered_map<char, int> repeated_chars;
        for (int winend = 0; winend < s.size(); winend++) {
            while (repeated_chars.count(s[winend])) {
                repeated_chars.erase(s[winstart]);
                winstart++;
            }
            maxLength = max(winend - winstart + 1, maxLength);
            repeated_chars[s[winend]] = winend;
        }
        return maxLength;
    }
};