class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            res += countPalindromesAroundCenter(s, i, i);
            res += countPalindromesAroundCenter(s, i, i + 1);
        }
        return res;
    }
    
    int countPalindromesAroundCenter(string s, int i, int j) {
        int res = 0;
        while (i >= 0 && j < s.size()) {
            if (s[i] != s[j]) break;
            i--;
            j++;

            res++;
        }
        return res;
    }

};