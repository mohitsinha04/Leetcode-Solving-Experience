class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) return 0;
        int curr = 0, last = 0, res = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                curr = (curr * 10) + (s[i] - '0');
            }
            if (!isdigit(s[i]) && !iswspace(s[i]) || i == s.size() - 1) {
                if (sign == '+' || sign == '-') {
                    res += last;
                    last = (sign == '+') ? curr : -curr;
                } else if (sign == '*') {
                    last = last * curr;
                } else if (sign == '/') {
                    last = last / curr;
                }
                sign = s[i];
                curr = 0;
            }
        }
        res += last;
        return res;
    }
};