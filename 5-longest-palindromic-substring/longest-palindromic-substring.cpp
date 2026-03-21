class Solution {
public:

    string expand (int left, int right, string s) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            string odd = expand(i, i, s);
            if (odd.size() > res.size()) {
                res = odd;
            }

            string even = expand(i, i+1, s);
            if (even.size() > res.size()) {
                res = even;
            }
        }
        return res;
    }
};