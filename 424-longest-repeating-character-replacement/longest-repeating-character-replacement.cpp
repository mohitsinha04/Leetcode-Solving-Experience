class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mapFreq;
        int winstart = 0;
        int res = 0;
        int maxFreq = 0;

        for (int winend = 0; winend < s.size(); winend++) {
            mapFreq[s[winend]]++;

            maxFreq = max(maxFreq, mapFreq[s[winend]]);

            if (winend - winstart + 1 - maxFreq > k) {
                mapFreq[s[winstart]]--;
                winstart++;
            }
            res = max(res, winend - winstart + 1);
        }
        return res;
    }
};