class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> charS(256, -1);
        vector<int> charT(256, -1);

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (charS[s[i]] != charT[t[i]]) return false;
            charS[s[i]] = i;
            charT[t[i]] = i;
        }

        // for (int i = 0; i < s.size(); i++) {
        //     if (charS[s[i] - 'a'] != charT[t[i] - 'a']) return false;
        // }
        return true;
    }
};