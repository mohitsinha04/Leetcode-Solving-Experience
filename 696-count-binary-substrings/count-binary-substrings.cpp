class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr_run = 1;
        int prev_run = 0, res = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) curr_run++;
            else {
                prev_run = curr_run;
                curr_run = 1;
            }
            if(prev_run >= curr_run) res++;
        }
        return res;
    }
};