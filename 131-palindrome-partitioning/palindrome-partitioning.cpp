class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        if (s.size() == 1) return true;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    void backtrack(vector<vector<string>>& res, vector<string>& curr, string& s, int index) {
        if (index == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));
                backtrack(res, curr, s, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(res, curr, s, 0);
        return res;
    }
};