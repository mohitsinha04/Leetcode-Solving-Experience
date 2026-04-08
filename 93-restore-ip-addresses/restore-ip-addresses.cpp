class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string curr;
        backtrack(res, curr, s, 0, 0);
        return res;
    }

    void backtrack(vector<string>& res, string curr, string& s, int start, int count) {
        if(count == 4 && start == s.size()) {
            curr.pop_back(); // remove last '.'
            res.push_back(curr);
            return;
        }

        if(count == 4 || start == s.size()) return;

        for(int len = 1; len <= 3 && start + len <= s.size(); len++) {
            string part = s.substr(start, len);

            // leading zero case
            if(part.size() > 1 && part[0] == '0') continue;

            int num = stoi(part);
            if(num > 255) continue;

            backtrack(res, curr + part + ".", s, start + len, count + 1);
        }
    }
};